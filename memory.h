#ifndef MEMORY
#define MEMORY

#include <vector>
#include <stdint.h>
#include <iostream>


class Memory{
    private:
    std::vector<uint32_t>  memory;

    public:
    void writeCell(int cell, uint32_t content);
    uint32_t readCell(int cell); 
    void pushCell(uint32_t content);

};

#endif 