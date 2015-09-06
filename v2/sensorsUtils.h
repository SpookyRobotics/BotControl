#ifndef SENSORS_UTILS_HEADER
#define SENSORS_UTILS_HEADER

#include "simpletools.h"

#define SENSOR_LIST_SIZE 0
#define SENSOR_PINS_SIZE 8

typedef struct {
  char name[12];
  int pinNumber;
  unsigned int (*serviceRoutine)();
  unsigned int sensorMapBit;
  
} Sensor;

extern volatile unsigned int SENSOR_TRIGGER_MAP;
extern Sensor SENSOR_LIST[SENSOR_LIST_SIZE];
extern int SENSOR_PINS[SENSOR_PINS_SIZE];

void startSensorHandlerLoop(volatile unsigned int * sensorTriggerMap);
unsigned int debouncePinRead(unsigned int pinToRead);
unsigned int validSensor(unsigned int sensorPin);
unsigned int sensorTriggered(Sensor sensor);
unsigned int sensorReset(Sensor sensor);
unsigned int debounceReadInput();

#endif