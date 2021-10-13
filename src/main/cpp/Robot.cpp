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
}

void Robot::RobotPeriodic() { }

void Robot::AutonomousInit() { }

void Robot::AutonomousPeriodic() { }

void Robot::TeleopInit() {

  controller = new frc::Joystick(0);

  shooter = new Shooter();
  tsm = new TeleopStateMachine(shooter, controller);

}

void Robot::TeleopPeriodic() {

  tsm->StateMachine();

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
