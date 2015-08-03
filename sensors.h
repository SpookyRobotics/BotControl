#ifndef SENSORS_HEADER
#define SENSORS_HEADER

#define BLUE_LED 0
#define GREEN_LED 1
#define WHITE_LED 2
#define RED_LED 3
#define RED_LASER 4
#define MAGNETIC_REED 5
#define COLLISION_DETECTOR 6
#define SPEAKER 7
#define SERVO1 8

void serviceCollisionDetector();
void serviceReedSwitch();
void spinMotor();
#endif