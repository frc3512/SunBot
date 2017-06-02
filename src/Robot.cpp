// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#include "Robot.hpp"

using namespace std::chrono_literals;

void Robot::OperatorControl() {
    while (IsEnabled() && IsOperatorControl()) {
        drive.ArcadeDrive(driveStick1.GetY(), driveStick2.GetX(), true);

        std::this_thread::sleep_for(10ms);
    }
}

START_ROBOT_CLASS(Robot)
