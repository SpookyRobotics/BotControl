#include "simpletools.h"
#include "cogDefinitions.h"
#include "effectors.h"
#include "sensors.h"
#include <string.h>

int COG_0_STATE = 0;
int COG_1_STATE = 0;
int COG_2_STATE = 0;
int COG_3_STATE = 0;
int COG_4_STATE = 0;
int COG_5_STATE = 0;
int COG_6_STATE = 0;
int COG_7_STATE = 0;

void NO_PROGRAM(){}

// Timer Cog for synchronous output 
void cog0Program(){
  high(17);
  pause(100);
  low(17);
  pause(100);
}

typedef struct {
  unsigned int count;
  unsigned int startCount;
  char repeat;
  void (*timedFunction)();
} TimedFunctionEntry;
  
TimedFunctionEntry TIMER_COG_FUNCTIONS[TIMER_COG_SLOTS];
void timerCogProgram(){
  while(1){
    for(int index =0; index < TIMER_COG_SLOTS; index++){
      TimedFunctionEntry timedFunctionEntry = TIMER_COG_FUNCTIONS[index];
      if(timedFunctionEntry.count >= 0){
        timedFunctionEntry.count -= 1;
        if(timedFunctionEntry.count == 0){
          timedFunctionEntry.timedFunction();  
          if(timedFunctionEntry.repeat){
            timedFunctionEntry.count = timedFunctionEntry.startCount;
          }
        }
      }        
    }      
    pause(TIMER_COG_OFFSET_TICKS);
  }    
}  
// Read the sensors and update the SENSOR_TRIGGER_MAP
// to inform other cogs of a change in the environment
void cog1Program(){
  unsigned int triggerMapUpdate = 0;
  SENSOR_TRIGGER_MAP = 0;
  sensorsInit();   
  while(1){
    triggerMapUpdate = 0;
    for(int index = 0; index < SENSOR_LIST_SIZE; index++){
      triggerMapUpdate |= SENSOR_LIST[index].serviceRoutine(); 
    }
    SENSOR_TRIGGER_MAP = triggerMapUpdate;
  }    
}
  
// Control all non Motor output
void cog2Program(){
  unsigned int triggerMap = 0;
  effectorsInit();
  while(1){
    triggerMap = SENSOR_TRIGGER_MAP;
    for(int index=0; index < EFFECTOR_LIST_SIZE; index++){
        EFFECTOR_LIST[index].serviceRoutine(triggerMap);
    }
  }    
}

// Control left and right motors
void cog3Program(){
  static int state = 0;
  if(state == 1){
    state = 0;
    high(1);
  }
  else{
    state = 1;
    low(1);
  }
  pause(100);
} 
void cog4Program(){}
void cog5Program(){}
void cog6Program(){}
void cog7Program(){}




