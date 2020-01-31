#include "main.h"

//HELPERS
void setDrive(int left, int right);
//void resetDriveEncoders();
void resetEncoderValues();
double avgDriveEncoderValue();

//structure to hold all values of the tracking wheels
typedef struct trackingEncoderValues {
  double rightEncoder = trackingRight.get_value();
  double leftEncoder = trackingLeft.get_value();
  double horizontalEncoder = trackingH.get_value();
} trackingEncoderValues;

//DRIVER CONTROL FUNCTIONS
void setDriveMotors();

//Auton
void translate(int inches);
void turn(int angle, int voltage);
