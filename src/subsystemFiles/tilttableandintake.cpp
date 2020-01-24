#include "main.h"

const double CHUTE_LENGTH = 50; // measure chute
const double CHUTE_SLOPE_RATIO = 0;
int chuteAngle;


//Helpers
//chute helper
void setTilt(int tiltPower) {
  tiltTable = tiltPower;
}

//intake helper
void setIntake(int intakePower) {
  intakeRight = intakePower;
  intakeLeft = intakePower;

}

//CONTROL FUNCTIONS
//tilt control
void setTiltMotor() {
  // lower is R2, want it to out outtake
  // Upper is R1, want it to intake
  int tiltPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN));
  setTilt(tiltPower);

}

//intake control
void setIntakeMotors() {
  // lower is L2, want it to out outtake
  // Upper is L1, want it to intake
  int intakePower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
  setIntake(intakePower);
}

//Autonomous Functions


void tiltto(){

}
