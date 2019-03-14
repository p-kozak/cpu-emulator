#ifndef ALU
#define ALU

#include "config.h"
#include <stdint.h>

class Alu{
    public:
    Alu();
    int32_t add(int32_t first, int32_t second);
    int32_t sub(int32_t first, int32_t second);
    int32_t mul(int32_t first, int32_t second);
};

#endif 