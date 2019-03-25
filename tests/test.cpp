#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/cpu.h"


TEST_CASE("CPU"){
    Cpu cpu;
    SECTION("2's complement"){
        REQUIRE(cpu.instructionDecodeAddiNumber(3545) == 3545);
        REQUIRE(cpu.instructionDecodeAddiNumber(0xFFFFFFF1) == -15);
        REQUIRE(cpu.instructionDecodeAddiNumber(0xFFFFFE56)==-426);
    }
    SECTION("ADDI"){
        int32_t ins     = 0b00001000000000100000000000001001; //addi to reg0 from reg1 add 9
        int32_t ins2    = 0b00001000100000000000000000001111;  //aadi to reg2 from teg0 add 15
        int32_t ins3    = 0b00001000110010001111111111101100; //addi to reg 3 from reg4 add -20 

        cpu.instructionExecute(ins);
        cpu.instructionExecute(ins2);
        cpu.instructionExecute(ins3);
        REQUIRE(cpu.registers.readRegister(0) == 9);
        REQUIRE(cpu.registers.readRegister(2) == 24);
        REQUIRE(cpu.registers.readRegister(3) == -20);
    }

    SECTION("ADD"){
        //First, let's save 9 in reg 0 and 15 in reg 1 using ADDI
        int32_t ins = 0b00001000000000000000000000001001;
        int32_t ins2 = 0b00001000010000100000000000001111;
        cpu.instructionExecute(ins);
        cpu.instructionExecute(ins2);
        //Check if right value is in register
        REQUIRE(cpu.registers.readRegister(0) == 9);
        REQUIRE(cpu.registers.readRegister(1) == 15);
        //Now, add value of reg 0 and 1 and store in reg 2
        int32_t ins3 = 0b00000000100000000001000000000000;
        cpu.instructionExecute(ins3);
        REQUIRE(cpu.registers.readRegister(2) == 24);
    }

    SECTION("SUB"){
        //First, let's save 9 in reg 0 and 15 in reg 1 using ADDI
        int32_t ins =  0b00001000000000000000000000001001;
        int32_t ins2 = 0b00001000010000100000000000001111;
        cpu.instructionExecute(ins);
        cpu.instructionExecute(ins2);
        //Check if right value is in register
        REQUIRE(cpu.registers.readRegister(0) == 9);
        REQUIRE(cpu.registers.readRegister(1) == 15);
        //Now, from reg 0 sub reg1, store in reg2 and expect -
        int32_t ins3 = 0b00010000100000000001000000000000;
        cpu.instructionExecute(ins3);
        REQUIRE(cpu.registers.readRegister(2) == -6);
    }

    SECTION("SW"){
        int32_t ins =  0b00001000000000000000000000001001;
        int32_t ins2 = 0b00001000010000100000000000001111;
        cpu.instructionExecute(ins);
        cpu.instructionExecute(ins2);

        //instructions for saving reg0 and reg1 in memory
        int32_t ins3 = 0b00100'00000'0000000000000000000000;
        int32_t ins4 = 0b00100'00001'0000000000000000000001;
        cpu.instructionExecute(ins3);
        cpu.instructionExecute(ins4);

        REQUIRE(cpu.memory.readCell(0) == 9);
        REQUIRE(cpu.memory.readCell(1) == 15);

    }

    SECTION("LW"){
        // USE SW first
        int32_t ins =  0b00001000000000000000000000001001;
        int32_t ins2 = 0b00001000010000100000000000001111;
        cpu.instructionExecute(ins);
        cpu.instructionExecute(ins2);

        //instructions for saving reg0 and reg1 in memory
        int32_t ins3 = 0b00100'00000'0000000000000000000000;
        int32_t ins4 = 0b00100'00001'0000000000000000000001;
        cpu.instructionExecute(ins3);
        cpu.instructionExecute(ins4);

        //instructions from loading from memory cells 0 and 1 to registers 3 and 4
        int32_t ins5 = 0b00011'00011'0000000000000000000000;
        int32_t ins6 = 0b00011'00100'0000000000000000000001;
        cpu.instructionExecute(ins5);
        cpu.instructionExecute(ins6);

        REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15); REQUIRE(cpu.registers.readRegister(3) == 9);
        REQUIRE(cpu.registers.readRegister(4) == 15);
        
    }


    SECTION("BEQ"){
        //reg0 = 2, reg1 = 2, reg2 = 3
        cpu.registers.writeRegister(0,2);
        cpu.registers.writeRegister(1,2);
        cpu.registers.writeRegister(2,3);

        int32_t ins = 0b00101'00000'00001'00000000000000000; //Compare reg0 and reg1, they are equal so pc should be incremented by 2
        cpu.instructionExecute(ins);
        REQUIRE(cpu.pc.checkCounter() == 2);
        
        int32_t ins2 = 0b00101'00000'00010'00000000000000000; //Compare reg0 and reg2, they are not equal so pc should be 3
        cpu.instructionExecute(ins2);
        REQUIRE(cpu.pc.checkCounter() == 3);
    }

    SECTION("JP"){
        int32_t ins = 0b00111'00000'00'0000'0000'0000'0001'0000;
        cpu.instructionExecute(ins);
        REQUIRE(cpu.pc.checkCounter() == 16);
    }

    SECTION("ASM"){
     /*   Assembler asmb;
        asmb.convertAssemblyToMachineCode(cpu.memory);
        for(int i =0; i < 5; i++){
            cout << cpu.memory.readCell(i) << endl;
        }*/
    }

}

