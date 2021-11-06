// #include <AHRS.h>
#include <frc/WPILib.h>
#include "ctre/Phoenix.h"

#ifndef DRIVECONTROLLER_H_
#define DRIVECONTROLLER_H_

class DriveController {
public:


	TalonSRX *canTalonFrontLeft, *canTalonFrontRight, *canTalonBackLeft,
				*canTalonBackRight;
	// AHRS *ahrs;

    double x_input;
    double y_input;

    const int CAN_TALON_FRONT_LEFT = 24;  
    const int CAN_TALON_BACK_LEFT = 21;
    const int CAN_TALON_FRONT_RIGHT = 27;
    const int CAN_TALON_BACK_RIGHT = 26;




	DriveController();
	void Drive(frc::Joystick *joyThrottle);
	// void DriveTest(Joystick *joyThrottle, Joystick *joyWheel);

};

#endif /* DRIVECONTROLLER_H_ */