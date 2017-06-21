// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#pragma once

// Includes definition for Talons and etc that connect to the RoboRIO

/* Order of subsystem constants:
 * > Motor IDs
 * > Other (i.e. miscellaneous constants)
 */

// TODO: Create enums mapping out XboxController buttons, then fix the control
// scheme

/* Order of subsystem constants:
 * > Motor IDs
 * > Other (i.e. miscellaneous constants)
 */

// Controller
constexpr int k_controller = 0;

constexpr double k_joystickDeadband = 0.02;

/*
 * DriveTrain
 */

// DriveTrain GearBox ID
constexpr int k_leftDriveMasterID = 1;
constexpr int k_leftDriveSlaveID = 2;
constexpr int k_rightDriveMasterID = 13;
constexpr int k_rightDriveSlaveID = 14;

// CheesyDrive constants
constexpr double k_lowGearSensitive = 0.75;
constexpr double k_turnNonLinearity = 1.0;
constexpr double k_inertiaDampen = 2.5;
constexpr double k_inertiaHighTurn = 3.0;
constexpr double k_inertiaLowTurn = 3.0;

// Solenoids
constexpr int k_confettiPrimer = 0;
constexpr int k_confettiEject = 1;
