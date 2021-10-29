#include "TeleopStateMachine.h"

TeleopStateMachine::TeleopStateMachine(Shooter *shooter_, frc::Joystick *joystick_, Barrel *barrel_)
{
    shooter = shooter_;
    barrel = barrel_;
    joystick = joystick_;
    
    current_state = States::STOP;
}

void TeleopStateMachine::UpdateButtons(){

    if(joystick->GetRawButton(8)){
        current_state = States::SHOOT;
    }
    

    if(joystick->GetRawButton(5)){

        current_state = States::RUN;
    } 

    if(joystick->GetRawButton(6)){
        current_state = States::STOP;
    }

    if(joystick->GetRawButton(up_button)){
        current_state = States::UP;
    }

    if(joystick->GetRawButton(down_button)){
        current_state = States::DOWN;
    }

    frc::SmartDashboard::PutNumber("state" ,(int) current_state);
}

void TeleopStateMachine::StateMachine(){

    UpdateButtons();

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
        barrel->current_state = Barrel::States::STOP;
        break;

    case States::SHOOT:
        shooter->current_state = Shooter::States::SHOOT;

        break;

    case States::UP:
        barrel->current_state = Barrel::States::UP;
        break;

    case States::DOWN:
        barrel->current_state = Barrel::States::DOWN;
        break;

    case States::EMERGENCY_STATE:

        break;
        
    default:
        break;
    }

    shooter->StateMachine();
    barrel->StateMachine();

}