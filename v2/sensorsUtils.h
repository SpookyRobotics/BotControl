#ifndef SENSORS_UTILS_HEADER
#define SENSORS_UTILS_HEADER

#include "simpletools.h"
#include "structs.h"







void startSensorHandlerLoop(volatile unsigned int * sensorTriggerMap);
unsigned int debouncePinRead(unsigned int pinToRead);
unsigned int validSensor(unsigned int sensorPin);
unsigned int sensorTriggered(Sensor sensor);
unsigned int sensorReset(Sensor sensor);
unsigned int debounceReadInput();

#endif