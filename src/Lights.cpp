// Copyright (c) 2017 FRC Team 3512, Spartatroniks. All Rights Reserved.

#include "Constants.hpp"
#include "Robot.hpp"

enum class State { Red, Blue, Yellow, Green, Purple, Orange, White, Off };

// Toggling B will cycle through the color sequence listed above
void SunBot::Lights() {
    static State state = State::Red;
    switch (state) {
        case State::Red:
            if (controllerButtons.PressedButton(2)) {
                std::cout << "Red." << std::endl;
                light.ShowRGB(255, 0, 0);
                state = State::Blue;
            }
            break;
        case State::Blue:
            if (controllerButtons.PressedButton(2)) {
                std::cout << "Blue." << std::endl;
                light.ShowRGB(0, 0, 255);
                state = State::Yellow;
            }
            break;
        case State::Yellow:
            if (controllerButtons.PressedButton(2)) {
                std::cout << "Yellow." << std::endl;
                light.ShowRGB(100, 100, 0);
                state = State::Green;
            }
            break;
        case State::Green:
            if (controllerButtons.PressedButton(2)) {
                std::cout << "Green." << std::endl;
                light.ShowRGB(0, 255, 0);
                state = State::Purple;
            }
            break;
        case State::Purple:
            if (controllerButtons.PressedButton(2)) {
                std::cout << "Purple." << std::endl;
                light.ShowRGB(255, 0, 255);
                state = State::Orange;
            }
            break;
        case State::Orange:
            if (controllerButtons.PressedButton(2)) {
                std::cout << "Orange." << std::endl;
                light.ShowRGB(255, 128, 0);
                state = State::White;
            }
            break;
        case State::White:
            if (controllerButtons.PressedButton(2)) {
                std::cout << "White." << std::endl;
                light.ShowRGB(255, 255, 255);
                state = State::Off;
            }
            break;
        case State::Off: // No color
            if (controllerButtons.PressedButton(2)) {
                std::cout << "Lights out." << std::endl;
                light.ShowRGB(0, 0, 0);
                state = State::Red;
            }
            break;
    }
}
