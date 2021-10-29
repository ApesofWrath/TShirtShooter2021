#pragma once

#include <ctre/Phoenix.h>
#include <frc/Joystick.h>

// will change the elevation of the Barrel with the right joystick(?) or contain the variables for the elevation for the Barrel

class Barrel
{
private:
    WPI_TalonSRX *elevation_talon;  
    frc::Joystick *controller;

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


