#ifndef ASMB
#define ASMB

#include "config.h"
#include "memory.h"
#include <fstream>
#include <string>

class Assembler{
    private:
    std::ifstream inFile;
    std::string opcode; 
    public:
    Assembler();
    ~Assembler();
    /*First, assembler has to convert assembly to machine code. When it's complete,
    the another function skims over memory, finds all jump instructions and then looks for a labels and
    replaces indices with addresses*/
    void addAddressesToJumps(Memory &memory);
    void convertAssemblyToMachineCode(Memory &memory);
    int32_t readSingleLine(std::string opcode);
    int32_t readWord();



};

#endif
