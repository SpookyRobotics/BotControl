#include "sensors.h"

// Flash white led when collision is about to detected
void serviceCollisionDetector(){
  int value = input(COLLISION_DETECTOR);
  if(value == 0){
    for(int index = 0; index < 15; index++){
      high(WHITE_LED);
      pause(10);
      low(WHITE_LED);
      pause(10);
    }      
  }    
}  
void serviceReedSwitch(){
  int value = input(MAGNETIC_REED);
  if(value == 0){
    for(int index = 0; index < 15; index++){
      high(SPEAKER);
      pause(10);
      low(SPEAKER);
      pause(10);
    }      
  }    
}  

void spinMotor(){
  static rotateFreq = 10;
  for(int index = 0; index < 15; index++){
    high(SPEAKER);
    pause(rotateFreq);
    low(SPEAKER);
    pause(rotateFreq);
    if(rotateFreq < 100){
      rotateFreq += 20;
    }
    else {
      rotateFreq = 10;
    }            
  }    
}  
