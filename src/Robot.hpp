// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#pragma once

#include <ctrlib/CANTalon.h>
#include <Compressor.h>
#include <GenericHID.h>
#include <RobotDrive.h>
#include <SampleRobot.h>
#include <Solenoid.h>
#include "ButtonTracker.hpp"
#include "Constants.hpp"
#include "DriveTrain.hpp"
#include "XboxController.h"

class SunBot : public SampleRobot {
public:
    void OperatorControl() override;

private:
    DriveTrain robotDrive;
    frc::XboxController controller{k_controller};
    ButtonTracker controllerButtons{k_controller};
    Compressor compressor;
    Solenoid confettiEject{k_confettiEject};
    Solenoid confettiPrimer{k_confettiPrimer};
};
