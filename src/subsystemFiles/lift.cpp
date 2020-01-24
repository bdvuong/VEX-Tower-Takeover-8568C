#include "main.h"
using namespace okapi;

//Global Variables
int liftRightEncoder = liftRight.get_position(); //initialize the lift's right motor encoder value
int liftLeftEncoder = liftLeft.get_position(); //initialize the lift's left motor encoder value
int goalHeight = 0;

const int NUM_HEIGHTS = 4;
int baseHeight = 0;
int smallTower = ;
int medTower = ;
int tallTower = ;




//Helpers

//Sets lift motor power
void setLiftMotors(int rightLiftMotorPower, int leftLiftMotorPower){
  liftRight = rightLiftMotorPower;
  liftLeft = leftLiftMotorPower;
}


void liftGoTo(int target, int liftRightEncoder, int liftLeftEncoder) {
  // int avgLiftEncoder = (liftRightEncoder + liftLeftEncoder) / 2;
  double kP = .5;
  int rightError = target - liftRightEncoder;
  int leftError = target - liftLeftEncoder;
  int encoderError = liftRightEncoder - liftLeftEncoder;
  while(liftRightEncoder < target && liftLeftEncoder < target) {
    setLiftMotors((rightError - encoderError) * kP, (leftError + encoderError) * kP);
  }
}


void setLift(int goalHeight) {
  switch(goalHeight) {
    case 1: {
      liftGoTo(baseHeight, liftRightEncoder, liftLeftEncoder);
    }
    case 2:{
      int target = ;
      liftGoTo(smallTower, liftRightEncoder, liftLeftEncoder);
    }
    case 3:{
      int target = ;
      liftGoTo(medTower, liftRightEncoder, liftLeftEncoder);
    }
    case 4: {
      int target = ;
      liftGoTo(tallTower, liftRightEncoder, liftLeftEncoder);
    }
  }
}
//Can maybe replace this case with a vector?(I think? It would look something like towerHeights = {not extended, tower1, tower2, tower3})





void changeCounter() {
  if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1) && goalHeight < NUM_HEIGHTS - 1) {
    goalHeight++;
    setLift(goalHeight);
  }
  else if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2) && goalHeight > 0) {
    goalHeight--;
    setLift(goalHeight);
  }

}





// //CONTROL FUNCTIONS
// void setLiftMotors() {
  //   // lower is R2, want it to out outtake
  //   // Upper is R1, want it to intake
  //   int liftPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
  //   while(liftPower != 0){
    //     adjustLift();
    //   }
    // }
