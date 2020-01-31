#include "main.h"

extern const int MAX_CHUTE_ANGLE;
extern const double CHUTE_LENGTH; // measure chute
extern const double CHUTE_SLOPE_RATIO;
//Helpers
void setTilt(int intakePower);
void setIntake(int intakePower);

//Controls
void setTiltMotor();
void setIntakeMotors();

//Auton Functions
void spinIntake();
