#include "RandomJointsExample_Initial.h"

#include "../RandomJointsExample.h"

void RandomJointsExample_Initial::configure(
    const mc_rtc::Configuration& config) {}

void RandomJointsExample_Initial::start(mc_control::fsm::Controller& ctl) {
  ctl.datastore().get<bool>("RandomJointsExample::DisableQP") = true;
}

bool RandomJointsExample_Initial::run(mc_control::fsm::Controller& ctl) {
  if (iter_ == 0) {
    auto& robot = ctl.robot();
    const auto& rjo = robot.refJointOrder();
    randomJoints_ = Eigen::VectorXd(rjo.size()).setRandom();

    for (size_t i = 0; i < randomJoints_.size(); ++i) {
      auto jointIndexInMbc = robot.jointIndexInMBC(i);
      robot.mbc().q[jointIndexInMbc][0] = randomJoints_[i];
    }
  }

  // pause for N iterations
  if (++iter_ % pauseIter_ == 0) {
    output("OK");
    return true;
  } else {
    return false;
  }
}

void RandomJointsExample_Initial::teardown(mc_control::fsm::Controller& ctl_) {}

EXPORT_SINGLE_STATE("RandomJointsExample_Initial", RandomJointsExample_Initial)
