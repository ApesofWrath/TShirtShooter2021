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

    double Kf_d = 1.0 / MAX_Y_RPM_ACTUAL; //scale down targets

    double target_l = 0;
    double target_r = 0;
    double target_yaw_rate = 0;
    double output_l = 0.0;
    double output_r = 0.0;

    const int CAN_TALON_FRONT_LEFT = 24;
    const int CAN_TALON_BACK_LEFT = 21;
    const int CAN_TALON_FRONT_RIGHT = 27;
    const int CAN_TALON_BACK_RIGHT = 26;

    const double MAX_Y_RPM_ACTUAL = 1325.0; //950
    const double MAX_Y_RPM = 600.0;
    const double MAX_ROT_VEL_ACTUAL = 50.0; //35
    const double MAX_YAW_RATE = (MAX_ROT_VEL_ACTUAL / MAX_Y_RPM_ACTUAL) * MAX_Y_RPM; //scale down from actual rot vel

    const double UNITS_PER_ROT = 4096.0;
    const double MINUTE_CONVERSION = 600.0; //100 ms to min




	DriveController();
	void Drive(frc::Joystick *joyThrottle);
	// void DriveTest(Joystick *joyThrottle, Joystick *joyWheel);

};

#endif /* DRIVECONTROLLER_H_ */