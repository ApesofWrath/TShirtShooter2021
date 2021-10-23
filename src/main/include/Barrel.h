#pragma once

#include <ctre/Phoenix.h>

class Barrel
{
private:
    WPI_TalonSRX *elevation_talon;  
public:
    enum States{
        INIT, UP, DOWN, 
        STOP
    };

    States current_state;

    Barrel();
        void Init();
        void StateMachine();
        void Down();
        void Up();
        void Stop();
};


