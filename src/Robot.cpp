// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#include "Robot.hpp"

#include <thread>

using namespace std::chrono_literals;

SunBot::SunBot() {
    timer.Start();
    light.ShowRGB(0, 0, 255);
    light.WriteRegister(7, 1, 0, 0, 255);
    light.WriteRegister(6, 1, 0, 0, 0);
    light.Fade(7, 6);
}

void SunBot::OperatorControl() {
    // Defaut state: Door and lift lowered, confetti barrel sealed.
    lift.Set(frc::DoubleSolenoid::kForward);
    door.Set(frc::DoubleSolenoid::kReverse);
    confettiPrimer.Set(false);
    confettiEject.Set(false);
    timer.Start();

    // light.ShowRGB(255, 0, 0);
    // light.WriteRegister(7, 1, 255, 0, 0);
    // light.WriteRegister(6, 1, 0, 0, 0);

    while (IsOperatorControl() && IsEnabled()) {
        // Drive code
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
            confettiEject.Set(false);
            confettiPrimer.Set(true);
        }
        // Fires confetti on Y press
        if (controllerButtons.PressedButton(4)) {
            confettiPrimer.Set(false);
            confettiEject.Set(true);
        }

        AwardLift();

        Lights();

        controllerButtons.Update();


        /*if (timer.HasPeriodPassed(2)) {
        	std::cout << "Blink" << std::endl;
        	light.Fade(7, 6);
        	timer.Reset();
        }*/
        // light.ShowRGB(0, 255, 0);


        std::this_thread::sleep_for(10ms);
    }
}

START_ROBOT_CLASS(SunBot)
