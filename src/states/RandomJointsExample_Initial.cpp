#include "RandomJointsExample_Initial.h"

#include "../RandomJointsExample.h"

void RandomJointsExample_Initial::configure(const mc_rtc::Configuration & config)
{
}

void RandomJointsExample_Initial::start(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<RandomJointsExample &>(ctl_);
}

bool RandomJointsExample_Initial::run(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<RandomJointsExample &>(ctl_);
  output("OK");
  return true;
}

void RandomJointsExample_Initial::teardown(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<RandomJointsExample &>(ctl_);
}

EXPORT_SINGLE_STATE("RandomJointsExample_Initial", RandomJointsExample_Initial)
