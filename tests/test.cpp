#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/cpu.h"

TEST_CASE("My Test"){
    Cpu cpu;
    SECTION("2's complement"){
        REQUIRE(cpu.instructionDecodeAddiNumber(3545) == 3545);
        REQUIRE(cpu.instructionDecodeAddiNumber(0xFFFFFFF1) == -15);
        REQUIRE(cpu.instructionDecodeAddiNumber(0xFFFFFE56)==-426);
    }
    SECTION("ADDI"){
        int32_t ins     = 0b00001000000000100000000000001001; //addi to reg0 from reg1 add 9
        int32_t ins2    = 0b00001000100000000000000000001111;  //aadi to reg2 from teg0 add 15
        cpu.instructionExecute(ins);
        cpu.instructionExecute(ins2);
        REQUIRE(cpu.registers.readRegister(0) == 9);
        REQUIRE(cpu.registers.readRegister(2) == 24);
    }
}