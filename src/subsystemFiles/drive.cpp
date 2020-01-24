#include "main.h"

//HELPERS
void setDrive(int left, int right) {
  driveRight = right;
  driveLeft = left;
}

void resetDriveEncoders() {
  driveLeft.tare_position();
  driveRight.tare_position();
}

double avgDriveEncoderValue() {
  return (fabs(driveLeft.get_position()) + fabs(driveRight.get_position())) / 2;
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
  int leftJoystick = (controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
  int rightJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
  if(abs(leftJoystick) < 10)
    leftJoystick = 0;
  if(abs(rightJoystick) < 10)
    rightJoystick = 0;
  int leftPower = leftJoystick + rightJoystick;
  int rightPower =  leftJoystick - rightJoystick;
  setDrive(leftPower, rightPower);
}


//Auton Functions
void translate(int units, int voltage) {
  // defines direction based on provided units
  int direction = abs(units) / units;
  //reset motor encoders
  resetDriveEncoders();
  //drive forward until units are reached
  while(avgDriveEncoderValue() < abs(units)) {
    setDrive(voltage * direction, voltage * direction);
    pros::delay(10);
  }
  //brief brake
   setDrive(-10 * direction, -10 * direction);
   pros::delay(50);
  //set drive back to neutral
  setDrive(0, 0);
}
