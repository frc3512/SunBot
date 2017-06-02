// Copyright (c) FRC Team 3512, Spartatroniks 2017. All Rights Reserved.

#include "Robot.hpp"

Robot::Robot() {}

void Robot::OperatorControl() {
    while (IsEnabled() && IsOperatorControl()) {
        drive.ArcadeDrive(driveStick1.GetY(), driveStick2.GetX(), true);
    }
}

START_ROBOT_CLASS(Robot)
