#pragma once
#include "Shooter.h"
#include <frc/Joystick.h>

class TeleopStateMachine
{
private:
    /* data */
public:

    enum States {
        INIT, WAIT_FOR_BUTTON, INPUT_VALVE,
        UP_STATE, OUTPUT_VALVE, EMERGENCY_STATE
    };

    States current_state;

    Shooter *shooter;

    TeleopStateMachine(Shooter *shooter_, frc::Joystick *joystick);
    void StateMachine();
};


