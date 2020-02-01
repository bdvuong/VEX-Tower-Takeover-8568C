#include "main.h"

//global variables
bool targetReached;
//Initialize motor encoder values
int driveRightEncoder = driveRight.get_position();
int driveLeftEncoder = driveLeft.get_position();

trackingEncoderValues driveEncoders;

//HELPERS
void setDrive(int left, int right) {
  driveRight = right;
  driveLeft = left;
}

void resetEncoderValues() {
  trackingRight.reset();
  trackingLeft.reset();
  trackingH.reset();
}

/*
void resetDriveEncoders() {
  driveLeft.tare_position();
  driveRight.tare_position();
}
*/

double avgDriveEncoderValue() {
  return (fabs(driveRightEncoder + fabs(driveLeftEncoder))) / 2;
}

//DRIVER CONTROL FUNCTIONS

// //TANK CONTROL
// void setDriveMotors() {
//   int leftJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
//   int rightJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
//   if(abs(leftJoystick) < 10)
//     leftJoystick = 0;
//   if(abs(rightJoystick) < 10)
//     rightJoystick = 0;
//   setDrive(leftJoystick, rightJoystick);
// }

//ARCADE CONTROL
void setDriveMotors() {
  int yAxis = (controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
  int xAxis = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
  if(abs(yAxis) < 10)
    yAxis = 0;
  if(abs(xAxis) < 10)
    xAxis = 0;
  int leftPower = yAxis + xAxis;
  int rightPower =  yAxis - xAxis;
  setDrive(leftPower, rightPower);
}


//Auton Functions
void translate(int targetPosition) { //set target in inches
  //initialize voltage
  int voltage;
  // defines direction based on provided units
  int direction = abs(targetPosition) / targetPosition;
  //reset motor encoders
  resetEncoderValues();
  //convert inches to ticks
  int units = INCHES_TICKS * targetPosition;
  //compare the average of the encoders to the desired units, then drive forward until units are reached
  //while(avgDriveEncoderValue() < abs(units)) {
  //encoder difference
  int encoderDiff = driveLeftEncoder - driveRightEncoder;
  int encoderModifier = direction * encoderDiff * units * .1;

  voltage = PIDLoop(.1, 0, 0, units, driveLeftEncoder);
  driveRight.move_absolute(units, voltage * direction);
  driveLeft.move_absolute(units, voltage * direction);
    //setDrive(voltage * direction, voltage * direction);
  pros::delay(10);
  //}
  //brief brake
  setDrive(-10 * direction, -10 * direction);
  pros::delay(50);
  //set drive back to neutral
  setDrive(0, 0);
}

//funtion to turn the bot on a point, want to eventually figure out how to turn and drive at the same time
void rotate(int targetAngle) {
  int voltage;
  int direction = abs(targetAngle) / targetAngle; // turning left will give a positive number, turning right will give a negative
  int radius = 6 * INCHES_TICKS;
  double angleRAD = targetAngle * DEG_TO_RAD;
  double target = radius * angleRAD;
  resetEncoderValues();
  //if reseting position this will initiate a rotation from the current orientation of the robot
  //while(abs(driveLeftEncoder) < fabs(target)) {
  voltage = PIDLoop(.1, 0, 0, target, driveLeftEncoder);
  driveLeft.move_absolute(target, voltage * direction);
  driveRight.move_absolute(target, -voltage * direction);
  //setDrive(voltage * direction, -voltage * direction);
  pros::delay(10);
  //}
  setDrive(-10 * direction, -10 * direction);
  pros::delay(50);
  //set drive back to neutral
  setDrive(0, 0);
}
