// Copyright (c) 2016-2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#pragma once

#include "ErrorBase.h"
#include "GenericHID.h"

namespace frc {

/**
 * Handle input from Xbox 360 or Xbox One controllers connected to the Driver
 * Station.
 *
 * This class handles Xbox input that comes from the Driver Station. Each time a
 * value is requested the most recent value is returend. There is a single class
 * instance for each controller and the mapping of ports to hardware buttons
 * depends on the code in the Driver Station.
 */
class XboxController : public GenericHID {
public:
    enum ButtonType {
        kBumper = 100,  // Larger than possible buttons
        kStick = 101,   // Larger than possible buttons
        kBumperLeft = 5,
        kBumperRight = 6,
        kStickLeft = 9,
        kStickRight = 10,
        kA = 1,
        kB = 2,
        kX = 3,
        kY = 4,
        kBack = 7,
        kStart = 8
    };

    explicit XboxController(int port);
    virtual ~XboxController() = default;

    XboxController(const XboxController&) = delete;
    XboxController& operator=(const XboxController&) = delete;

    double GetX(JoystickHand hand) const override;
    double GetY(JoystickHand hand) const override;

    virtual double GetTriggerAxis(JoystickHand hand) const;

    bool GetButton(ButtonType button, JoystickHand hand = kRightHand) const;
    bool ButtonPressed(ButtonType button, JoystickHand hand = kRightHand);
    bool ButtonReleased(ButtonType button, JoystickHand hand = kRightHand);

private:
    uint32_t m_pressedButtons = 0;
    uint32_t m_releasedButtons = 0;

    int GetButtonIndex(ButtonType button, JoystickHand hand = kRightHand) const;
};

}  // namespace frc
