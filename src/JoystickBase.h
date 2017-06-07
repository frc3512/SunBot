// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#pragma once

#include "GenericHID.h"

namespace frc {

/**
 * Joystick Interface.
 */
class JoystickBase : public GenericHID {
public:
    explicit JoystickBase(int port);
    virtual ~JoystickBase() = default;

    virtual double GetZ(JoystickHand hand = kRightHand) const = 0;
    virtual double GetTwist() const = 0;
    virtual double GetThrottle() const = 0;
};

}  // namespace frc
