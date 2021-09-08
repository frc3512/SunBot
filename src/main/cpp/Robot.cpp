// Copyright (c) 2017-2021 FRC Team 3512. All Rights Reserved.

#include "Robot.hpp"

enum class State { kIdle, kDoorUp, kAwardUp, kAwardDown };

Robot::Robot() {
    rightGrbx.SetInverted(true);
    timer.Start();
}

void Robot::TeleopInit() {
    // Defaut state: Door and lift lowered, confetti barrel sealed.
    lift.Set(frc::DoubleSolenoid::kForward);
    door.Set(frc::DoubleSolenoid::kReverse);
    confettiPrimer.Set(false);
    confettiEject.Set(false);

    timer.Start();
}

void Robot::TeleopPeriodic() {
    // Drive code
    if (controller.GetStickButton(frc::GenericHID::kLeftHand)) {
        drive.CurvatureDrive(
            controller.GetY(frc::GenericHID::kLeftHand),
            controller.GetX(frc::GenericHID::kRightHand),
            controller.GetStickButton(frc::GenericHID::kRightHand));
    } else {
        drive.CurvatureDrive(
            controller.GetY(frc::GenericHID::kLeftHand) * 0.5,
            controller.GetX(frc::GenericHID::kRightHand) * 0.5,
            controller.GetStickButton(frc::GenericHID::kRightHand));
    }

    // Primes confetti shooter on X press
    if (controller.GetXButtonPressed()) {
        confettiEject.Set(false);
        confettiPrimer.Set(true);
    }
    // Fires confetti on Y press
    if (controller.GetYButtonPressed()) {
        confettiPrimer.Set(false);
        confettiEject.Set(true);
    }

    AwardLift();
}

void Robot::AwardLift() {
    static State state = State::kIdle;
    switch (state) {
        case State::kIdle:
            // On right bumper press, open door
            if (controller.GetBumperPressed(frc::GenericHID::kRightHand)) {
                std::cout << "Door Up." << std::endl;
                timer.Reset();
                door.Set(frc::DoubleSolenoid::kForward);
                state = State::kDoorUp;
            }
            break;
        // Wait two seconds, raise award
        case State::kDoorUp:
            if (timer.HasPeriodPassed(2_s)) {
                std::cout << "Award Up." << std::endl;
                lift.Set(frc::DoubleSolenoid::kReverse);
                state = State::kAwardUp;
            }
            break;
        // On right bumper press, lower award
        case State::kAwardUp:
            if (controller.GetBumperPressed(frc::GenericHID::kRightHand)) {
                std::cout << "Award Down." << std::endl;
                timer.Reset();
                lift.Set(frc::DoubleSolenoid::kForward);
                state = State::kAwardDown;
            }
            break;
        // Wait two seconds, close door
        case State::kAwardDown:
            if (timer.HasPeriodPassed(2_s)) {
                std::cout << "Idle." << std::endl;
                door.Set(frc::DoubleSolenoid::kReverse);
                state = State::kIdle;
            }
            break;
    }
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
