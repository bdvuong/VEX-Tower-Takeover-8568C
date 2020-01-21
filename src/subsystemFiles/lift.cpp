#include "main.h"

//Global Variables
int liftRightEncoder = liftRight.get_position(); //initialize the lift's right motor encoder value
int liftLeftEncoder = liftLeft.get_position(); //initialize the lift's left motor encoder value
const int liftMax = 2500; //the lifts maximum height
const int liftMin = -liftMax;

//Helpers
void setLift(int leftLiftPower, int rightliftPower) {
  // liftRight = rightliftPower;
  // liftLeft = leftliftPower;

}
//Attempts to keep the lift even if it does fall out of alignment
void adjustLift(){
  int voltage = 0 ;
  if(liftLeftEncoder > liftRightEncoder){
    int error = liftLeftEncoder - liftRightEncoder;
    setLift(127 - error);
  }
  if(liftRightEncoder > liftLeftEncoder){
    int error = liftRightEncoder - liftLeftEncoder;
  }
}

//CONTROL FUNCTIONS
void setLiftMotors() {
  // lower is R2, want it to out outtake
  // Upper is R1, want it to intake
  int liftPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
  while(liftPower != 0){
    adjustLift();
  }
}


/*
make a p only PID loop, use something somehow


*/
