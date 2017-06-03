// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#pragma once

#include <Compressor.h>
#include <GenericHID.h>
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
    RobotDrive robotDrive{k_leftDrive, k_rightDrive};
    XboxController controller{k_controller};
    ButtonTracker controllerButtons{k_controller};
    Compressor compressor;
    Solenoid confettiEject{7};
    Solenoid confettiPrimer{6};
};
