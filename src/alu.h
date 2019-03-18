#ifndef ALU
#define ALU

#include "config.h"

class Alu{
    public:
    Alu();
    int32_t add(int32_t first, int32_t second);
    int32_t sub(int32_t first, int32_t second);
    int32_t mul(int32_t first, int32_t second); //multiply
    bool geq(int32_t first, int32_t second); //greather equal
};

#endif 