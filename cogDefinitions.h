#ifndef COG_DEFINITIONS_HEADER
#define COG_DEFINITIONS_HEADER

#include "config.h"

#define COG_0_PROGRAM cog0Program
#define COG_0_STACK_SIZE 200
#define COG_0_DEBUG_STACK_SIZE 70
extern int COG_0_STATE;

#define COG_1_PROGRAM NO_PROGRAM
#define COG_1_STACK_SIZE 200
#define COG_1_DEBUG_STACK_SIZE 5
extern int COG_1_STATE;

#define COG_2_PROGRAM NO_PROGRAM
#define COG_2_STACK_SIZE 200
#define COG_2_DEBUG_STACK_SIZE 0
extern int COG_2_STATE;

#define COG_3_PROGRAM NO_PROGRAM
#define COG_3_STACK_SIZE 0
#define COG_3_DEBUG_STACK_SIZE 0
extern int COG_3_STATE;

#define COG_4_PROGRAM NO_PROGRAM
#define COG_4_STACK_SIZE 0
#define COG_4_DEBUG_STACK_SIZE 0
extern int COG_4_STATE;

#define COG_5_PROGRAM NO_PROGRAM
#define COG_5_STACK_SIZE 0
#define COG_5_DEBUG_STACK_SIZE 0
extern int COG_5_STATE;

#define COG_6_PROGRAM NO_PROGRAM
#define COG_6_STACK_SIZE 0
#define COG_6_DEBUG_STACK_SIZE 0
extern int COG_6_STATE;

#define COG_7_PROGRAM NO_PROGRAM
#define COG_7_STACK_SIZE 0
#define COG_7_DEBUG_STACK_SIZE 0
extern int COG_7_STATE;


extern volatile unsigned int SENSOR_TRIGGER_MAP;
void NO_PROGRAM();
void cog0Program();
void cog1Program();  
void cog2Program();
void cog3Program(); 
void cog4Program();
void cog5Program();
void cog6Program();
void cog7Program();
void timerCogProgram();


#endif
