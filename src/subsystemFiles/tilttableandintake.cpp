#include "main.h"

const double CHUTE_LENGTH = 50; // measure chute
const double CHUTE_SLOPE_RATIO = 0;
const int MAX_CHUTE_ANGLE = 3000;

int tiltEncoder = tiltTable.get_position();

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
  // Upper is R1, want it to
<<<<<<< HEAD
  //sgiveTiltPosition();
  //while(tiltEncoder != MAX_CHUTE_ANGLE || tiltEncoder < MAX_CHUTE_ANGLE) {
=======
  giveTiltPosition();
  while(tiltEncoder != MAX_CHUTE_ANGLE || tiltEncoder < MAX_CHUTE_ANGLE) {
>>>>>>> a7ff9c6c8cf5862402a00763fcebae5712d4b1c5
    int tiltPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN));
    setTilt(tiltPower);
  //}
  //while(tiltEncoder >= MAX_CHUTE_ANGLE){
    //setTilt(0);
  }
<<<<<<< HEAD
//}
=======
  while(tiltEncoder >= MAX_CHUTE_ANGLE){
    setTilt(0);
  }
}
>>>>>>> a7ff9c6c8cf5862402a00763fcebae5712d4b1c5

//intake control
void setIntakeMotors() {
  // lower is L2, want it to out outtake
  // Upper is L1, want it to intake
  int intakePower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
  setIntake(intakePower);
}

//Autonomous Functions

void tiltToAngle(int targetAngle) {
  double Kp = .1;
  while(tiltTable.get_position() < abs(targetAngle)) {
    int error = targetAngle - tiltEncoder;
    int direction = abs(error) / error;
    double power = Kp * direction * error;
    setTilt(power);
  }
}

void spinIntake(){
  setIntake(127);
}
