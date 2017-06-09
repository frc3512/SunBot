// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#include "Robot.hpp"

#include <thread>

using namespace std::chrono_literals;

void SunBot::OperatorControl() {
    while (IsOperatorControl() && IsEnabled()) {
        std::this_thread::sleep_for(10ms);
    }
}

START_ROBOT_CLASS(SunBot)
