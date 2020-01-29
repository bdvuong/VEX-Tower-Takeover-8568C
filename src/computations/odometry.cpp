#include "main.h"

//global variables

position currPosition;
polarCoord polarCoords;
rectCoord rectCoords;

      //////////////////////////////////////////////
      //                                          //
      //        varibles only for odometry        //
      //                                          //
      //////////////////////////////////////////////

//current position of tracking wheels
double positionL; //left wheel
double positionR; //right wheel
double positionH; //horizontal wheel

//initial position of tracking wheels, should be zero
double initL = 0.0;
double initR = 0.0;
double initH = 0.0;

//position of tracking wheels in the previous loop
double lastLeftPosition;
double lastRightPosition;
double lastHorizontalPosition;

//angle things
double angle;
double deltaTheta;
double lastAngle;
double thetaM;
double initAngle = 0.0;

//change in position of tracking wheels since last cycle
double deltaLeft;
double deltaRight;
double deltaHorizontal;
double deltaHorizontaltest;

//total change in position of the tracking wheels since last reset
double deltaLr = 0;
double deltaRr = 0;

//change of coordinate position
double deltaX;
double deltaY;

//Polar coordinates
double theta = 0;
double radius = 0;



//Helper functions
polarCoord rectToPolar(double x, double y) {
  polarCoord polarCoord;
  polarCoord.radius = sqrt(x*x + y*y);
  polarCoord.angle = atan2(y, x);
  return polarCoord;
}

rectCoord polarToRect(double radius, double angle) {
  rectCoord rectCoord;
  rectCoord.x = radius * acos(angle);
  rectCoord.y = radius * asin(angle);
  return rectCoord;
}

void updatePosition() {
  //step 1: Update tracking wheels, converted to inches
  positionL = trackingLeft.get_value() * TRACKING_TICK_INCH;
  positionR = trackingRight.get_value() * TRACKING_TICK_INCH;
  positionH = trackingH.get_value() * TRACKING_TICK_INCH;

  //step 2: calculate the change in the encoders' value since the last cycle
  deltaLeft = (positionL - lastLeftPosition);
  deltaRight = (positionR - lastRightPosition);
  deltaHorizontal = (positionH - lastHorizontalPosition);

  //step 3: update the previous values of the encoders
  lastLeftPosition = positionL;
  lastRightPosition = positionR;
  lastHorizontalPosition = positionH;

  //step 4: calculate the total change in the encoder values since the last reset
   deltaLr = (positionL - initL);
   deltaRr = (positionR - initR);

   //step 5: find the change in angle
   angle = initAngle + (deltaLr - deltaRr) / (LTRACKING_CENTER + RTRACKING_CENTER);

   //step 6: calculate the change in angle
   deltaTheta = angle - lastAngle;
   deltaHorizontaltest = deltaHorizontal - HTRACKING_CENTER * deltaTheta;

   //step 7: if the change in angle is 0, calculate the local offset
   if (deltaTheta == 0) {
     deltaX = deltaHorizontal;
     deltaY = deltaRight;
   }
   //step 8: otherwise calulate the local offset
   else {
     deltaX = (2*sin(deltaTheta / 2)) * (deltaHorizontal / deltaTheta + HTRACKING_CENTER);
     deltaY = (2*sin(deltaTheta / 2)) * (deltaHorizontal / deltaTheta + RTRACKING_CENTER);
   }

   //step 9: calculate the average orientation
   thetaM = angle + deltaTheta/2;

   //step 10: calculate the global offset by converting existing Cartesian/rectangular coordinates to polar coordinates, changing the angle then converting back
   theta = atan2f(deltaY, deltaX); //finds the angle
   radius = sqrt(deltaX * deltaX + deltaY * deltaY); // finds the radius
   //change the angle
   theta = theta - thetaM;
   //convert back to Cartesian/rectangular
   deltaX = radius * cos(theta);
   deltaY = radius * sin(theta);

   //lastAngle += PI;
   //while(lastAngle <= 0) {
  //   lastAngle += 2*PI;
  // }
  // lastAngle = modulo(lastAngle, 2 * PI);
  // lastAngle -= PI;

   //step 11: update final positions
   lastAngle = angle;

   currPosition.xPosition = currPosition.xPosition + deltaX;
   currPosition.yPosition = currPosition.yPosition + deltaY;
}

double getX() {
  return currPosition.xPosition;
}

double getY() {
  return currPosition.yPosition;
}

double getAngleDegrees() {
  //finds a coterminal angle 
  currPosition.angle += PI;
  while(currPosition.angle < 0) {
    currPosition.angle += 2*PI;
  }
  currPosition.angle = modulo(currPosition.angle, 2*PI);
  currPosition.angle -= PI;
  return currPosition.angle*180/PI;
}

double getAngleRad() {
  return currPosition.angle;g
}

double modulo(double a, double b) {
  while(a > b) {
    a -= b;
  }
  return a;
}
