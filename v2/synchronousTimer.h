#ifndef SYNCRONIZED_TIMER_HEADER
#define SYNCRONIZED_TIMER_HEADER
#include "simpletools.h"


typedef struct {
  unsigned int startCount;
  char repeat;
  void (*timedFunction)();
} TimedFunctionEntry;


extern TimedFunctionEntry TIMER_COG_FUNCTIONS[TIMER_COG_SLOTS];
void initSynchronizedTimerFunctions();
void timerCogProgram();

#endif