#include "simpletools.h"                      // Include simple tools
#include "debuggingCog.h"
#include "sensors.h"
#include "cogDefinitions.h"


int * cog0 = NULL;
int * cog1 = NULL;
int * cog2 = NULL;
int * cog3 = NULL;
int * cog4 = NULL;
int * cog5 = NULL;
int * cog6 = NULL;
int * cog7 = NULL;

int main(){ 
  // Main loop runs COG_7_PROGRAM
  
  if(COG_0_PROGRAM != NO_PROGRAM){
    cog0 = cog_run(&COG_0_PROGRAM,COG_0_STACK_SIZE);
  }
  
  if(COG_1_PROGRAM != NO_PROGRAM){
    cog1 = cog_run(&COG_1_PROGRAM,COG_1_STACK_SIZE);
  }
  
  if(COG_2_PROGRAM != NO_PROGRAM){
    cog2 = cog_run(&COG_2_PROGRAM,COG_2_STACK_SIZE);
  }
  
  if(COG_3_PROGRAM != NO_PROGRAM){
    cog3 = cog_run(&COG_3_PROGRAM,COG_3_STACK_SIZE);
  }
  
  if(COG_4_PROGRAM != NO_PROGRAM){
    cog4 = cog_run(&COG_4_PROGRAM,COG_4_STACK_SIZE);
  }
  
  if(COG_5_PROGRAM != NO_PROGRAM){
    cog5 = cog_run(&COG_5_PROGRAM,COG_5_STACK_SIZE);
  }
  
  if(COG_6_PROGRAM != NO_PROGRAM){
    cog6 = cog_run(&COG_6_PROGRAM,COG_6_STACK_SIZE);
  }
  
  if(COG_7_PROGRAM != NO_PROGRAM){
    COG_7_PROGRAM();
  }                 
}  