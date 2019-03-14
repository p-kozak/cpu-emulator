#ifndef PROGRAMCOUNTER
#define PROGRAMCOUNTER

#include "config.h"

class ProgramCounter{
    private:
    int counter;
    
    public:
    ProgramCounter();
    void incrementCounter();
    void setCounter(int index);
    int checkCounter();
};

#endif