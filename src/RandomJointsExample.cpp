#include "RandomJointsExample.h"

RandomJointsExample::RandomJointsExample(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config)
: mc_control::fsm::Controller(rm, dt, config)
{

  mc_rtc::log::success("RandomJointsExample init done ");
}

bool RandomJointsExample::run()
{
  return mc_control::fsm::Controller::run();
}

void RandomJointsExample::reset(const mc_control::ControllerResetData & reset_data)
{
  mc_control::fsm::Controller::reset(reset_data);
}


