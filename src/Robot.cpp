// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#include "Robot.hpp"

#include <thread>

using namespace std::chrono_literals;

void SunBot::OperatorControl() {
    confettiPrimer.Set(true);
    confettiEject.Set(false);
    timer.Start();
    light.ShowRGB(0, 0, 255);
    light.WriteRegister(7, 1, 0, 0, 255);
    light.WriteRegister(6, 1, 0, 0, 0);

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
        if (controllerButtons.HeldButton(5) &&
            controllerButtons.PressedButton(3)) {
            confettiPrimer.Set(false);
            confettiEject.Set(true);
        }
        if (controllerButtons.PressedButton(4)) {
            confettiEject.Set(false);
            confettiPrimer.Set(true);
        }

        if (timer.HasPeriodPassed(2)){
            std::cout << "Blink" << std::endl;
            light.Fade(7, 6);
            timer.Reset();
        }

        std::this_thread::sleep_for(10ms);
    }
}

START_ROBOT_CLASS(SunBot)
