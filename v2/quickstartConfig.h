#ifndef QUICKSTART_CONFIG_HEADER
#define QUICKSTART_CONFIG_HEADER
#include "sensorsUtils.h"
#include "effectorsUtils.h"
#include "structs.h"
/***********************
 * Begin Effector layout
 ***********************/
#define LED0 23
#define LED1 22
#define LED2 21
#define LED3 20
#define LED4 19
#define LED5 18
#define LED6 17
#define LED7 16

extern Effector leds;
void serviceDebugLeds(unsigned int);
void serviceLeds(unsigned int effectorMap);


/***********************
 * Begin Sensor layout
 ***********************/
#define TOUCH0 7
#define TOUCH1 6
#define TOUCH2 5
#define TOUCH3 4
#define TOUCH4 3
#define TOUCH5 2
#define TOUCH6 1
#define TOUCH7 0

extern Sensor touch0;
extern Sensor touch1;
extern Sensor touch2;
extern Sensor touch3;
extern Sensor touch4;
extern Sensor touch5;
extern Sensor touch6;
extern Sensor touch7;

void blinkLed1();
void blinkLed0();
unsigned int serviceTouch0();
unsigned int serviceTouch1();
unsigned int serviceTouch2();
unsigned int serviceTouch3();
unsigned int serviceTouch4();
unsigned int serviceTouch5();
unsigned int serviceTouch6();
unsigned int serviceTouch7();

void quickstartSensorsInit();
void quickstartEffectorsInit();
/**
 * Begin Synchronized timer functions 
 */

void quickstartInitSynchronizedTimerFunctions();


#endif