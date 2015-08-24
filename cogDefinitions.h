#ifndef COG_DEFINITIONS_HEADER
#define COG_DEFINITIONS_HEADER

#include "effectors.h"

void NO_PROGRAM(){}

void cog1Program(){
  while(1){
    serviceCollisionDetector();
    serviceReedSwitch();
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
     
#define COG_0_PROGRAM testProgram
#define COG_0_STACK_SIZE 15
#define COG_0_DEBUG_STACK_SIZE 70
int COG_0_STATE = 0;

#define COG_1_PROGRAM NO_PROGRAM
#define COG_1_STACK_SIZE 5
#define COG_1_DEBUG_STACK_SIZE 5
int COG_1_STATE = 0;

#define COG_2_PROGRAM NO_PROGRAM
#define COG_2_STACK_SIZE 0
#define COG_2_DEBUG_STACK_SIZE 0
int COG_2_STATE = 0;

#define COG_3_PROGRAM NO_PROGRAM
#define COG_3_STACK_SIZE 0
#define COG_3_DEBUG_STACK_SIZE 0
int COG_3_STATE = 0;

#define COG_4_PROGRAM NO_PROGRAM
#define COG_4_STACK_SIZE 0
#define COG_4_DEBUG_STACK_SIZE 0
int COG_4_STATE = 0;

#define COG_5_PROGRAM NO_PROGRAM
#define COG_5_STACK_SIZE 0
#define COG_5_DEBUG_STACK_SIZE 0
int COG_5_STATE = 0;


#define COG_6_PROGRAM NO_PROGRAM
#define COG_6_STACK_SIZE 0
#define COG_6_DEBUG_STACK_SIZE 0
int COG_6_STATE = 0;

#define COG_7_PROGRAM NO_PROGRAM
#define COG_7_STACK_SIZE 0
#define COG_7_DEBUG_STACK_SIZE 0
int COG_7_STATE = 0;



#endif
