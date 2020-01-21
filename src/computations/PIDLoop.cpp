#include "main.h"

float error;
float integral = 0;
float derivative;
float prevError = 0;
const int intergralMax = 25;

///

int PIDLoop(double Kp, double Ki, double Kd, int units, double EncoderValue) {

  int voltage;

  //set the error
  error = units - EncoderValue;
  pros::lcd::print(0, "error: %f, %f, %f", error, units, EncoderValue);

  //increase the intergral dependin
  integral = integral + error;

  if(error == 0)
    integral = 0;

  if(fabs(error) >= intergralMax)
    integral = 0;

  derivative = prevError - error;
  prevError = error;

  voltage = (Kp * error) + (Ki * integral) + (Kd * derivative);

  if(voltage > 127)
    voltage = 127;

  if(voltage < -127)
    voltage = -127;

  return voltage;
}
