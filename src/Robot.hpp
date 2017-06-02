// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#pragma once

#include <thread>

#include <Joystick.h>
#include <RobotDrive.h>
#include <SampleRobot.h>

#include "Constants.hpp"

class Robot : public frc::SampleRobot {
public:
    void OperatorControl() override;

private:
    frc::Joystick driveStick1{0};
    frc::Joystick driveStick2{1};
    frc::RobotDrive drive{k_leftDrive, k_rightDrive};
};
