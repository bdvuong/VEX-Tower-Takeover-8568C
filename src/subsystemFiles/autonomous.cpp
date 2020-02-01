#include "main.h"

void extendChute(int position){
  pros::lcd::print(3, "tilt angle %f", tiltTable.get_position());
  if(tiltTable.get_position() < position){
      setTilt(62);
  }
  else if(tiltTable.get_position() > position){
    setTilt(0);
    setIntake(127);
    pros::delay(200);

      }

  else
  {
    setTilt(0);
  }
}

void redAlliance() {
  extendChute(2150);
  setIntake(127);
  pros::delay(500);
  translate(5);
  translate(-5);
  //translate(10);

}
