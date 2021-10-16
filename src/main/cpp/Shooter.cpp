#include "Shooter.h"

// Will contain the controls for firing and compressors

Shooter::Shooter()
{

    m_compressor1 = new WPI_TalonSRX(0);

}

void Shooter::Init() { }

void Shooter::StateMachine() {

    switch (current_state)
    {
        case States::INIT:
            Init();

        break;

        case States::UP:
            
            break;

        
    }

}