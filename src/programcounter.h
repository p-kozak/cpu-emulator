#ifndef PROGRAMCOUNTER
#define PROGRAMCOUNTER

#include "config.h"

class ProgramCounter{
    private:
    uint32_t counter;
    
    public:
    ProgramCounter();
    void incrementCounter();
    void incrementCounter(int32_t i);
    void setCounter(int32_t index);
    int checkCounter();
};

#endif
