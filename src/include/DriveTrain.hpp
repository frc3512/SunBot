// Copyright (c) 2016-2018 FRC Team 3512. All Rights Reserved.

#pragma once

#include <Drive/DifferentialDrive.h>
#include <ctre/phoenix/MotorControl/CAN/WPI_TalonSRX.h>

#include "Constants.hpp"
#include "CANTalonGroup.hpp"

class CANTalonGroup;

/**
 * Provides an interface for this year's drive train
 */
class DriveTrain {
public:
    using WPI_TalonSRX = ctre::phoenix::motorcontrol::can::WPI_TalonSRX;

    DriveTrain();
    virtual ~DriveTrain() = default;

    void Drive(double throttle, double turn, bool isQuickTurn);

    // Directly set wheel speeds [0..1] (see GearBox::SetManual(double))
    void SetLeftManual(double value);
    void SetRightManual(double value);

    // Sends print statements for debugging purposes
    void Debug();

private:
    // Left gearbox used in position PID
    WPI_TalonSRX m_leftFront{k_leftDriveMasterID};
    WPI_TalonSRX m_leftRear{k_leftDriveSlaveID};
    CANTalonGroup m_leftGrbx{m_leftFront, m_leftRear};

    // Right gearbox used in position PID
    WPI_TalonSRX m_rightFront{k_rightDriveMasterID};
    WPI_TalonSRX m_rightRear{k_rightDriveSlaveID};
    CANTalonGroup m_rightGrbx{m_rightFront, m_rightRear};

    frc::DifferentialDrive m_drive{m_leftGrbx, m_rightGrbx};

};
