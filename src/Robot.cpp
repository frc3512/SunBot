// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#include "Robot.hpp"

#include <thread>

using namespace std::chrono_literals;

void SunBot::OperatorControl() {
    while (IsOperatorControl() && IsEnabled()) {
	if (controller.GetStickButton(GenericHID::kLeftHand)){
	robotDrive.Drive(controller.GetY(GenericHID::kLeftHand), controller.GetX(GenericHID::kRightHand), controller.GetStickButton(GenericHID::kRightHand));
} else {
	robotDrive.Drive(controller.GetY(GenericHID::kLeftHand) * 0.6, controller.GetX(GenericHID::kRightHand) * 0.6, controller.GetStickButton(GenericHID::kRightHand));
}
        std::this_thread::sleep_for(10ms);
    }
}

START_ROBOT_CLASS(SunBot)
