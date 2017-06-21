// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#include "Robot.hpp"

#include <thread>

using namespace std::chrono_literals;

void SunBot::OperatorControl() {
    confettiPrimer.Set(true);
    confettiEject.Set(false);
    while (IsOperatorControl() && IsEnabled()) {
        if (controller.GetStickButton(GenericHID::kLeftHand)) {
            robotDrive.Drive(controller.GetY(GenericHID::kLeftHand),
                             controller.GetX(GenericHID::kRightHand),
                             controller.GetStickButton(GenericHID::kRightHand));
        } else {
            robotDrive.Drive(controller.GetY(GenericHID::kLeftHand) * 0.5,
                             controller.GetX(GenericHID::kRightHand) * 0.5,
                             controller.GetStickButton(GenericHID::kRightHand));
        }

        // Primes confetti shooter on X press
        if (controllerButtons.PressedButton(3)) {
            confettiPrimer.Set(true);
            confettiEject.Set(false);
        }
        // Fires confetti on Y press
        if (controllerButtons.PressedButton(4)) {
            confettiEject.Set(true);
            confettiPrimer.Set(false);
        }

        AwardLift();

        controllerButtons.Update();
        std::this_thread::sleep_for(10ms);
    }
}

START_ROBOT_CLASS(SunBot)
