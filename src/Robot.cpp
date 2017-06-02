// Copyright (c) FRC Team 3512, Spartatroniks 2017. All Rights Reserved.

#include <chrono>

#include <RobotDrive.h>
#include <SampleRobot.h>
#include <XboxController.h>

#include "Constants.hpp"

using namespace std::chrono_literals;

class SunBot : public frc::SampleRobot {
public:
    void OperatorControl() override {
        while (IsOperatorControl() && IsEnabled()) {
            robotDrive.ArcadeDrive(controller.GetY(GenericHID::kLeftHand),
                                   controller.GetX(GenericHID::kRightHand));
        }
        std::this_thread::sleep_for(10ms);
    }

private:
    frc::RobotDrive robotDrive{k_leftDrive, k_rightDrive};
    frc::XboxController controller{k_controller};
};

START_ROBOT_CLASS(SunBot)
