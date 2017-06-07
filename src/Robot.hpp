// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#pragma once

#include <Compressor.h>
#include <RobotDrive.h>
#include <SampleRobot.h>
#include <Solenoid.h>

#include "ButtonTracker.hpp"
#include "Constants.hpp"
#include "XboxController.h"

class SunBot : public frc::SampleRobot {
public:
    void OperatorControl() override;

private:
    frc::RobotDrive robotDrive{k_leftDrive, k_rightDrive};
    frc::XboxController controller{k_controller};
    ButtonTracker controllerButtons{k_controller};
    frc::Compressor compressor;
    frc::Solenoid confettiEject{0};   // TODO: find right channel
    frc::Solenoid confettiPrimer{1};  // TODO: find right channel
};
