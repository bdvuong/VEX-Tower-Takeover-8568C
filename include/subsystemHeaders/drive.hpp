#include "main.h"

//HELPERS
void setdrive(int left, int right);
void resetDriveEncoders();
double avgdriveencoderValue();

//DRIVER CONTROL FUNCTIONS
void setDriveMotors();

//Auton
void translate(int units, int voltage);
