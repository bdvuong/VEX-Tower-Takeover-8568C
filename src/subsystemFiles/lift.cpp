#include "main.h"

//Global Variables
int liftRightEncoder = liftRight.get_position(); //initialize the lift's right motor encoder value
int liftLeftEncoder = liftLeft.get_position(); //initialize the lift's left motor encoder value
int goalHeight = 1;
int maxHeight = 18000; //set max height lift can go to lower the chances of gears slipping
bool buttonPressed = limitSwitch.get_value();

const int NUM_HEIGHTS = 4;
//all tower heights should be in encoder units
int baseHeight = 0;
float smallTower = 18.83 * INCHES_TICKS;
float medTower = 24.66 * INCHES_TICKS;
float tallTower = 37.91 * INCHES_TICKS;

//Helpers

void limitSwitchPressed() {
  if(buttonPressed == 1) {
    liftLeft.tare_position();
    liftRight.tare_position();
    setLift(0, 0);
  }

}

//Sets lift motor power
void setLift(int rightLiftMotorPower, int leftLiftMotorPower){
  liftRight = rightLiftMotorPower;
  liftLeft = leftLiftMotorPower;
}

int getEncoderValues_lift() {
  int liftRightEncoder = liftRight.get_position();
  int liftLeftEncoder = liftLeft.get_position();
  return liftRightEncoder;
  return liftLeftEncoder;
}

void liftGoTo(int target, int liftRightEncoder, int liftLeftEncoder) {
  //P loop to self correct lift so it doesn't lift inconsistently
  double kP = .5; //arbitrary number, dont think i need this necesarily but idk.
  int avgLiftEncoder;
  int rightError;
  int leftError;
  int encoderError;
  while(true) {
    int avgLiftEncoder = (liftRightEncoder + liftLeftEncoder) / 2;
    int rightError = target - liftRightEncoder;
    int leftError = target - liftLeftEncoder;
    int encoderError = liftRightEncoder - liftLeftEncoder;
    if(liftRightEncoder < target && liftLeftEncoder < target) {
      while(true) {
        setLift((rightError - encoderError) * kP, (leftError + encoderError) * kP);
        //if(avgLiftEncoder == target){
        if(abs(avgLiftEncoder - target) < 10){
          break;
        }
        break;
      }
    }
    else if(liftRightEncoder > target && liftLeftEncoder > target) {
      while(true) {
        setLift((-rightError - encoderError) * kP, (-leftError + encoderError) * kP);
        //if(avgLiftEncoder == target){
          if(abs(avgLiftEncoder - target) < 10){
          break;
        }
        break;
      }
    }
  }
}


void liftToGoal(int goalHeight) {
  printf("in switch function");
  switch(goalHeight) {
    case 1: {
      liftGoTo(baseHeight, liftRightEncoder, liftLeftEncoder);
    }
    case 2:{
      liftGoTo(smallTower, liftRightEncoder, liftLeftEncoder);
    }
    case 3:{
      liftGoTo(medTower, liftRightEncoder, liftLeftEncoder);
    }
    case 4: {
      liftGoTo(tallTower, liftRightEncoder, liftLeftEncoder);
    }
    default: {
      if(goalHeight < 1) {
        goalHeight = 1;
      }
      else if(goalHeight > 4) {
        goalHeight = 4;
      }
    }
  }
}

int giveCounterValue() {
  pros::lcd::print(4, "Counter: %i", goalHeight);
  return goalHeight;
}

//Can maybe replace this case with a vector?(I think? It would look something like towerHeights = {not extended, tower1, tower2, tower3})
void changeCounter() {
  giveCounterValue();
  goalHeight += (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1) - controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2));
  printf("im in the counter");
  liftToGoal(goalHeight);
/*
  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && goalHeight < NUM_HEIGHTS - 1) {
    goalHeight++;
    liftToGoal(goalHeight);
    pros::lcd::print(6, "goalHeight = %i", goalHeight);
  }
  else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && goalHeight > 0) {
    goalHeight--;
    liftToGoal(goalHeight);
    pros::lcd::print(6, "goalHeight = %i", goalHeight);
  }
*/
}


//CONTROL FUNCTIONS
void setLiftMotors() {
    // lower is R2, want it to out outtake
    // Upper is R1, want it to intake
    int liftPower = 62 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
    setLift(liftPower, liftPower);
    //giveLiftValues();
}

/*
void setAutoLift() {
  int counter = counter + (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1) - controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2));
  liftToGoal(counter);
}
*/
