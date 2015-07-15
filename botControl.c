#include "simpletools.h"                      // Include simple tools
#include "debuggingCog.h"

int main()                                    
{
  unsigned int displayingCog = 0;
  unsigned int directions;
  unsigned int states;
  
  set_directions(0x7,0x0,0x0);
  debugPrint("Pin Directions %d\n",get_directions(0x7,0x0));
  
  while(1){
    readTouchButtons(&states);
    handleInputs(&states);
    //displayOnLeds(displayingCog,states);
    //displayingCog += 1;
    //sleep(1);  
  }  
}

