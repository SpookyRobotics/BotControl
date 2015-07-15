/*
Platform: P8X32A QuickStart 
Depending on a selected touch input, read the processor state 
of the corresponding cog and display its state on the LEDs
*/
#include "simpletools.h"    
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
  
int getLedPort(int led){
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
    debugPrint("Invalid led: %u\n",led);
    return -1;  
  }    
}

void turnLedOn(int led) {
  int pinNumber = getLedPort(led);
  if(pinNumber != -1){
    debugPrint("setting high %u\n",pinNumber);
    high(pinNumber);
  }
}
  
void turnLedOff(int led) {
  int pinNumber = getLedPort(led);
  if(pinNumber != -1){
    debugPrint("setting low %u\n",pinNumber);
    low(pinNumber);
  }
}

// Leds are indexed with MSB = 0
void displayCogBeingQueried(unsigned int cogToDisplay){
  switch(cogToDisplay){
  case 0:
    turnLedOn(3);
    break;
  case 1:
    turnLedOn(2);
    break;
  case 2:
    turnLedOn(3);
    turnLedOn(2);
    break;
  case 3:
    turnLedOn(1);
    break;
  case 4:
    turnLedOn(3);
    turnLedOn(1);
    break;
  case 5:
    turnLedOn(2);
    turnLedOn(1);
    break;
  case 6:
    turnLedOn(3);
    turnLedOn(2);
    turnLedOn(1);
    break;
  case 7:
    turnLedOn(0);
    break;
  }     
}  
void displayOnLeds(unsigned int cogToDisplay){
  if(cogToDisplay <0 || cogToDisplay > 7){
    debugPrint("No valid cog to display on leds",0);
    return;
  }
  displayCogBeingQueried(cogToDisplay);    
  displayCogState(cogToDisplay);        
}

void displayHexDigit(int bit0Led, char hexDigit){
  hexDigit &= 0xF;
  switch(hexDigit){
    case 0:
      break;
    case 1:
      turnLedOn(bit0Led);
      break;
    case 2:
      turnLedOn(bit0Led-1);
      break;
    case 3:
      turnLedOn(bit0Led);
      turnLedOn(bit0Led-1);
      break;
    case 4:
      turnLedOn(bit0Led-2);
      break;
    case 5:
      turnLedOn(bit0Led);
      turnLedOn(bit0Led-2);
      break;
    case 6:
      turnLedOn(bit0Led-1);
      turnLedOn(bit0Led-2);
      break;
    case 7:
      turnLedOn(bit0Led);
      turnLedOn(bit0Led-1);
      turnLedOn(bit0Led-2);
      break;
    case 8:
      turnLedOn(bit0Led-3);
      break;
    case 9:
      turnLedOn(bit0Led);
      turnLedOn(bit0Led-3);
      break;
    case 10:
      turnLedOn(bit0Led-1);
      turnLedOn(bit0Led-3);
      break;
    case 11:
      turnLedOn(bit0Led);
      turnLedOn(bit0Led-1);
      turnLedOn(bit0Led-3);
      break;
    case 12:
      turnLedOn(bit0Led-2);
      turnLedOn(bit0Led-3);
      break;
    case 13:
      turnLedOn(bit0Led);
      turnLedOn(bit0Led-2);
      turnLedOn(bit0Led-3);
      break;
    case 14:
      turnLedOn(bit0Led-1);
      turnLedOn(bit0Led-2);
      turnLedOn(bit0Led-3);
      break;
    case 15:
      turnLedOn(bit0Led);
      turnLedOn(bit0Led-1);
      turnLedOn(bit0Led-2);
      turnLedOn(bit0Led-3);
      break;
    default:
      debugPrint("Error in displayHexDigit",0); 
    }      
}  
void displayCogState(int cogToDisplay){
  displayHexDigit(7,cogToDisplay+7);
}    

void clearLeds(){
  for(int led=0; led<8; led++){
    turnLedOff(led);
  }
}
      
void readTouchButtons(unsigned int * states){
  *states = INA;      
}  

void handleInputs(unsigned int * states){
  for(int index =0; index < 8; index++){
    unsigned int pin = (*states >> index) & 1;  
    if(pin == 1){
      displayOnLeds(index);
      pause(2000);
      clearLeds();
      return;
    }
  }    
  
}  
  
