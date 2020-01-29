#include "main.h"

//initialize variables
double targAngle;
double refAngle;


//Helper Functions
//find the reference angle closest to given angle
double findRefAngle(double targAngle) {
  //does not account for angles not within the unit circle
  //determine which quadrant the angle is in
  if(targAngle < PI / 2 && targAngle > 0) { //quad 1: between 0 and PI/2
    refAngle = targAngle;
    return refAngle;
  }
  else if(targAngle > PI / 2 && targAngle < PI) { //quad 2: between PI/2 and PI
    refAngle = PI - targAngle;
    return refAngle;
  }
  else if(targAngle > PI && targAngle < (3 * PI) / 2) { //quad 3: between PI and 3PI/2
    refAngle = targAngle - PI;
    return refAngle;
  }
  else if(targAngle > (3 * PI) / 2 && targAngle < 2 * PI) { //quad 4: between 3PI/2 and 2PI
    refAngle = (2 * PI) - targAngle;
    return refAngle;
  }
}

//find the nearest equivilent reference angle in rotational units
double nearestEquivAngle(double targAngle) {
  findRefAngle(targAngle);
  double coterminalAngle = ((refAngle - targAngle) / 2 * PI) * (2 * PI) + targAngle;
  return coterminalAngle;
}
