#pragma once

#include "MDPWSConstants.hpp"
#include "MessageModel.hpp"
#include "NamespaceMap.hpp"
#include "SDCConstants.hpp"
#include <sstream>
#include <string>

class MessageSerializer
{
public:
  /**
   * @brief Construct a new MessageSerializer
   */
  MessageSerializer();
  /**
   * @brief get the serialized string
   */
  std::string str() const;

  void serialize(const MESSAGEMODEL::Envelope& message);
  void serialize(rapidxml::xml_node<>* parent, const MESSAGEMODEL::Envelope& message);
  void serialize(rapidxml::xml_node<>* parent, const MESSAGEMODEL::Header& header);
  void serialize(rapidxml::xml_node<>* parent, const MESSAGEMODEL::Body& body);
  void serialize(rapidxml::xml_node<>* parent, const WS::ADDRESSING::RelatesToType& relatesTo);
  void serialize(rapidxml::xml_node<>* parent,
                 const WS::ADDRESSING::EndpointReferenceType& endpointReference);
  void serialize(rapidxml::xml_node<>* parent, const WS::DISCOVERY::AppSequenceType& appSequence);
  void serialize(rapidxml::xml_node<>* parent, const WS::DISCOVERY::HelloType& hello);
  void serialize(rapidxml::xml_node<>* parent, const WS::DISCOVERY::ProbeMatchType& probeMatch);
  void serialize(rapidxml::xml_node<>* parent, const WS::DISCOVERY::ProbeMatchesType& probeMatches);
  void serialize(rapidxml::xml_node<>* parent, const WS::DISCOVERY::ResolveMatchType& resolveMatch);
  void serialize(rapidxml::xml_node<>* parent,
                 const WS::DISCOVERY::ResolveMatchesType& resolveMatches);
  void serialize(rapidxml::xml_node<>* parent, const WS::MEX::Metadata& metadata);
  void serialize(rapidxml::xml_node<>* parent, const WS::MEX::MetadataSection& metadataSection);
  void serialize(rapidxml::xml_node<>* parent, const WS::DISCOVERY::ScopesType& scopes);
  void serialize(rapidxml::xml_node<>* parent, const WS::DPWS::ThisModelType& thisModel);
  void serialize(rapidxml::xml_node<>* parent, const WS::DPWS::ThisDeviceType& thisDevice);
  void serialize(rapidxml::xml_node<>* parent, const WS::DPWS::Relationship& relationship);
  void serialize(rapidxml::xml_node<>* parent, const WS::DPWS::HostServiceType& host);
  void serialize(rapidxml::xml_node<>* parent, const WS::DPWS::HostedServiceType& hosted);
  void serialize(rapidxml::xml_node<>* parent, const BICEPS::MM::GetMdibResponse& getMdibResponse);
  void serialize(rapidxml::xml_node<>* parent, const BICEPS::PM::Mdib& mdib);
  void serialize(rapidxml::xml_node<>* parent, const BICEPS::PM::MdDescription& mdDescription);
  void serialize(rapidxml::xml_node<>* parent, const BICEPS::PM::MdsDescriptor& mdsDescriptor);
  void serialize(rapidxml::xml_node<>* parent, const BICEPS::PM::Metadata& metadata);
  void serialize(rapidxml::xml_node<>* parent,
                 const BICEPS::PM::SystemContextDescriptor& systemContext);
  void serialize(rapidxml::xml_node<>* parent,
                 const BICEPS::PM::PatientContextDescriptor& patientContext);
  void serialize(rapidxml::xml_node<>* parent, const BICEPS::PM::VmdDescriptor& vmd);
  void serialize(rapidxml::xml_node<>* parent, const BICEPS::PM::ChannelDescriptor& channel);
  void serialize(rapidxml::xml_node<>* parent,
                 const BICEPS::PM::AbstractMetricDescriptor& abstractMetric);
  void serialize(rapidxml::xml_node<>* parent, const BICEPS::PM::MdState& mdState);

  static std::string toString(BICEPS::PM::SafetyClassification);
  static std::string toString(const WS::DISCOVERY::UriListType& uriList);
  static std::string toString(const WS::DISCOVERY::QNameListType& qNameList);

private:
  std::unique_ptr<rapidxml::xml_document<>> xmlDocument_;
};
