#include "DriveController.h"

#define PI 3.14159265

DriveController::DriveController() {

	canTalonFrontLeft = new TalonSRX(CAN_TALON_FRONT_LEFT);
	canTalonBackLeft = new TalonSRX(CAN_TALON_BACK_LEFT);
	canTalonBackLeft->Set(ControlMode::Follower, CAN_TALON_FRONT_LEFT);

	canTalonFrontRight = new TalonSRX(CAN_TALON_FRONT_RIGHT);
	canTalonBackRight = new TalonSRX(CAN_TALON_BACK_RIGHT);
	canTalonBackRight->Set(ControlMode::Follower,CAN_TALON_FRONT_RIGHT);

	// ahrs = new AHRS(SPI::Port::kMXP, 200);

}

void DriveController::Drive(frc::Joystick *joyThrottle) {

	if(joyThrottle->GetPOV() == 0){
			x_input = 0;
			y_input = 1; 
		} else if(joyThrottle->GetPOV() == 45){
			x_input = 1;
			y_input = 1;
		} else if(joyThrottle->GetPOV() == 90){
			x_input = 1;
			y_input = 0;
		} else if(joyThrottle->GetPOV() == 135){
			x_input = 1;
			y_input = -1;
		} else if(joyThrottle->GetPOV() == 180){
			x_input = 0;
			y_input = -1;
		} else if(joyThrottle->GetPOV() == 225){
			x_input = -1;
			y_input = -1;
		} else if(joyThrottle->GetPOV() == 270){
			x_input = -1;
			y_input = 0;
		} else if(joyThrottle->GetPOV() == 315){
			x_input = -1;
			y_input = 1;
		} else{
			x_input = 0;
			y_input = 0;
		}

	canTalonFrontLeft->Set(ControlMode::PercentOutput, x_input);
	canTalonFrontRight->Set(ControlMode::PercentOutput, -y_input);

	}