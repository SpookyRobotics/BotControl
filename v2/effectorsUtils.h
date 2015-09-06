#ifndef EFFECTORS__UTILS_HEADER
#define EFFECTORS_UTILS_HEADER

#include "simpletools.h"

#define EFFECTOR_LIST_SIZE 0
#define EFFECTOR_PINS_SIZE 8

typedef struct {
  char name[12];
  int pinNumbersSize;
  int * pinNumbers;
  void (*serviceRoutine)(unsigned int); 
} Effector;


extern int EFFECTOR_PINS[];
extern Effector EFFECTOR_LIST[EFFECTOR_LIST_SIZE];


void startEffectorHandlerLoop(volatile unsigned int * sensorTriggerMap);
void defaultEffectorService(int state, int * pins, int pinsLength);
int validEffector(unsigned int sensorPin);
void togglePins(unsigned int sensors[], unsigned int sensorsLength,unsigned int onTimeMs, unsigned int offTimeMs);

#endif