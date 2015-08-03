#ifndef EFFECTORS_HEADER
#define EFFECTORS_HEADER

#define BLUE_LED 0
#define GREEN_LED 1
#define WHITE_LED 2
#define RED_LED 3
#define RED_LASER 4

#define SPEAKER 7
#define SERVO1 8

int validEffector(unsigned int sensorPin);
void togglePins(unsigned int sensors[], unsigned int sensorsLength,unsigned int onTimeMs, unsigned int offTimeMs);

#endif