#ifndef CONFIG
#define CONFIG
/*It's 32 and don't change it, instruction is specified for 32 bits and it's going
to fail otherwise*/
#include <stdint.h>
#include <vector>
#include <stdint.h>
#include <iostream>
#define NUMBER_OF_REGISTERS 32 
#define DEBUG   //comment out to exit debug mode
#ifdef DEBUG
 #define D if(1) 
#else
 #define D if(0) 
#endif
#define DS cout << 
#define DE << endl
#define DP(st) cout << st << endl
#define DPV(st,val) cout << st << val << endl




#endif