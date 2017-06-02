// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#pragma once

#include <RobotDrive.h>
#include <SampleRobot.h>
#include <XboxController.h>

#include "Constants.hpp"

class SunBot : public frc::SampleRobot {
public:
    void OperatorControl() override;

private:
    frc::RobotDrive robotDrive{k_leftDrive, k_rightDrive};
    frc::XboxController controller{k_controller};
};
