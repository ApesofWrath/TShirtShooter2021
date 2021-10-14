#include "Shooter.h"

// Will contain the controls for firing and compressors

Shooter::Shooter()
{

    m_compressor1 = new WPI_TalonSRX(0);

}
