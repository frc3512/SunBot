// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#pragma once

#include <Compressor.h>
#include <GenericHID.h>
#include <RobotDrive.h>
#include <SampleRobot.h>
#include <Solenoid.h>
#include <ctrlib/CANTalon.h>
#include <Timer.h>

#include "ButtonTracker.hpp"
#include "Constants.hpp"
#include "DriveTrain.hpp"
#include "mindsensors.h"
#include "XboxController.h"

class SunBot : public SampleRobot {
public:
    void OperatorControl() override;

private:
    DriveTrain robotDrive;
    frc::XboxController controller{k_controller};
    ButtonTracker controllerButtons{k_controller};
    Solenoid confettiEject{k_confettiEject};
    Solenoid confettiPrimer{k_confettiPrimer};
    frc::Timer timer;
    mindsensors::CANLight light{21};
};
