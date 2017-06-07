// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#include "XboxController.h"

#include "HAL/HAL.h"

using namespace frc;

/**
 * Construct an instance of an Xbox controller.
 *
 * The controller index is the USB port on the Driver Station.
 *
 * @param port The port on the Driver Station that the controller is plugged
 *             into (0-5).
 */
XboxController::XboxController(int port) : GenericHID(port) {
    // HAL_Report(HALUsageReporting::kResourceType_XboxController, port);
    HAL_Report(HALUsageReporting::kResourceType_Joystick, port);
}

/**
 * Get the X axis value of the controller.
 *
 * @param hand Side of controller whose value should be returned.
 */
double XboxController::GetX(JoystickHand hand) const {
    if (hand == kLeftHand) {
        return GetRawAxis(0);
    } else {
        return GetRawAxis(4);
    }
}

/**
 * Get the Y axis value of the controller.
 *
 * @param hand Side of controller whose value should be returned.
 */
double XboxController::GetY(JoystickHand hand) const {
    if (hand == kLeftHand) {
        return GetRawAxis(1);
    } else {
        return GetRawAxis(5);
    }
}

/**
 * Get the trigger axis value of the controller.
 *
 * @param hand Side of controller whose value should be returned.
 */
double XboxController::GetTriggerAxis(JoystickHand hand) const {
    if (hand == kLeftHand) {
        return GetRawAxis(2);
    } else {
        return GetRawAxis(3);
    }
}

/**
 * Get buttons based on an enumerated type.
 *
 * The button type will be looked up in the list of buttons and then read.
 *
 * @param button The type of button to read.
 * @return The state of the button.
 */
bool XboxController::GetButton(ButtonType button, JoystickHand hand) const {
    return GetRawButton(GetButtonIndex(button, hand));
}

/**
 * Whether the button was pressed since the last check. Button indexes begin at
 * 1. The button type is mapped to a button index first.
 *
 * @param button The button index, beginning at 1.
 * @return Whether the button was pressed since the last check.
 */
bool XboxController::ButtonPressed(ButtonType button, JoystickHand hand) {
    return RawButtonPressed(GetButtonIndex(button, hand));
}

/**
 * Whether the button was released since the last check. Button indexes begin at
 * 1. The button type is mapped to a button index first.
 *
 * @param button The button index, beginning at 1.
 * @return Whether the button was released since the last check.
 */
bool XboxController::ButtonReleased(ButtonType button, JoystickHand hand) {
    return RawButtonReleased(GetButtonIndex(button, hand));
}

/**
 * Returns button index corresponding to a button type
 */
int XboxController::GetButtonIndex(ButtonType button, JoystickHand hand) const {
    if (button == kBumper) {
        if (hand == kLeftHand) {
            return kBumperLeft;
        } else {
            return kBumperRight;
        }
    } else if (button == kStick) {
        if (hand == kLeftHand) {
            return kStickLeft;
        } else {
            return kStickRight;
        }
    } else {
        return button;
    }
}
