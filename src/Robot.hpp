// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#pragma once

#include <ctrlib/CANTalon.h>
#include <SampleRobot.h>
#include <XboxController.h>
#include "DriveTrain.hpp"

#include "Constants.hpp"

class SunBot : public SampleRobot {
public:
    void OperatorControl() override;

private:
    DriveTrain robotDrive;
    frc::XboxController controller{k_controller};
};
