#include "main.h"

//HELPERS
void setDrive(int left, int right);
//void resetDriveEncoders();
void resetEncoderValues(); 
double avgDriveEncoderValue();

//DRIVER CONTROL FUNCTIONS
void setDriveMotors();

//Auton
void translate(int inches);
void turn(int angle, int voltage);
