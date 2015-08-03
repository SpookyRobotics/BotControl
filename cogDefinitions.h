#ifndef COG_DEFINITIONS_HEADER
#define COG_DEFINITIONS_HEADER

void NO_PROGRAM(){}

void cog1Program(){
  while(1){
    serviceCollisionDetector();
    serviceReedSwitch();
  }    
}  

#define COG_0_PROGRAM debuggingCogMain
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
