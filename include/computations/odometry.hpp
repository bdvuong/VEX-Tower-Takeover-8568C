#include "main.h"

typedef struct position {
double xPosition;
double yPosition;
double angle;
} position;

typedef struct rectCoord {
double x;
double y;
} rectCoord;

typedef struct polarCoord {
double radius;
double angle;
} polarCoord;

void updatePosition();
double getX();
double getY();
double getAngleDegrees();
double getAngle();
