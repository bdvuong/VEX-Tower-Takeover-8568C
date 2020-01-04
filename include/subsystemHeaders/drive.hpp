#include "main.h"

//HELPERS
void setDrive(int left, int right);
void resetDriveEncoders();
double avgdriveencoderValue();

//DRIVER CONTROL FUNCTIONS
void setDriveMotors();

//Auton
void translate(int units, int voltage);
