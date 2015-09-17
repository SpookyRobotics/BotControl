#ifndef STRUCTS_HEADER_FILE
#define STRUCTS_HEADER_FILE

#include "config.h"

typedef struct {
  char name[12];
  int pinNumbersSize;
  int * pinNumbers;
  void (*serviceRoutine)(unsigned int); 
} Effector;

typedef struct {
  char name[12];
  int pinNumber;
  unsigned int (*serviceRoutine)();
  unsigned int sensorMapBit;
  
} Sensor;

typedef struct {
  char valid;
  unsigned int startEffectorsIndex;
  unsigned int endEffectorsIndex;
  unsigned int startSensorsIndex;
  unsigned int endSensorsIndex;
  unsigned int effectorsMask;
  unsigned int sensorsMask;
} InstructorCommand;

extern volatile unsigned int SENSOR_TRIGGER_MAP;
extern Sensor SENSOR_LIST[SENSOR_LIST_SIZE];
extern int SENSOR_PINS[SENSOR_PINS_SIZE];

extern int EFFECTOR_PINS[];
extern Effector EFFECTOR_LIST[EFFECTOR_LIST_SIZE];

#endif