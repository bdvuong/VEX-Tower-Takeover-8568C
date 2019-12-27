#include "main.h"

//Helpers
void setIntake(int intakePower) {
  intakeRight = intakePower;
  intakeLeft = intakePower;

}

//CONTROL FUNCTIONS
void setIntakeMotors() {
  // lower is L2, want it to out outtake
  // Upper is L1, want it to intake
  int intakePower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
  setIntake(intakePower);
}

// //AUTON FUNCTIONS
// void spinIntakeMotors() {
// 
// }
