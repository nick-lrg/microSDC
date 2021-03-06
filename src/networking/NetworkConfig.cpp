#include "NetworkConfig.hpp"

NetworkConfig::NetworkConfig(bool useTLS, std::string ipAddress)
  : useTLS_(useTLS)
  , ipAddress_(std::move(ipAddress))
{
}

bool NetworkConfig::useTLS() const
{
  return useTLS_;
}

const std::string& NetworkConfig::ipAddress() const
{
  return ipAddress_;
}
