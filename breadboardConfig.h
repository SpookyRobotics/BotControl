#ifndef BREADBOARD_CONFIG_HEADER
#define BREADBOARD_CONFIG_HEADER

#include "sensors.h"
#include "effectors.h"

/***********************
 * Begin Effector layout
 ***********************/
#define BLUE_LED 0
#define GREEN_LED 1
#define WHITE_LED 2
#define RED_LED 3
#define RED_LASER 4
#define SPEAKER 7
#define SERVO1 8
#define DEBUG_LED_1 10
#define DEBUG_LED_2 11
#define DEBUG_LED_3 12
#define DEBUG_LED_4 13
#define DEBUG_LED_5 14
#define DEBUG_LED_6 15
#define DEBUG_LED_7 19
#define DEBUG_LED_8 18
#define DEBUG_LED_9 17
#define DEBUG_LED_10 16




extern Effector BlueLed;
extern Effector GreenLed;
extern Effector WhiteLed;
extern Effector RedLed;
extern Effector RedLaser;
extern Effector Speaker;
extern Effector DebugLeds;

void serviceBlueLed(unsigned int);
void serviceGreenLed(unsigned int);
void serviceWhiteLed(unsigned int);
void serviceRedLed(unsigned int);
void serviceRedLaser(unsigned int);
void serviceSpeaker(unsigned int);
void serviceDebugLeds(unsigned int);

/**********************
 * Begin Sensor Layout
 * ********************/

#define MAGNETIC_REED 5
#define COLLISION_DETECTOR 6
#define DEBUG_SENSOR 200


extern Sensor MAGNETIC_REED_SENSOR; 
extern Sensor COLLISION_DETECTOR_SENSOR;
unsigned int serviceCollisionDetector();
unsigned int serviceReedSwitch();

#endif
