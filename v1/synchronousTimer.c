#include "synchronousTimer.h"
#include "simpletools.h"

TimedFunctionEntry TIMER_COG_FUNCTIONS[TIMER_COG_SLOTS];
void timerCogProgram(){
  initSynchronizedTimerFunctions();
  int functionCounts[TIMER_COG_SLOTS];
  for(int index =0; index < TIMER_COG_SLOTS; index++){
    functionCounts[index] = TIMER_COG_FUNCTIONS[index].startCount;
  }    
  while(1){
    for(int index =0; index < TIMER_COG_SLOTS; index++){      
      functionCounts[index] -= 1;        

      if(functionCounts[index] == 0){
        TimedFunctionEntry timedFunctionEntry = TIMER_COG_FUNCTIONS[index];
        timedFunctionEntry.timedFunction();  
        if(timedFunctionEntry.repeat){
            functionCounts[index] = timedFunctionEntry.startCount;
        }
      }         
    }   
    pause(TIMER_COG_OFFSET_TICKS);
  }    
}
