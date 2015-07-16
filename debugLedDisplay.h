#ifndef DEBUG_LED_DISPLAY_HEADER
#define DEBUG_LED_DISPLAY_HEADER
void displayOnLeds(unsigned int cogToDisplay);
void displayHexDigit(int bit0Led, char hexDigit);
void clearLeds();
void displayCogBeingQueried(unsigned int cogToDisplay);
void displayCogState(int cogToDisplay);
void turnLedOn(int led) ;
void turnLedOff(int led) ;
int getLedPort(int led);
#endif

