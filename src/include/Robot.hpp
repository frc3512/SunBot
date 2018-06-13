// Copyright (c) 2017-2018 FRC Team 3512. All Rights Reserved.

#pragma once

#include <DoubleSolenoid.h>
#include <GenericHID.h>
#include <RobotDrive.h>
#include <SampleRobot.h>
#include <Solenoid.h>
#include <Timer.h>

#include "ButtonTracker.hpp"
#include "CANTalonGroup.hpp"
#include "Constants.hpp"
#include "DriveTrain.hpp"
#include "XboxController.h"

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
};
