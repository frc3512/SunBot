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
        if (controllerButtons.HeldButton(5) &&
            controllerButtons.PressedButton(3)) {
            confettiPrimer.Set(false);
            confettiEject.Set(true);
        }
        if (controllerButtons.PressedButton(4)) {
            confettiEject.Set(false);
            confettiPrimer.Set(true);
        }
        controllerButtons.Update();
        std::this_thread::sleep_for(10ms);
    }
}

START_ROBOT_CLASS(SunBot)
