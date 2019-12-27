#include "main.h"

//Helpers
void setTilt(int tiltPower) {
  tiltTable = tiltPower;
}

//CONTROL FUNCTIONS
void setTiltMotor() {
  // lower is R2, want it to out outtake
  // Upper is R1, want it to intake
  int tiltPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN));
  setTilt(tiltPower);

}
