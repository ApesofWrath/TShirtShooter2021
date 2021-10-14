#include "Barrel.h"

// Contains elevation controls for the barrel

Barrel::Barrel()
{
    elevation_talon = new WPI_TalonSRX(0);

}

float Barrel::GetElevation() {
    return elevation_talon->GetSelectedSensorPosition(1);
}

