// Copyright (c) 2017-2020 FRC Team 3512. All Rights Reserved.

#pragma once

#include <array>

#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <frc/DoubleSolenoid.h>
#include <frc/Solenoid.h>
#include <frc/Spark.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/TimedRobot.h>
#include <frc/XboxController.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc2/Timer.h>

class Robot : public frc::TimedRobot {
public:
    Robot();

    void TeleopInit() override;
    void TeleopPeriodic() override;

    void AwardLift();

private:
    // Colors: off, red, blue, yellow, green, purple, orange, white
    static constexpr std::array<double, 8> kColors = {0.99, 0.61, 0.87, 0.69,
                                                      0.77, 0.91, 0.65, 0.93};

    ctre::phoenix::motorcontrol::can::WPI_TalonSRX frontLeftMotor{1};
    ctre::phoenix::motorcontrol::can::WPI_TalonSRX frontRightMotor{13};
    ctre::phoenix::motorcontrol::can::WPI_TalonSRX rearLeftMotor{2};
    ctre::phoenix::motorcontrol::can::WPI_TalonSRX rearRightMotor{14};

    frc::SpeedControllerGroup leftGrbx{frontLeftMotor, rearLeftMotor};
    frc::SpeedControllerGroup rightGrbx{frontRightMotor, rearRightMotor};

    frc::DifferentialDrive drive{leftGrbx, rightGrbx};

    frc::XboxController controller{0};
    frc::Solenoid confettiEject{1};
    frc::Solenoid confettiPrimer{0};

    // First port is up and second port is down
    frc::DoubleSolenoid door{2, 3};

    // First port is down and second port is up
    frc::DoubleSolenoid lift{4, 5};
    frc2::Timer timer;
    frc::Spark light{1};
};
