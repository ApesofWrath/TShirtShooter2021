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

	target_l = 0 * MAX_Y_RPM;
	target_r = 0 * MAX_Y_RPM;

    /*
	current_l = (canTalonFrontLeft->GetSensorCollection().GetQuadratureVelocity() / UNITS_PER_ROT) * MINUTE_CONVERSION;
	current_r = (canTalonFrontRight->GetSensorCollection().GetQuadratureVelocity() / UNITS_PER_ROT) * MINUTE_CONVERSION; //right is negative for forward
   
	error_l = target_l - current_l;
	error_r = target_r + current_r;
    */

	target_yaw_rate = 1.0 * (0) * MAX_YAW_RATE; //left should be positive
	
    /*
    yaw_rate_current = 1.0 * (double) ahrs->GetRawGyroZ()
			* (double) ((PI) / 180);
	yaw_error = target_yaw_rate - yaw_rate_current;
    */
	
    target_l = target_l - (target_yaw_rate * (MAX_Y_RPM / MAX_YAW_RATE)); //linear velocities for each side, controlling inputs
	target_r = target_r + (target_yaw_rate * (MAX_Y_RPM / MAX_YAW_RATE));

    /*
	d_yaw = yaw_error - yaw_last_error;
	yaw_output = (k_p_yaw * yaw_error) + (k_d_yaw * d_yaw);

	target_l = target_l - yaw_output; //after using yaw controller
	target_r = target_r + yaw_output;

	P_l = Kp_d * error_l;
	P_r = Kp_d * error_r;

	i_l += error_l;
	i_r += error_r;

	I_l = Ki_d * i_l;
	I_r = Ki_d * i_r;

	d_r = (error_r - last_error_r);
	d_l = (error_l - last_error_l);

	D_l = Kd_d * d_l;
	D_r = Kd_d * d_r;
    */

	output_l = (Kf_d * target_l); // P_l + I_l + D_l + 
	output_r = (Kf_d * target_r); // P_r + I_r + D_r +

	canTalonFrontLeft->Set(ControlMode::PercentOutput, -output_l); //backs are slaved to fronts
	canTalonFrontRight->Set(ControlMode::PercentOutput, output_r);

    /*
	last_error_l = error_l;
	last_error_r = error_r;
	yaw_last_error = yaw_error;
    */
}