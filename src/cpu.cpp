#include "cpu.h"

using namespace std;
   
Cpu::Cpu(/* args */){
    instruction = 0;
    asmb.convertAssemblyToMachineCode(memory, readProgram());
    //exit(0);
    dbg = 0; insc = 0;
    memory.printMemory();
    asmb.addAddressesToJumps(memory);
    //memory.printMemory();
    //To run units tets, comment this out
    while(1 && dbg < 30){
        //Execute while True. Program should exit automatically at the end
        //Might implement some safety measurement later...
        D DPV("PC is: ", pc.checkCounter());
        instructionExecute(memory.readCell(pc.checkCounter()));

        insc++;
        // cout << registers.readRegister(0) << " "
        // << registers.readRegister(1) << " "
        // << registers.readRegister(2) << endl;
        D registers.printRegisters();
        //dbg++;
    }
    memory.printMemory();
}

Cpu::~Cpu(){

}

std::string Cpu::readProgram(){
    std::string name;
    cout << "Input path to the program:" << endl;
    cin >> name;
    return name;

}

int32_t Cpu::instructionFetch(int index){
    return memory.readCell(index);
}

int32_t Cpu::instructionDecodeOpcode(int32_t instruction){
    //Opcode is first five bits
    // cout << instruction << endl;
    // int32_t a,b,c,d;
    // a = 0b11111 << (32 - 5);
    // b = instruction & (0b11111 << (32 - 5));
    // c = ((instruction & (0b11111 << (32 - 5))) >> (32-5));
    // cout << a << endl << b << c << endl;
    
    return ((instruction & (0b11111 << (32 - 5))) >> (32-5));
}

int32_t Cpu::instructionDecodeFirstRegister(int32_t instruction){
    return ((instruction & (0b11111 << (32 - 10))) >> (32-10));
}

int32_t Cpu::instructionDecodeSecondRegister(int32_t instruction){
    return ((instruction & (0b11111 << (32 - 15))) >> (32-15));
}

int32_t Cpu::instructionDecodeThirdRegister(int32_t instruction){
    return ((instruction & (0b11111 << (32 - 20))) >> (32-20));
}

int32_t Cpu::instructionDecodeMemoryAddress(int32_t instruction){
    //Here we are just going to set the first 10 MS bits to 0 and return the rest
    return (instruction & (0x003FFFFF ));
}

int32_t Cpu::instructionDecodeAddiNumber(int32_t instruction){
    // DONE. Work on this, not complete. return 17 bit's in 2's complement but won't be recognised as such
    // Actually I'm not sure if all this mess is required. Probably I could just cast the instruction to int16_t and work on this...
    // But ir works so I'm fine :)))

    int32_t numBin = (instruction & (0xFFFF));
    int32_t sign  = numBin >> 15; 
    if(sign == 0){
        return numBin;
    }else{
        return -((~numBin & (0x0000FFFF))  + 1);
    }
}


//Instruction execution

