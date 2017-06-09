// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#pragma once

#include <SampleRobot.h>
#include <XboxController.h>
#include <ctrlib/CANTalon.h>

#include "Constants.hpp"
#include "DriveTrain.hpp"

class SunBot : public SampleRobot {
public:
    void OperatorControl() override;

private:
    DriveTrain robotDrive;
    frc::XboxController controller{k_controller};
};
