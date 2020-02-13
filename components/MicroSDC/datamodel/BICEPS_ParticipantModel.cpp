#include "BICEPS_ParticipantModel.hpp"

namespace BICEPS::PM
{

  // Range
  //
  const Range::LowerOptional& Range::Lower() const
  {
    return Lower_;
  }
  Range::LowerOptional& Range::Lower()
  {
    return Lower_;
  }
  const Range::UpperOptional& Range::Upper() const
  {
    return Upper_;
  }
  Range::UpperOptional& Range::Upper()
  {
    return Upper_;
  }
  const Range::StepWidthOptional& Range::StepWidth() const
  {
    return StepWidth_;
  }
  Range::StepWidthOptional& Range::StepWidth()
  {
    return StepWidth_;
  }
  const Range::RelativeAccuracyOptional& Range::RelativeAccuracy() const
  {
    return RelativeAccuracy_;
  }
  Range::RelativeAccuracyOptional& Range::RelativeAccuracy()
  {
    return RelativeAccuracy_;
  }
  const Range::AbsoluteAccuracyOptional& Range::AbsoluteAccuracy() const
  {
    return AbsoluteAccuracy_;
  }
  Range::AbsoluteAccuracyOptional& Range::AbsoluteAccuracy()
  {
    return AbsoluteAccuracy_;
  }

  // CodedValue
  //
  CodedValue::CodedValue(const CodeType& code)
    : Code_(code)
  {
  }
  const CodedValue::CodeType& CodedValue::Code() const
  {
    return Code_;
  }
  CodedValue::CodeType& CodedValue::Code()
  {
    return Code_;
  }

  // Metadata
  //
  const Metadata::ManufacturerSequence& Metadata::Manufacturer() const
  {
    return Manufacturer_;
  }
  Metadata::ManufacturerSequence& Metadata::Manufacturer()
  {
    return Manufacturer_;
  }
  const Metadata::ModelNameSequence& Metadata::ModelName() const
  {
    return ModelName_;
  }
  Metadata::ModelNameSequence& Metadata::ModelName()
  {
    return ModelName_;
  }
  const Metadata::ModelNumberOptional& Metadata::ModelNumber() const
  {
    return ModelNumber_;
  }
  Metadata::ModelNumberOptional& Metadata::ModelNumber()
  {
    return ModelNumber_;
  }
  const Metadata::SerialNumberSequence& Metadata::SerialNumber() const
  {
    return SerialNumber_;
  }
  Metadata::SerialNumberSequence& Metadata::SerialNumber()
  {
    return SerialNumber_;
  }

  // AbstractDescriptor
  //
  AbstractDescriptor::AbstractDescriptor(const HandleType& handle)
    : Handle_(handle)
  {
  }
  const AbstractDescriptor::TypeOptional& AbstractDescriptor::Type() const
  {
    return Type_;
  }
  AbstractDescriptor::TypeOptional& AbstractDescriptor::Type()
  {
    return Type_;
  }
  const AbstractDescriptor::HandleType& AbstractDescriptor::Handle() const
  {
    return Handle_;
  }
  AbstractDescriptor::HandleType& AbstractDescriptor::Handle()
  {
    return Handle_;
  }
  const AbstractDescriptor::DescriptorVersionOptional& AbstractDescriptor::DescriptorVersion() const
  {
    return DescriptorVersion_;
  }
  AbstractDescriptor::DescriptorVersionOptional& AbstractDescriptor::DescriptorVersion()
  {
    return DescriptorVersion_;
  }
  const AbstractDescriptor::SafetyClassificationOptional&
  AbstractDescriptor::SafetyClassification() const
  {
    return SafetyClassification_;
  }
  AbstractDescriptor::SafetyClassificationOptional& AbstractDescriptor::SafetyClassification()
  {
    return SafetyClassification_;
  }

  // AbstractContextDescriptor
  //
  AbstractContextDescriptor::AbstractContextDescriptor(const HandleType& handle)
    : AbstractDescriptor(handle)
  {
  }

  // PatientContext
  //
  PatientContextDescriptor::PatientContextDescriptor(const HandleType& handle)
    : AbstractContextDescriptor(handle)
  {
  }

  // SystemContext
  //
  SystemContextDescriptor::SystemContextDescriptor(const HandleType& handle)
    : AbstractContextDescriptor(handle)
  {
  }
  const SystemContextDescriptor::PatientContextOptional&
  SystemContextDescriptor::PatientContext() const
  {
    return PatientContext_;
  }
  SystemContextDescriptor::PatientContextOptional& SystemContextDescriptor::PatientContext()
  {
    return PatientContext_;
  }

