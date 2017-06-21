// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#include "Constants.hpp"
#include "Robot.hpp"

enum class State { Idle, DoorUp, AwardUp, AwardDown };

void SunBot::AwardLift() {
    static State state = State::Idle;
    switch (state) {
        case State::Idle:
            if (controllerButtons.PressedButton(2)) {
                door.Set(frc::DoubleSolenoid::kForward);
                state = State::DoorUp;
            }
            break;
        case State::DoorUp:
            if (timer.HasPeriodPassed(2.0)) {
                lift.Set(frc::DoubleSolenoid::kReverse);
                state = State::AwardUp;
            }
            break;
        case State::AwardUp:
            if (controllerButtons.PressedButton(2)) {
                lift.Set(frc::DoubleSolenoid::kForward);
                state = State::AwardDown;
            }
            break;
        case State::AwardDown:
            if (timer.HasPeriodPassed(2.0)) {
                door.Set(frc::DoubleSolenoid::kReverse);
                state = State::Idle;
            }
            break;
    }
}
