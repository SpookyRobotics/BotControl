#include "simpletools.h"                      // Include simple tools
#include "debuggingCog.h"

int COG_0_STATE = 0;
int COG_1_STATE = 1;
int COG_2_STATE = 2;
int COG_3_STATE = 3;
int COG_4_STATE = 4;
int COG_5_STATE = 5;
int COG_6_STATE = 6;
int COG_7_STATE = 7;

int main(){
  int * debuggingCog = cog_run(&debuggingCogMain,15);
}  