#include "main.h"

//Helpers
//Check if button is pressed
void limitSwitchPressed();

//void setLift(int goalHeight);
void setLift(int rightLiftMotorPower, int leftLiftMotorPower);
int getEncoderValues_lift();
void liftGoTo(int target, int liftRightEncoder, int liftLeftEncoder);
void liftToGoal();
void changeCounter();
//float giveLiftValues();
int giveCounterValue();

//Controls
void setLiftMotors();
void setAutoLift();
