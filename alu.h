#ifndef ALU
#define ALU

#include "config.h"
#include <stdint.h>

class Alu{
    public:
    Alu();
    uint32_t add(uint32_t first, uint32_t second);
    uint32_t sub(uint32_t first, uint32_t second);
};

#endif 