  // AbstractDeviceComponentDescriptor
  //
  AbstractDeviceComponentDescriptor::AbstractDeviceComponentDescriptor(const HandleType& handle)
    : AbstractDescriptor(handle)
  {
  }

  // AbstractMetricDescriptor
  //
  AbstractMetricDescriptor::AbstractMetricDescriptor(
      const HandleType& handle, const UnitType& unit, const MetricCategoryType& metricCategory,
      const MetricAvailabilityType& metricAvailability)
    : AbstractDescriptor(handle)
    , Unit_(unit)
    , MetricCategory_(metricCategory)
    , MetricAvailability_(metricAvailability)
  {
  }
  const AbstractMetricDescriptor::UnitType& AbstractMetricDescriptor::Unit() const
  {
    return Unit_;
  }
  AbstractMetricDescriptor::UnitType& AbstractMetricDescriptor::Unit()
  {
    return Unit_;
  }
  const AbstractMetricDescriptor::MetricCategoryType&
  AbstractMetricDescriptor::MetricCategory() const
  {
    return MetricCategory_;
  }
  AbstractMetricDescriptor::MetricCategoryType& AbstractMetricDescriptor::MetricCategory()
  {
    return MetricCategory_;
  }
  const AbstractMetricDescriptor::MetricAvailabilityType&
  AbstractMetricDescriptor::MetricAvailability() const
  {
    return MetricAvailability_;
  }
  AbstractMetricDescriptor::MetricAvailabilityType& AbstractMetricDescriptor::MetricAvailability()
  {
    return MetricAvailability_;
  }


  // NumericMetricDescriptor
  //
  NumericMetricDescriptor::NumericMetricDescriptor(const HandleType& handle, const UnitType& unit,
                                                   const MetricCategoryType& metricCategory,
                                                   const MetricAvailabilityType& metricAvailability,
                                                   const ResolutionType& resolution)
    : AbstractMetricDescriptor(handle, unit, metricCategory, metricAvailability)
    , Resolution_(resolution)
  {
  }

  MetricType NumericMetricDescriptor::getMetricType() const
  {
    return MetricType::NUMERIC;
  }

  const NumericMetricDescriptor::TechnicalRangeSequence&
  NumericMetricDescriptor::TechnicalRange() const
  {
    return TechnicalRange_;
  }
  NumericMetricDescriptor::TechnicalRangeSequence& NumericMetricDescriptor::TechnicalRange()
  {
    return TechnicalRange_;
  }
  const NumericMetricDescriptor::ResolutionType& NumericMetricDescriptor::Resolution() const
  {
    return Resolution_;
  }
  NumericMetricDescriptor::ResolutionType& NumericMetricDescriptor::Resolution()
  {
    return Resolution_;
  }
  const NumericMetricDescriptor::AveragingPeriodOptional&
  NumericMetricDescriptor::AveragingPeriod() const
  {
    return AveragingPeriod_;
  }
  NumericMetricDescriptor::AveragingPeriodOptional& NumericMetricDescriptor::AveragingPeriod()
  {
    return AveragingPeriod_;
  }

  // ChannelDescriptor
  //
  ChannelDescriptor::ChannelDescriptor(const HandleType& handle)
    : AbstractDeviceComponentDescriptor(handle)
  {
  }
  const ChannelDescriptor::MetricSequence& ChannelDescriptor::Metric() const
  {
    return Metric_;
  }
  ChannelDescriptor::MetricSequence& ChannelDescriptor::Metric()
  {
    return Metric_;
  }

  // AbstractComplexDeviceComponentDescriptor
  //
  AbstractComplexDeviceComponentDescriptor::AbstractComplexDeviceComponentDescriptor(
      const HandleType& handle)
    : AbstractDeviceComponentDescriptor(handle)
  {
  }

  // VmdDescriptor
  //
  VmdDescriptor::VmdDescriptor(const HandleType& handle)
    : AbstractComplexDeviceComponentDescriptor(handle)
  {
  }
  const VmdDescriptor::ChannelSequence& VmdDescriptor::Channel() const
  {
    return Channel_;
  }
  VmdDescriptor::ChannelSequence& VmdDescriptor::Channel()
  {
    return Channel_;
  }

