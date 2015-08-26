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

void cog0Program(){}

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
  unsigned int lastSeenTriggerMap = 0;
  effectorsInit();
  while(1){
    triggerMap = SENSOR_TRIGGER_MAP;
    /*if(triggerMap > 0 && triggerMap != lastSeenTriggerMap){
      // Trigger effectors as desired based on triggerMap
      for(int index=0; index < EFFECTOR_LIST_SIZE; index++){
        EFFECTOR_LIST[index].serviceRoutine(triggerMap);
      }          
    }*/
    for(int index=0; index < EFFECTOR_LIST_SIZE; index++){
        EFFECTOR_LIST[index].serviceRoutine(triggerMap);
    }
    lastSeenTriggerMap = triggerMap;      
  }    
}

// Control left and right motors
void cog3Program(){} 
void cog4Program(){}
void cog5Program(){}
void cog6Program(){}
void cog7Program(){}




