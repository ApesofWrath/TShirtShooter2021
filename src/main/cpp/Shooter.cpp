#include "Shooter.h"

// Will contain the controls for firing and compressors

Shooter::Shooter()
{

    m_compressor1 = new WPI_TalonSRX(1);
    m_compressor2 = new WPI_TalonSRX(11);
    m_firing_valve = new frc::Solenoid(0, 3); // Solenoid


}

void Shooter::Init() { 
    m_compressor1->Set(0.0);
    m_compressor2->Set(0.0);
}

void Shooter::Stop(){
    m_compressor1->Set(0.0);
    m_compressor2->Set(0.0);
    m_firing_valve->Set(false);
}

void Shooter::Go(){
    m_compressor1->Set(1.0);
    m_compressor2->Set(1.0);
}

void Shooter::Shoot(){
    m_firing_valve->Set(true);
}



void Shooter::StateMachine() {

    frc::SmartDashboard::PutNumber("s state", current_state);

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