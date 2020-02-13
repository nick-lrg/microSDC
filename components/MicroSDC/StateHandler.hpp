#pragma once

#include "MicroSDC.hpp"
#include "datamodel/BICEPS_ParticipantModel.hpp"
#include "esp_log.h"

/**
 * @brief Abstract class to handle states of this device. Exposes updateState() to update this state
 * in the microSDC mdib.
 */
class StateHandler
{
public:
  /**
   * @brief Constructs a new StateHandler referring to a descriptor
   * @param descriptorHandle the handle of the associated descriptor
   */
  explicit StateHandler(std::string descriptorHandle);
  /**
   * @brief gets the handle of the associated descriptor
   * @return the descriptor's handle of this state
   */
  const std::string& getDescriptorHandle() const;
  /**
   * @brief returns the metric type of this state. This is used to fake RTTI for dynamic
   * subclassing.
   * @return The metric type of this state
   */
  virtual BICEPS::PM::MetricType getMetricType() const = 0;
  /**
   * @brief sets the MicroSDC instantation, which handles this state
   * @param MicroSDC the pointer MicroSDC object
   */
  void setMicroSDC(MicroSDC* microSDC);
  /**
   * @brief updates this state in the mdib of the holding MicroSDC object
   * @tparam State infered state type of this state
   * @param state the new state to update
   */
  template <class State>
  void updateState(std::shared_ptr<State> state)
  {
    if (microSDC_ == nullptr)
    {
      ESP_LOGE("StateHandler", "Cannot update state of unassigned state! Use addMdState!");
      return;
    }
    microSDC_->updateState(state);
  }

private:
  /// pointer to the holding MicroSDC object
  MicroSDC* microSDC_{nullptr};
  /// handle of the associated descriptor
  std::string descriptorHandle_;
};

/**
 * @brief Implements a StateHandler of an arbitrary MdState
 * @tparam MdState the state type of this metric state
 */
template <class MdState>
class MdStateHandler : public StateHandler
{
public:
  /**
   * @brief constructs a new MdStateHandler referring to a descriptor
   * @param descriptorHandle the handle of the associated descriptor
   */
  explicit MdStateHandler(const std::string& descriptorHandle)
    : StateHandler(descriptorHandle)
  {
  }
  /**
   * @brief gets the initial state object of this metric
   * @return pointer to the MdState constructed
   */
  virtual std::shared_ptr<MdState> getInitialState() const = 0;
};