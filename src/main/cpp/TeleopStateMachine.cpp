#include "TeleopStateMachine.h"

TeleopStateMachine::TeleopStateMachine(Shooter *shooter_, frc::Joystick *joystick, Barrel *barrel_)
{
    shooter = shooter_;
    barrel = barrel_;
    
}

void TeleopStateMachine::StateMachine(){

    switch (current_state)
    {
    case States::INIT:
        
        break;
    
    case States::WAIT_FOR_BUTTON:

        break;

    case States::INPUT_VALVE:

        break;

    case States::OUTPUT_VALVE:

        break;

    case States::UP_STATE:

        break;

    case States::EMERGENCY_STATE:

        break;
        
    default:
        break;
    }

}