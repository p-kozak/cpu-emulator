#ifndef PROGRAMCOUNTER
#define PROGRAMCOUNTER

#include "config.h"
#include "stdint.h"

class ProgramCounter{
    private:
    int counter;
    
    public:
    ProgramCounter();
    void incrementCounter();
    void incrementCounter(int32_t i);
    void setCounter(int32_t index);
    int checkCounter();
};

#endif