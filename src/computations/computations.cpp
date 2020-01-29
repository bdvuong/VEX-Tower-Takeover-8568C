#include "main.h"



double coterminalAngle(double refAngle, double targAngle) {
  double coterminalAngle = ((refAngle - targAngle) / 2 * PI) * (2 * PI) + targAngle;
  return coterminalAngle;
}
