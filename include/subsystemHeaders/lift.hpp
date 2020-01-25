#include "main.h"

//Helpers
void setLift(int goalHeight);
void liftGoTo(int target, int liftRightEncoder, int liftLeftEncoder);
void changeCounter();
int getEncoderValues_lift();
float giveLiftValues();

//Controls
void setLiftMotors();
