// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
  cs::UsbCamera camera = frc::CameraServer::GetInstance()->StartAutomaticCapture("TapeCamera", 0);

  camera.SetResolution(320, 190);
  camera.SetExposureManual(0);
	camera.SetBrightness(100);
}

void Robot::RobotPeriodic() { }

void Robot::AutonomousInit() { }

void Robot::AutonomousPeriodic() { }

void Robot::TeleopInit() {

  controller = new frc::Joystick(0);

  shooter = new Shooter();
  barrel = new Barrel();
  tsm = new TeleopStateMachine(shooter, controller, barrel);
  drive_controller = new DriveController();

}

void Robot::TeleopPeriodic() {

  tsm->StateMachine();
  drive_controller->Drive(controller);

}

void Robot::DisabledInit() { }

void Robot::DisabledPeriodic() { }

void Robot::TestInit() { }

void Robot::TestPeriodic() { }

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
