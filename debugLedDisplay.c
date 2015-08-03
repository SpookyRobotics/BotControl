#include "debugLedDisplay.h"
#include "debuggingCog.h"
#include "simpletools.h"
#include <stdarg.h>

/**
 * Debug functions that depend on the QuickStart platform setup of leds.
 */
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

void clearLeds(){
  for(int led=0; led<8; led++){
    turnLedOff(led);
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

extern int COG_0_STATE;
extern int COG_1_STATE;
extern int COG_2_STATE;
extern int COG_3_STATE;
extern int COG_4_STATE;
extern int COG_5_STATE;
extern int COG_6_STATE;
extern int COG_7_STATE;

void displayCogState(int cogToDisplay){
  int cogState = 0;
  switch(cogToDisplay){
    case 0:
       cogState = COG_0_STATE;
       break;
    case 1:
       cogState = COG_1_STATE;
       break;
    case 2:
       cogState = COG_2_STATE;
       break;
    case 3:
       cogState = COG_3_STATE;
       break;
    case 4:
       cogState = COG_4_STATE;
       break;
    case 5:
       cogState = COG_5_STATE;
       break;
    case 6:
       cogState = COG_6_STATE;
       break;
    case 7:
       cogState = COG_7_STATE;
       break;
    
  }    
  displayHexDigit(7,cogState);
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

