// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#pragma once

#include <vector>

#include "ErrorBase.h"
#include "JoystickBase.h"

namespace frc {

class DriverStation;

/**
 * Handle input from standard Joysticks connected to the Driver Station.
 * This class handles standard input that comes from the Driver Station. Each
 * time a value is requested the most recent value is returned. There is a
 * single class instance for each joystick and the mapping of ports to hardware
 * buttons depends on the code in the Driver Station.
 */
class Joystick : public JoystickBase {
public:
    static const int kDefaultXAxis = 0;
    static const int kDefaultYAxis = 1;
    static const int kDefaultZAxis = 2;
    static const int kDefaultTwistAxis = 2;
    static const int kDefaultThrottleAxis = 3;

    enum AxisType {
        kXAxis,
        kYAxis,
        kZAxis,
        kTwistAxis,
        kThrottleAxis,
        kNumAxisTypes
    };

    enum ButtonType { kTrigger = 1, kTop = 2, kNumButtonTypes = 2 };

    explicit Joystick(int port);
    Joystick(int port, int numAxisTypes, int numButtonTypes);
    virtual ~Joystick() = default;

    Joystick(const Joystick&) = delete;
    Joystick& operator=(const Joystick&) = delete;

    int GetAxisChannel(AxisType axis) const;
    void SetAxisChannel(AxisType axis, int channel);

    double GetX(JoystickHand hand = kRightHand) const override;
    double GetY(JoystickHand hand = kRightHand) const override;
    double GetZ(JoystickHand hand = kRightHand) const override;
    double GetTwist() const override;
    double GetThrottle() const override;
    virtual double GetAxis(AxisType axis) const;

    bool GetButton(ButtonType button) const;
    bool ButtonPressed(ButtonType button);
    bool ButtonReleased(ButtonType button);

    virtual double GetMagnitude() const;
    virtual double GetDirectionRadians() const;
    virtual double GetDirectionDegrees() const;

    int GetAxisType(int axis) const;

    int GetAxisCount() const;
    int GetButtonCount() const;

private:
    DriverStation& m_ds;
    std::vector<int> m_axes;
    std::vector<int> m_buttons;
};

}  // namespace frc
