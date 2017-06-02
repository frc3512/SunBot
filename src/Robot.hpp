// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#pragma once

#include <Joystick.h>
#include <RobotDrive.h>
#include <SampleRobot.h>

#include "Constants.hpp"

class Robot : public frc::SampleRobot {
public:
    void OperatorControl() override;

private:
    frc::Joystick driveStick{k_driveStick};
    frc::Joystick turnStick{k_turnStick};
    frc::RobotDrive drive{k_leftDrive, k_rightDrive};
};
