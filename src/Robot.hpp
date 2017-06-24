// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#pragma once

#include <Compressor.h>
#include <DoubleSolenoid.h>
#include <GenericHID.h>
#include <RobotDrive.h>
#include <SampleRobot.h>
#include <Solenoid.h>
#include <Timer.h>
#include <Timer.h>
#include <ctrlib/CANTalon.h>

#include "ButtonTracker.hpp"
#include "Constants.hpp"
#include "DriveTrain.hpp"
#include "XboxController.h"
#include "mindsensors.h"

class SunBot : public SampleRobot {
public:
    SunBot();

    void OperatorControl() override;

    void AwardLift();

private:
    DriveTrain robotDrive;
    frc::XboxController controller{k_controller};
    ButtonTracker controllerButtons{k_controller};
    Solenoid confettiEject{k_confettiEject};
    Solenoid confettiPrimer{k_confettiPrimer};
    DoubleSolenoid door{k_doorUp, k_doorDown};
    DoubleSolenoid lift{k_liftDown, k_liftUp};
    Timer timer;
    mindsensors::CANLight light{21};
};
