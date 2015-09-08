#ifndef EFFECTORS__UTILS_HEADER
#define EFFECTORS_UTILS_HEADER

#include "simpletools.h"
#include "structs.h"








void startEffectorHandlerLoop(volatile unsigned int * sensorTriggerMap);
void defaultEffectorService(int state, int * pins, int pinsLength);
int validEffector(unsigned int sensorPin);
void togglePins(unsigned int sensors[], unsigned int sensorsLength,unsigned int onTimeMs, unsigned int offTimeMs);

#endif