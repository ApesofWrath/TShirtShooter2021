#pragma once

#include <ctre/Phoenix.h>

class Barrel
{
private:
    
public:
    Barrel();
    float GetElevation();

    WPI_TalonSRX *elevation_talon;
};


