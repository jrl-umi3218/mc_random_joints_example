#pragma once

#include <mc_control/fsm/Controller.h>
#include <mc_control/mc_controller.h>

#include "api.h"

struct RandomJointsExample_DLLAPI RandomJointsExample
    : public mc_control::fsm::Controller {
  RandomJointsExample(mc_rbdyn::RobotModulePtr rm, double dt,
                      const mc_rtc::Configuration& config);

  bool run() override;
  bool runOptional(bool withQP = true);

  void reset(const mc_control::ControllerResetData& reset_data) override;
};
