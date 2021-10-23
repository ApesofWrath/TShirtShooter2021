#include "Shooter.h"

// Will contain the controls for firing and compressors

Shooter::Shooter()
{

    m_compressor1 = new WPI_TalonSRX(0);
    m_compressor2 = new WPI_TalonSRX(0);
    m_firing_valve = new frc::Solenoid(1, 2); // Solenoid


}

void Shooter::Init() { 
    m_compressor1->Set(0.0);
    m_compressor2->Set(0.0);
}

void Shooter::Stop(){
    m_compressor1->Set(0.0);
    m_compressor2->Set(0.0);
}

void Shooter::Go(){
    m_compressor1->Set(1.0);
    m_compressor2->Set(1.0);

}

void Shooter::Shoot(){
    
}



void Shooter::StateMachine() {

    switch (current_state)
    {
        case States::INIT:
            Init();

            break;

        case States::STOP:
            Stop();

            break;    
        
        case States::GO:
            Go();

            break;
        case States::SHOOT:
            Shoot();

            break;
            

        
    }

}