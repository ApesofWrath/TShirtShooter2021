#include "Barrel.h"
#include <frc/smartdashboard/SmartDashboard.h>

// Contains elevation controls for the barrel

Barrel::Barrel()
{
    elevation_talon = new WPI_TalonSRX(28);
    controller = new frc::Joystick(0);
}

void Barrel::Init() { 
    elevation_talon->Set(0);
}

void Barrel::Down() {  // joy->GetRawAxis(0)
    frc::SmartDashboard::PutNumber("joy axis 1", controller->GetRawAxis(1));
    elevation_talon->Set(-0.2 * (controller->GetRawAxis(1) + 1));
}

void Barrel::Up() { 
    elevation_talon->Set(0.2 * ((controller->GetRawAxis(0) + 1)));
}

void Barrel::Stop() { 
    elevation_talon->Set(0);
}

void Barrel::StateMachine() {
    frc::SmartDashboard::PutNumber("b state", current_state);
    frc::SmartDashboard::PutNumber("joy axis 1", controller->GetRawAxis(1));

    switch (current_state)
    {
        case States::INIT:
            Init();
        break;

        case States::DOWN:
            Down();

        break;

        case States::UP:
            Up();
            break;
        case States::STOP:
            Stop();
            break;
        
    }

}





