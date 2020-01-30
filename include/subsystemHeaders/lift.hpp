#include "main.h"

//Helpers
void limitSwitchPressed();
//void setLift(int goalHeight);
void setLift(int rightLiftMotorPower, int leftLiftMotorPower);
void liftGoTo(int target, int liftRightEncoder, int liftLeftEncoder);
void changeCounter();
int getEncoderValues_lift();
float giveLiftValues();

//Controls
void setLiftMotors();