void Cpu::instructionExecute(int32_t instruction){
    D DPV("Executing instruction: ", instruction);
    int32_t opcode = instructionDecodeOpcode(instruction);
    //cout << "Opcode " << opcode << endl;
    //not all will be used but I declare  them here to not waste space
    int32_t regTargetAddress, regTargetVal, regSecondAddress, regThirdAddress, memoryAddress, regSecondVal, regThirdVal, memoryVal; 
    switch(opcode){
        case ADD:
            D DP("Instruction ADD");
            regTargetAddress = instructionDecodeFirstRegister(instruction);
            regSecondAddress = instructionDecodeSecondRegister(instruction);
            regThirdAddress = instructionDecodeThirdRegister(instruction);
            regSecondVal = registers.readRegister(regSecondAddress);
            regThirdVal = registers.readRegister(regThirdAddress);
            DA cout << "Executing instruction ADD. Adding reg" <<regSecondAddress<<"(" << regSecondVal <<") to reg" <<regThirdAddress <<"("<<regThirdVal << "). Saving to reg" <<regTargetAddress << "(" << alu.add(regSecondVal, regThirdVal) << ")" << endl;
            registers.writeRegister(regTargetAddress, alu.add(regSecondVal, regThirdVal));
            pc.incrementCounter();
            break;
        case MUL:
            D DP("Instruction MUL");
            regTargetAddress = instructionDecodeFirstRegister(instruction);
            regSecondAddress = instructionDecodeSecondRegister(instruction);
            regThirdAddress = instructionDecodeThirdRegister(instruction);
            regSecondVal = registers.readRegister(regSecondAddress);
            regThirdVal = registers.readRegister(regThirdAddress);
            registers.writeRegister(regTargetAddress, alu.mul(regSecondVal, regThirdVal));
            pc.incrementCounter();
            break;
        case ADDI:
            D DP("Instruction ADDI");
            //Here I am using the rhird register variable just to store the value of ADDI immediate value
            regTargetAddress = instructionDecodeFirstRegister(instruction);
            regSecondAddress = instructionDecodeSecondRegister(instruction);
            regSecondVal = registers.readRegister(regSecondAddress);
            regThirdVal  = instructionDecodeAddiNumber(instruction);
            registers.writeRegister(regTargetAddress, alu.add(regSecondVal, regThirdVal));
            pc.incrementCounter();
            break;
        case SUB:
            D DP("Instruction SUB");
            //Decode addresses of 3 registers
            regTargetAddress = instructionDecodeFirstRegister(instruction);
            regSecondAddress = instructionDecodeSecondRegister(instruction);
            regThirdAddress = instructionDecodeThirdRegister(instruction);
            //Read Values in registers which are no target
            regSecondVal = registers.readRegister(regSecondAddress);
            regThirdVal = registers.readRegister(regThirdAddress);
      
            registers.writeRegister(regTargetAddress, alu.sub(regSecondVal, regThirdVal));
            pc.incrementCounter();
            break;
        case LW:
             D DP("Instruction LW");
            regTargetAddress = instructionDecodeFirstRegister(instruction);
            memoryAddress = instructionDecodeMemoryAddress(instruction);
            memoryVal = memory.readCell(memoryAddress);
            registers.writeRegister(regTargetAddress, memoryVal);
            pc.incrementCounter();
            break;
        case SW:
        D DP("Instruction SW");
            regTargetAddress = instructionDecodeFirstRegister(instruction);
            regTargetVal = registers.readRegister(regTargetAddress);
            memory.pushCell(regTargetVal);
            pc.incrementCounter();
            break;
        case BEQ:
        D DP("Instruction BEQ");
            //retrive two first registers and their vaue
            regTargetAddress = instructionDecodeFirstRegister(instruction);
            regSecondAddress = instructionDecodeSecondRegister(instruction);
            regTargetVal = registers.readRegister(regTargetAddress); 
            regSecondVal = registers.readRegister(regSecondAddress);
            //if branch taken, omit the jump
            if(regTargetVal == regSecondVal){
                pc.incrementCounter(2); 
            }else{
                //otherwise, let the jump happen 
                pc.incrementCounter();
            }
            break;
        case BNE:
        D DP("Instruction BNE");
            //retrive two first registers and their vaue
            regTargetAddress = instructionDecodeFirstRegister(instruction);
            regSecondAddress = instructionDecodeSecondRegister(instruction);
            regTargetVal = registers.readRegister(regTargetAddress); 
            regSecondVal = registers.readRegister(regSecondAddress);
            //if branch taken, omit the jump
            if(regTargetVal != regSecondVal){
                pc.incrementCounter(2); 
            }else{
                //otherwise, let the jump happen 
                pc.incrementCounter();
            }
            break;

        case GEQ:
        D DP("Instruction GEQ");
            //retrive two first registers and their vaue
            regTargetAddress = instructionDecodeFirstRegister(instruction);
            regSecondAddress = instructionDecodeSecondRegister(instruction);
            regTargetVal = registers.readRegister(regTargetAddress); 
            regSecondVal = registers.readRegister(regSecondAddress);
            //if branch taken, omit the jump
            if(regTargetVal >= regSecondVal){
                pc.incrementCounter(2); 
            }else{
                //otherwise, let the jump happen 
                pc.incrementCounter();
            }
            break;

        case LBL:
        D DP("Instruction LBL");
            // just break, nothing to do here
            pc.incrementCounter();
            break;
        case JP:
        D DP("Instruction JP");
            //First, decode memory address. You don't need to decode label number as it was transalted to memory address by assembler
            memoryAddress = instructionDecodeMemoryAddress(instruction);
            pc.setCounter(memoryAddress);
            break;

        case EF:
        D DP("Instruction EF");
            //print memory and exit
            memory.printMemory();
            std::exit(0);
        default:
            cout << "Wrong instruction. Exiting" << endl;
            std::exit(1);

    }
}