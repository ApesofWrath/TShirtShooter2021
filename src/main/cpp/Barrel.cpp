#include "Barrel.h"
#include <frc/smartdashboard/SmartDashboard.h>

// Contains elevation controls for the barrel

Barrel::Barrel()
{
    elevation_talon = new WPI_TalonSRX(28);
}

void Barrel::Init() { 
    elevation_talon->Set(0);
}

void Barrel::Down() { 
    elevation_talon->Set(-0.3);
}

void Barrel::Up() { 
    elevation_talon->Set(0.3);
}

void Barrel::Stop() { 
    elevation_talon->Set(0);
}

void Barrel::StateMachine() {
    frc::SmartDashboard::PutNumber("b state", current_state);
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





