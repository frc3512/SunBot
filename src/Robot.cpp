// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#include "Robot.hpp"

#include <thread>

using namespace std::chrono_literals;

SunBot::SunBot() {
	timer.Start();
}

void SunBot::OperatorControl() {
	// Defaut state: Door and lift lowered, confetti barrel sealed.
	lift.Set(frc::DoubleSolenoid::kForward);
	door.Set(frc::DoubleSolenoid::kReverse);
    confettiPrimer.Set(false);
    confettiEject.Set(false);
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
