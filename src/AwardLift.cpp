// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#include "Constants.hpp"
#include "Robot.hpp"

enum class State { Idle, DoorUp, AwardUp, AwardDown };

void SunBot::AwardLift() {
    static State state = State::Idle;
    switch (state) {
        case State::Idle:
            // On right bumper press, open door
            if (controllerButtons.PressedButton(5)) {
                door.Set(frc::DoubleSolenoid::kForward);
                state = State::DoorUp;
            }
            break;
        case State::DoorUp:
            // Wait two seconds, then raise award
            if (timer.HasPeriodPassed(2.0)) {
                lift.Set(frc::DoubleSolenoid::kReverse);
                state = State::AwardUp;
            }
            break;
        case State::AwardUp:
            // On right bumper press, lower award
            if (controllerButtons.PressedButton(5)) {
                lift.Set(frc::DoubleSolenoid::kForward);
                state = State::AwardDown;
            }
            break;
        case State::AwardDown:
            // Wait two seconds, then close door
            if (timer.HasPeriodPassed(2.0)) {
                door.Set(frc::DoubleSolenoid::kReverse);
                state = State::Idle;
            }
            break;
    }
}
