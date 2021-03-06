#include "simpletools.h"
#include "effectors.h"
#include "sensors.h"
#include "cogDefinitions.h"
#include "testFunctions.h"
#include "breadboardConfig.h"

Sensor DEBUG_SENSOR1 = {"MAG_REED",MAGNETIC_REED, &debugSensor1,0};
Sensor DEBUG_SENSOR2 = {"COL_DETECT",COLLISION_DETECTOR, &debugSensor2,1};

TimedFunctionEntry blinkLed = {3,1,&blinkLed1};
TimedFunctionEntry blinkLed2 = {3,1,&blinkLed0};


  
unsigned int debugSensor1(){
  unsigned int result = debounceReadInput(); 
  if(result & (1 << 7)){
     high(23);
  }
  if(result & (1 << 6)){
    high(22);
  }
  pause(100);
  low(23);low(22);
  pause(100);         
}

unsigned int debugSensor2(){
   return 0;  
}

void testComm1(){
  while(1){
    SENSOR_TRIGGER_MAP += 1;
    if(SENSOR_TRIGGER_MAP == 1000){
      SENSOR_TRIGGER_MAP = 0;
    }
  }          
}  

void testComm2(){
  unsigned int triggerMap = 0;
  unsigned int lastSeenTriggerMap = 0;
  while(1){
    triggerMap = SENSOR_TRIGGER_MAP;
    if(triggerMap > 0 && triggerMap != lastSeenTriggerMap){
      high(16);
      pause(200);
      low(16);
      pause(100);
    }
    lastSeenTriggerMap = triggerMap;      
  }  
}  

void testServo(){
  int SERVO = 20;
  unsigned int count = 0;
  unsigned int clockSpeed = 12;
  unsigned int highTime = 10800;
  for(int index = 0; index < 120000; index++){
    if(index % 2 == 0){
      high(WHITE_LED);
      pause(100);
      low(WHITE_LED);
      pause(100);
    }      
    if(count < highTime){
      high(SERVO);
    }
    else{
      low(SERVO);
    }
    count += 1;
  }      
}
  
void testProgram(){
  int leds[] = { BLUE_LED,GREEN_LED, WHITE_LED, RED_LED};
  int debugLeds[] = { DEBUG_LED_1, DEBUG_LED_2,DEBUG_LED_3,DEBUG_LED_4,DEBUG_LED_5,
                      DEBUG_LED_6,DEBUG_LED_7,DEBUG_LED_8,DEBUG_LED_9,DEBUG_LED_10};
  int debugLedsLength = 10;
  int ledLength = 4;
  high(RED_LASER);
  for(int index=0; index < 40; index++){
    high(index % ledLength);
    for(int index2 = 0; index2 < index%debugLedsLength; index2++){
      high(debugLeds[index2]);
    }      
    pause(100);
    low(index % ledLength);
    for(int index2 = 0; index2 < index%debugLedsLength; index2++){
      low(debugLeds[index2]);
    }       
    pause(100);
  }
  
  for(int index = 0; index < 48000; index++){
    if(index % 2 == 0){
      high(SPEAKER);
    }
    else{
      low(SPEAKER);
    }
  }    
  
  for(int index = 0; index < 48000; index++){
    if(input(MAGNETIC_REED) == 0){
      high(BLUE_LED);
    }
    else{
      low(BLUE_LED);
    }                    
    if(input(COLLISION_DETECTOR) == 0){
      high(WHITE_LED);
    }
    else{
      low(WHITE_LED);
    }  
  }
  low(RED_LASER);
}

void blinkLed1(){
  static int state = 0;
  if(state){
    state = 0;
    high(23);
  }
  else{
    state = 1;
    low(23);
  }        
}  

void blinkLed0(){
  static int state = 0;
  if(state){
    state = 0;
    high(22);
  }
  else{
    state = 1;
    low(22);
  }        
}
