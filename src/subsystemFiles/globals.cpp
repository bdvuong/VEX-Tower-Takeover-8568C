#include "main.h"

//Verify gear set, maybe change ports
pros::Motor driveRight(10, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS); //torque motors
pros::Motor driveLeft(9, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS); //torque motors
pros::Motor liftRight(1, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS); //torque motors
pros::Motor liftLeft(2, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS); //torque motors
pros::Motor intakeRight(3, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS); //standard gear ratio
pros::Motor intakeLeft(4, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS); //standard gear ratio
pros::Motor tiltTable(8, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS); //torque motors

//Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

//Sensors
pros::ADIEncoder trackingH('A', 'B');
pros::ADIEncoder trackingRight('C', 'D');
pros::ADIEncoder trackingLeft('G', 'H');

//driver macros

//this macro makes the bot move backwards slowly and pushes the stack outwards
void dumpCubes() {
  int buttonA = controller.get_digital(pros::E_CONTROLLER_DIGITAL_A);
  if (buttonA == 1) {
    setDrive(-25, -25);
    setIntake(30);
  }
}

//misc

float giveTiltPosition(){
  float position = tiltTable.get_position();
  pros::lcd::print(2, "position %f", position);
  return position;
}

const float INCHESTOTICKS = 1800/(4*3.14159);
