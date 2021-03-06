#include "WebServer.esp32.hpp"
#include "Log.hpp"
#include "Request.esp32.hpp"
#include "networking/NetworkConfig.hpp"
#include "rapidxml/rapidxml.hpp"
#include "services/ServiceInterface.hpp"
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

std::unique_ptr<WebServerInterface> WebServerFactory::produce(const NetworkConfig& networkConfig)
{
  return std::make_unique<WebServerEsp32>(networkConfig.useTLS());
}

WebServerEsp32::WebServerEsp32(bool useTLS)
{
  extern const unsigned char cacert_pem_start[] asm("_binary_cacert_pem_start");
  extern const unsigned char cacert_pem_end[] asm("_binary_cacert_pem_end");
  config_.client_verify_cert_pem = cacert_pem_start;
  config_.client_verify_cert_len = cacert_pem_end - cacert_pem_start;

  extern const unsigned char serverCert_pem_start[] asm("_binary_serverCert_pem_start");
  extern const unsigned char serverCert_pem_end[] asm("_binary_serverCert_pem_end");
  config_.cacert_pem = serverCert_pem_start;
  config_.cacert_len = serverCert_pem_end - serverCert_pem_start;
  extern const unsigned char serverKey_pem_start[] asm("_binary_serverKey_pem_start");
  extern const unsigned char serverKey_pem_end[] asm("_binary_serverKey_pem_end");
  config_.prvtkey_pem = serverKey_pem_start;
  config_.prvtkey_len = serverKey_pem_end - serverKey_pem_start;

  config_.transport_mode = useTLS ? HTTPD_SSL_TRANSPORT_SECURE : HTTPD_SSL_TRANSPORT_INSECURE;
  // use the URI wildcard matching function
  config_.httpd.uri_match_fn = httpd_uri_match_wildcard;
  config_.httpd.max_open_sockets = useTLS ? 2 : 7;
  config_.httpd.lru_purge_enable = true;
}

void WebServerEsp32::start()
{
  // start the server
  LOG(LogLevel::INFO,
      "Starting WebServer server on port: " << (config_.transport_mode == HTTPD_SSL_TRANSPORT_SECURE
                                                    ? config_.port_secure
                                                    : config_.port_insecure));
  esp_err_t ret = httpd_ssl_start(&server_, &config_);

  if (ret != ESP_OK)
  {
    LOG(LogLevel::ERROR, "Error starting server!");
    throw std::runtime_error("Cannot start WebServer!");
    return;
  }
  registerUriHandlers();
}

void WebServerEsp32::stop()
{
  LOG(LogLevel::INFO, "Stopping WebServer...");
  httpd_stop(server_);
}

void WebServerEsp32::addService(std::shared_ptr<ServiceInterface> service)
{
  services_.emplace_back(service);
}

esp_err_t WebServerEsp32::handlerCallback(httpd_req_t* req)
{
  std::vector<char> buffer;
  buffer.resize(req->content_len + 1);
  size_t received = httpd_req_recv(req, buffer.data(), req->content_len);
  if (received != req->content_len)
  {
    LOG(LogLevel::ERROR, "Could not receive all bytes!");
    return ESP_FAIL;
  }
  // null-terminate the buffer
  buffer.emplace_back('\0');
  LOG(LogLevel::DEBUG, "Received " << std::to_string(received) << " of "
                                   << std::to_string(req->content_len) << " bytes: \n"
                                   << buffer.data());
  auto webServer = reinterpret_cast<WebServerEsp32*>(req->user_ctx);
  LOG(LogLevel::INFO, "Dispatch URI: " << req->uri);
  auto service = std::find_if(
      webServer->services_.begin(), webServer->services_.end(),
      [&](const auto& service) { return strcmp(service->getURI().c_str(), req->uri) == 0; });
  if (service == webServer->services_.end())
  {
    // send 404 and close socket
    httpd_resp_send_err(req, HTTPD_404_NOT_FOUND, "404 Service not found");
    return ESP_FAIL;
  }

  try
  {
    (*service)->handleRequest(std::make_unique<RequestEsp32>(req, buffer.data()));
  }
  catch (rapidxml::parse_error& e)
  {
    LOG(LogLevel::ERROR, "Rapidxml Parse error: " << e.what());
    return ESP_FAIL;
  }
  catch (std::exception& e)
  {
    LOG(LogLevel::ERROR, "Error handling Request: std::exception: " << e.what());
    return ESP_FAIL;
  }
  catch (...)
  {
    LOG(LogLevel::ERROR, "Error while handling request!");
    // httpd_resp_send_err(req, HTTPD_500_INTERNAL_SERVER_ERROR, "500 Internal Server Error");
    return ESP_FAIL;
  }
  return ESP_OK;
}

void WebServerEsp32::registerUriHandlers()
{
  LOG(LogLevel::INFO, "Registering URI handlers...");
  const httpd_uri_t get = {
      "*",             // uri
      HTTP_GET,        // method
      handlerCallback, // handler
      this             // user_ctx
  };
  const httpd_uri_t post = {
      "*",             // uri
      HTTP_POST,       // method
      handlerCallback, // handler
      this             // user_ctx
  };
  httpd_register_uri_handler(server_, &get);
  httpd_register_uri_handler(server_, &post);
}
