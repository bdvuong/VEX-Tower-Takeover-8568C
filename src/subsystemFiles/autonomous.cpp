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
  translate(2);

}

void setAutonomousButton() {
  while(controller.get_digital(pros::E_CONTROLLER_DIGITAL_X) == 1) {
    redAlliance();
  }
}
