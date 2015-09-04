#ifndef TEST_FUNCTIONS_HEADER
#define TEST_FUNCTIONS_HEADER

#include "synchronousTimer.h"

extern Sensor DEBUG_SENSOR1;
extern Sensor DEBUG_SENSOR2;
unsigned int debugSensor1();
unsigned int debugSensor2();
void testComm1();
void testComm2();
void testServo();
void testProgram();

/* Synchronized timer functions */
extern TimedFunctionEntry blinkLed;
extern TimedFunctionEntry blinkLed2;

void blinkLed1();
void blinkLed0();
#endif