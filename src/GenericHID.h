// Copyright (c) 2008-2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#pragma once

#include <stdint.h>

#include <string>

#include "ErrorBase.h"

namespace frc {

class DriverStation;

/**
 * GenericHID Interface.
 */
class GenericHID : public ErrorBase {
public:
    enum RumbleType { kLeftRumble, kRightRumble };

    enum HIDType {
        kUnknown = -1,
        kXInputUnknown = 0,
        kXInputGamepad = 1,
        kXInputWheel = 2,
        kXInputArcadeStick = 3,
        kXInputFlightStick = 4,
        kXInputDancePad = 5,
        kXInputGuitar = 6,
        kXInputGuitar2 = 7,
        kXInputDrumKit = 8,
        kXInputGuitar3 = 11,
        kXInputArcadePad = 19,
        kHIDJoystick = 20,
        kHIDGamepad = 21,
        kHIDDriving = 22,
        kHIDFlight = 23,
        kHID1stPerson = 24
    };

    enum JoystickHand { kLeftHand = 0, kRightHand = 1 };

    explicit GenericHID(int port);
    virtual ~GenericHID() = default;

    virtual double GetX(JoystickHand hand = kRightHand) const = 0;
    virtual double GetY(JoystickHand hand = kRightHand) const = 0;
    virtual double GetRawAxis(int axis) const;

    bool GetRawButton(int button) const;
    bool RawButtonPressed(int button);
    bool RawButtonReleased(int button);

    int GetPOV(int pov = 0) const;
    int GetPOVCount() const;

    int GetPort() const;
    GenericHID::HIDType GetType() const;
    std::string GetName() const;

    void SetOutput(int outputNumber, bool value);
    void SetOutputs(int value);
    void SetRumble(RumbleType type, double value);

private:
    DriverStation& m_ds;
    int m_port;
    int m_outputs = 0;
    uint16_t m_leftRumble = 0;
    uint16_t m_rightRumble = 0;
};

}  // namespace frc
