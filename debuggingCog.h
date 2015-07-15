#ifndef DEBUGGING_COG_H
#define DEBUGGING_COG_H
void debugPrint(char* string , int num, ...);
void readTouchButtons(unsigned int * states);
void handleInputs(unsigned int * states);

#endif