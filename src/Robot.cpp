// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#include "Robot.hpp"

#include <thread>

using namespace std::chrono_literals;

void SunBot::OperatorControl() {
    confettiPrimer.Set(true);
    confettiEject.Set(false);
    while (IsOperatorControl() && IsEnabled()) {
        robotDrive.ArcadeDrive(controller.GetY(GenericHID::kLeftHand),
                               controller.GetX(GenericHID::kRightHand));
        if (controllerButtons.PressedButton(controller.kStickLeft) &&
            controllerButtons.PressedButton(controller.kX)) {
            confettiPrimer.Set(false);
            confettiEject.Set(true);
        }
        if (controllerButtons.PressedButton(controller.kY)) {
            confettiEject.Set(false);
            confettiPrimer.Set(true);
        }
        controllerButtons.Update();
    }
}

START_ROBOT_CLASS(SunBot)
