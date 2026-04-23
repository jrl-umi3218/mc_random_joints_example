#include "RandomJointsExample.h"

RandomJointsExample::RandomJointsExample(mc_rbdyn::RobotModulePtr rm, double dt,
                                         const mc_rtc::Configuration& config)
    : mc_control::fsm::Controller(rm, dt, config) {
  mc_rtc::log::success("RandomJointsExample init done ");
  datastore().make<bool>("RandomJointsExample::DisableQP", false);
}

bool RandomJointsExample::run() {
  // Allow to add a condition to disable the QP from any state
  if (datastore().get<bool>("RandomJointsExample::DisableQP")) {
    mc_rtc::log::info("RandomJointsExample: run without QP");
    return mc_control::fsm::Controller::run(mc_solver::FeedbackType::SkipQP);
  } else {
    mc_rtc::log::info("RandomJointsExample: run openloop QP");
    return mc_control::fsm::Controller::run(mc_solver::FeedbackType::None);
  }
}

void RandomJointsExample::reset(
    const mc_control::ControllerResetData& reset_data) {
  mc_control::fsm::Controller::reset(reset_data);
}
