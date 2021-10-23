#pragma once

#include <ctre/Phoenix.h>
#include <frc/WPILib.h>

class Shooter
{
private:
    WPI_TalonSRX *m_compressor1;
    WPI_TalonSRX *m_compressor2;
    frc::Solenoid *m_firing_valve;

public:

    enum States {
        INIT, STOP, GO,
        SHOOT
    };

    States current_state;

    Shooter();
    void Init();
    void Stop();
    void Go();    
    void Shoot();    
    
    
    void StateMachine();
};


