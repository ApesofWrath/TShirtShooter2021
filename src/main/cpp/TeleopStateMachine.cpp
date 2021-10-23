#include "TeleopStateMachine.h"

TeleopStateMachine::TeleopStateMachine(Shooter *shooter_, frc::Joystick *joystick_, Barrel *barrel_)
{
    shooter = shooter_;
    barrel = barrel_;
    joystick = joystick_;
    
}

void TeleopStateMachine::UpdateButtons(){
    if(joystick->GetRawButton(start_compressor_button)){
        current_state = States::RUN;
    }

    if(joystick->GetRawButton(stop_compressor_button)){
        current_state = States::STOP;
    }

    if(joystick->GetRawButton(shoot_button)){
        current_state = States::SHOOT;
    } else {
        current_state = States::STOP;
    }

    if(joystick->GetRawButton(up_button)){
        current_state = States::UP;
    }

    if(joystick->GetRawButton(down_button)){
        current_state = States::DOWN;
    }
}

void TeleopStateMachine::StateMachine(){

    switch (current_state)
    {
    case States::INIT:
        shooter->current_state = Shooter::States::INIT;
        break;
    
    case States::RUN:
        shooter->current_state = Shooter::States::GO;
        
        break;

    case States::STOP:
        shooter->current_state = Shooter::States::STOP;

        break;

    case States::SHOOT:
        shooter->current_state = Shooter::States::SHOOT;

        break;

    case States::UP:

        break;

    case States::DOWN:

        break;

    case States::EMERGENCY_STATE:

        break;
        
    default:
        break;
    }

}