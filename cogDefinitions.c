#include "cogDefinitions.h"
#include "effectors.h"
#include "sensors.h"

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

void cog1Program(){
  unsigned int triggerMapUpdate = 0;
  while(1){
    triggerMapUpdate = SENSOR_TRIGGER_MAP;
    triggerMapUpdate |= serviceCollisionDetector();
    triggerMapUpdate |= serviceReedSwitch();
    SENSOR_TRIGGER_MAP = triggerMapUpdate;
  }    
}
  
// Control all non Motor output
void cog2Program(){
  unsigned int triggerMap = 0;
  unsigned int lastSeenTriggerMap = 0;
  while(1){
    triggerMap = SENSOR_TRIGGER_MAP;
    if(triggerMap > 0 && triggerMap != lastSeenTriggerMap){
      
    }
    lastSeenTriggerMap = triggerMap;      
  }    
}

// Control left and right motors
void cog3Program(){} 
void cog4Program(){}
void cog5Program(){}
void cog6Program(){}



