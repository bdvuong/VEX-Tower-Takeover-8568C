// #include "main.h"
//
// //global variables
//
//       //////////////////////////////////////////////
//       //                                          //
//       //        varibles only for odometry        //
//       //                                          //
//       //////////////////////////////////////////////
//
// float positionL = 0; //distance from tracking center, to middle of left tracking wheel
// float positionR = 0; //distance from tracking center, to middle of right tracking wheel
// float positionH = 0; //distance from tracking center, to middle of horizontal tracking wheel
//
// float wheelDiameter = 0; //diameter of side tracking wheels
// float trackingDiameter = 0; //diameter of the sideways tracking wheel
//
//
//
// float x = 0;
// float y = 0;
// float angle = 0;
//
// float lastLeftPosition = 0;
// float lastRightPosition = 0;
// float lastHorizontalPosition = 0;
//
// float deltaTheta = 0;
// float thetaNew = 0;
// float thetaM = 0;
//
//
//
// float curLeft = 0;
// float curRight = 0;
// float curHorizontal = 0;
//
// float leftAtReset = 0;
// float rightAtReset = 0;
// float thetaReset = 0;
//
// float deltaLeft = 0;
// float deltaRight = 0;
// float deltaHorizontal = 0;
//
// float deltaLr = 0;
// float deltaRr = 0;
//
// float deltaX = 0;
// float deltaY = 0;
//
//
// float theta = 0;
// float radius = 0;
//
// void updatePosition() {
//   //step 1: Update tracking wheels, convert to inches
//   curLeft = trackingLeft.get_value();
//   curRight = trackingRight.get_value();
//   curHorizontal = trackingH.get_value();
//
//   deltaLeft = (curLeft - lastLeftPosition) * (PI / 180) * (wheelDiameter / 2);
//   deltaRight = (curRight - lastRightPosition) * (PI / 180) * (wheelDiameter / 2);
//   deltaHorizontal = (curHorizontal - lastHorizontalPosition) * (PI / 180) * (wheelDiameter / 2);
//
//   lastLeftPosition = curLeft;
//   lastRightPosition = curRight;
//   lastHorizontalPosition = curHorizontal;
//
//    deltaLr = (curLeft - leftAtReset) * (PI / 180) * (wheelDiameter / 2);
//    deltaRr = (curRight - rightAtReset) * (PI / 180) * (wheelDiameter / 2);
//
//    thetaNew = (thetaReset + (deltaLr - deltaRr) / (positionL + positionR));
//
//    deltaTheta = thetaNew - angle;
//
//    deltaHorizontal = deltaHorizontal - positionH * deltaTheta;
//
//    if (deltaTheta == 0) {
//      deltaX = deltaHorizontal;
//      deltaY = deltaRight;
//    }
//    else {
//      deltaX = (2*sin(deltaTheta / 2)) * (deltaHorizontal / deltaTheta + positionH);
//      deltaY = (2*(deltaTheta / 2)) * (deltaHorizontal / deltaTheta + positionR);
//    }
//
//    thetaM = angle + deltaTheta/2;
//
//    theta = atan2f(deltaY, deltaX);
//    radius = sqrt(deltaX * deltaX + deltaY * deltaY);
//    theta = theta - thetaM;
//    deltaX = radius * cos(theta);
//    deltaY = radius * sin(theta);
//
//    thetaNew += PI;
//    while(thetaNew <= 0) {
//      thetaNew += 2*PI;
//    }
//    thetaNew = modulo(thetaNew, 2*PI);
//    thetaNew -= PI;
//
//    angle = thetaNew;
//    x = x - deltaX;
//    y = y + deltaY;
// }
//
// float getX() {
//   return x;
// }
//
// float getY() {
//   return y;
// }
//
// float getAngleDegrees() {
//   return angle * 180 / PI;
// }
//
// float getAngle() {
//   return angle;
// }
//
// float modulo(float a, float b) {
//   while(a > b) {
//     a -= b;
//   }
//   return a;
// }
