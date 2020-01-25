#include "main.h"

//MOTORS
extern pros::Motor liftRight;
extern pros::Motor liftLeft;
extern pros::Motor intakeRight;
extern pros::Motor intakeLeft;
extern pros::Motor driveRight;
extern pros::Motor driveLeft;
extern pros::Motor tiltTable;

//CONTROLLER
extern pros::Controller controller;

//Sensors
extern pros::ADIEncoder trackingH;
extern pros::ADIEncoder trackingLeft;
extern pros::ADIEncoder trackingRight;

//driver macros
void dumpCubes();

//MISC
float giveangle();
extern const float INCHESTOTICKS;

//Conversion
  #define TICKS_PER_REV_TORQUE = 1800
  #define DEG_CIRCLE = 360.0
  #define PI = 3.14159
  #define TICKS_DEG_TORQUE = DEG_CIRCLE / TICKS_PER_REV_TORQUE
  #define DEG_TO_TICKS = TICKS_PER_REV_TORQUE / DEG_CIRCLE
