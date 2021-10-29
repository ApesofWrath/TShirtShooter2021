#pragma once

#include <ctre/Phoenix.h>
#include <frc/WPILib.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <chrono>

class Shooter
{
private:
    WPI_TalonSRX *m_compressor1;
    WPI_TalonSRX *m_compressor2;
    frc::Solenoid *m_firing_valve;

    std::chrono::duration<double> counter;
    
    std::chrono::time_point<std::chrono::steady_clock> start;

    std::chrono::time_point<std::chrono::steady_clock> end;
public:

    enum States {
        INIT, STOP, GO,
        SHOOT
    };

    States current_state;
    States last_state;

    Shooter();
    void Init();
    void Stop();
    void Go();    
    void Shoot();    
    // void StartCounter();
    void ResetCounter();

    void StateMachine();
};


