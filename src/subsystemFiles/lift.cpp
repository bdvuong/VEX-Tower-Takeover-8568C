#include "main.h"

//Helpers
void setLift(int liftPower) {
  liftRight = liftPower;
  liftLeft = liftPower;

}

//CONTROL FUNCTIONS
void setLiftMotors() {
  // lower is R2, want it to out outtake
  // Upper is R1, want it to intake
  int liftPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
  setIntake(liftPower);
}


//PID loop to keep lift even
voi
