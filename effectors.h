#ifndef EFFECTORS_HEADER
#define EFFECTORS_HEADER

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

int validEffector(unsigned int sensorPin);
void togglePins(unsigned int sensors[], unsigned int sensorsLength,unsigned int onTimeMs, unsigned int offTimeMs);

#endif