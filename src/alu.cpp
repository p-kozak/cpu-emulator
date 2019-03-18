#include "alu.h"

Alu::Alu(){
    
}

int32_t Alu::add(int32_t x, int32_t y){
    return x + y;
}

int32_t Alu::sub(int32_t x, int32_t y){
    return x - y;
}

int32_t Alu::mul(int32_t x, int32_t y){
    return x * y;
}

bool geq(int32_t x, int32_t y){
    return x>=y;
}