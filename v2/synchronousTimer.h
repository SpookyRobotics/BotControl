#ifndef SYNCRONIZED_TIMER_HEADER
#define SYNCRONIZED_TIMER_HEADER
#include "simpletools.h"

#define TIMER_COG_SLOTS 2
#define TIMER_COG_OFFSET_TICKS 10

typedef struct {
  unsigned int startCount;
  char repeat;
  void (*timedFunction)();
} TimedFunctionEntry;


extern TimedFunctionEntry TIMER_COG_FUNCTIONS[TIMER_COG_SLOTS];
void timerCogProgram();

#endif