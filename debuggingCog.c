/*
Platform: P8X32A QuickStart 
Depending on a selected touch input, read the processor state 
of the corresponding cog and display its state on the LEDs
*/
#include "simpletools.h"    
#include "debugLedDisplay.h"
#define DEBUG 0                


void debugPrint(char* string , int num, ...){
  va_list valist;
  if(DEBUG == 0){
    return;
  }    
  
  /* initialize valist for num number of arguments */
  va_start(valist, num);
  
  print(string,valist);
  /* clean memory reserved for valist */
  va_end(valist);
}


      
void readTouchButtons(unsigned int * states){
  *states = INA;      
}  

void handleInputs(unsigned int * states){
  for(int index =0; index < 8; index++){
    unsigned int pin = (*states >> index) & 1;  
    if(pin == 1){
      displayOnLeds(index);
      pause(4000);
      clearLeds();
      return;
    }
  }    
  
}  

void debuggingCogMain(){
  unsigned int displayingCog = 0;
  unsigned int directions;
  unsigned int states;
  
  set_directions(0x7,0x0,0x0);
  debugPrint("Pin Directions %d\n",get_directions(0x7,0x0));
  
  while(1){
    readTouchButtons(&states);
    handleInputs(&states); 
  }  
}
  
