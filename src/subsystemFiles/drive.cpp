#include "main.h"
#include "math.h"

//Initialize encoder values
int driveRightEncoder = driveRight.get_position();
int driveLeftEncoder = driveLeft.get_position();

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
void translate(int inches) {
  //initialize voltage
  int voltage;
  // defines direction based on provided units
  int direction = abs(inches) / inches;
  //reset motor encoders
  resetDriveEncoders();
  //convert inches to ticks
  int units = INCHES_TO_TICKS * inches;
  //drive forward until units are reached
  while(avgDriveEncoderValue() < abs(units)) {
    //encoder difference
    int encoderDiff = driveLeftEncoder - driveRightEncoder;
    int encoderModifier =

    PIDLoop(0, 0, 0, units, driveLeftEncoder)

    setDrive(voltage * direction, voltage * direction);
    pros::delay(10);
  }
  //brief brake
   setDrive(-10 * direction, -10 * direction);
   pros::delay(50);
  //set drive back to neutral
  setDrive(0, 0);
}


//translate function to move robot a set amount of inches, with a built in pid
// void translate(int dist) {
//   //reset the motor encoders
//   resetDriveEncoders();
//   int driveLastError = 0;
//
//   int direction = abs(dist) / dist;
//
//   int target = fabs(dist * INCHES_TO_TICKS); //convert distance to encoder ticks
//   float error = target - abs(driveLeftEncoder);
//
//   while(fabs(error) > 0) {
//
//     error = target - abs(driveLeftEncoder);
//
//     int drivePower =
//   }
//
// }
//
// void turn(int angle, int voltage) {
//   int direction = abs(angle) / angle; // left will give a negative number, right will give a positive
//   double power = angle * TICKS_PER_REV_TORQUE;
//
// }
