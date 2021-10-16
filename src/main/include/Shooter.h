#pragma once
#include <ctre/Phoenix.h>

class Shooter
{
private:
    WPI_TalonSRX *m_compressor1;

public:

    enum States {
        INIT, UP, DOWN
    };

    States current_state;

    Shooter();
    void Init();
    void StateMachine();
};