  // MdsDescriptor
  //
  MdsDescriptor::MdsDescriptor(const HandleType& handle)
    : AbstractComplexDeviceComponentDescriptor(handle)
  {
  }
  const MdsDescriptor::VmdSequence& MdsDescriptor::Vmd() const
  {
    return Vmd_;
  }
  MdsDescriptor::VmdSequence& MdsDescriptor::Vmd()
  {
    return Vmd_;
  }
  const MdsDescriptor::SystemContextOptional& MdsDescriptor::SystemContext() const
  {
    return SystemContext_;
  }
  MdsDescriptor::SystemContextOptional& MdsDescriptor::SystemContext()
  {
    return SystemContext_;
  }
  const MdsDescriptor::MetaDataOptional& MdsDescriptor::MetaData() const
  {
    return MetaData_;
  }
  MdsDescriptor::MetaDataOptional& MdsDescriptor::MetaData()
  {
    return MetaData_;
  }

  // MdDescription
  //
  const MdDescription::MdsSequence& MdDescription::Mds() const
  {
    return Mds_;
  }
  MdDescription::MdsSequence& MdDescription::Mds()
  {
    return Mds_;
  }

  // MetricQuality
  //
  const MetricQuality::ValidityType& MetricQuality::Validity() const
  {
    return Validity_;
  }
  MetricQuality::ValidityType& MetricQuality::Validity()
  {
    return Validity_;
  }

  // AbstractMetricValue
  //
  const AbstractMetricValue::MetricQualityType& AbstractMetricValue::Quality() const
  {
    return MetricQuality_;
  }
  AbstractMetricValue::MetricQualityType& AbstractMetricValue::Quality()
  {
    return MetricQuality_;
  }

  // NumericMetricValue
  //
  const NumericMetricValue::ValueOptional& NumericMetricValue::Value() const
  {
    return Value_;
  }
  NumericMetricValue::ValueOptional& NumericMetricValue::Value()
  {
    return Value_;
  }
  MetricType NumericMetricValue::getMetricType() const
  {
    return MetricType::NUMERIC;
  }

  // AbstractState
  //
  AbstractState::AbstractState(DescriptorHandleType handle)
    : DescriptorHandle_(std::move(handle))
  {
  }
  const AbstractState::DescriptorHandleType& AbstractState::DescriptorHandle() const
  {
    return DescriptorHandle_;
  }
  AbstractState::DescriptorHandleType& AbstractState::DescriptorHandle()
  {
    return DescriptorHandle_;
  }

  // AbstractMetricState
  //
  AbstractMetricState::AbstractMetricState(DescriptorHandleType handle)
    : AbstractState(std::move(handle))
  {
  }

  // NumericMetricState
  //
  NumericMetricState::NumericMetricState(DescriptorHandleType handle)
    : AbstractMetricState(std::move(handle))
  {
  }
  StateType NumericMetricState::getStateType() const
  {
    return StateType::NUMERIC_METRIC_STATE;
  }
  const NumericMetricState::MetricValueOptional& NumericMetricState::MetricValue() const
  {
    return MetricValue_;
  }
  NumericMetricState::MetricValueOptional& NumericMetricState::MetricValue()
  {
    return MetricValue_;
  }

  // MdState
  //
  const MdState::StateSequence& MdState::State() const
  {
    return State_;
  }
  MdState::StateSequence& MdState::State()
  {
    return State_;
  }

  // Mdib
  //
  Mdib::Mdib(const SequenceIdType& sequenceIdType)
    : SequenceId_(sequenceIdType)
  {
  }
  const Mdib::MdDescriptionOptional& Mdib::MdDescription() const
  {
    return MdDescription_;
  }
  Mdib::MdDescriptionOptional& Mdib::MdDescription()
  {
    return MdDescription_;
  }
  const Mdib::MdStateOptional& Mdib::MdState() const
  {
    return MdState_;
  }
  Mdib::MdStateOptional& Mdib::MdState()
  {
    return MdState_;
  }
  const Mdib::MdibVersionOptional& Mdib::MdibVersion() const
  {
    return MdibVersion_;
  }
  Mdib::MdibVersionOptional& Mdib::MdibVersion()
  {
    return MdibVersion_;
  }
  const Mdib::SequenceIdType& Mdib::SequenceId() const
  {
    return SequenceId_;
  }
  Mdib::SequenceIdType& Mdib::SequenceId()
  {
    return SequenceId_;
  }
  const Mdib::InstanceIdOptional& Mdib::InstanceId() const
  {
    return InstanceId_;
  }
  Mdib::InstanceIdOptional& Mdib::InstanceId()
  {
    return InstanceId_;
  }
} // namespace BICEPS::PM