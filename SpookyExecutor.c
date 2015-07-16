/*
Platform: P8X32A QuickStart 
Depending on a selected touch input, read the processor state 
of the corresponding cog and display its state on the LEDs
*/
#include "propeller.h"
#include "cog.h"
#include "simpletext.h"    
#include <stdarg.h>

#define DEBUG 1                  

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
  
int getPort(int led){
  switch(led){
    case 0:
      return 23;
    case 1:
      return 22;
    case 2:
      return 21;
    case 3:
      return 20;
    case 4:
      return 19;
    case 5:
      return 18;
    case 6:
      return 17;
    case 7:
      return 16;
    default:
      debugPrint("Invalid led: %d\n",led);
      return -1;  
  }    
}

void turnLedOn(int led) {
  int pinNumber = getPort(led);
  if(pinNumber != -1){
    debugPrint("setting high %d\n",pinNumber);
    high(pinNumber);
  }
}
  
void turnLedOff(int led) {
  int pinNumber = getPort(led);
  if(pinNumber != -1){
    debugPrint("setting low %d\n",pinNumber);
    low(pinNumber);
  }
}

void readTouchButtons(unsigned int * states){
  *states = get_states(0x7,0x0);
  debugPrint("Pin States %d\n",*states);
}  

  
int main()                                    
{
  unsigned int displayingCog = 0;
  unsigned int directions;
  unsigned int states;
  
  set_directions(0x7,0x0,0x0);
  debugPrint("Pin Directions %d\n",get_directions(0x7,0x0));
  
  while(1){
    readTouchButtons(&states);
    displayOnLeds(displayingCog,states);
    displayingCog += 1;
    sleep(1);  
  }  
}
