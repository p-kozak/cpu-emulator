#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/cpu.h"

TEST_CASE("My Test"){
    Cpu cpu;
    REQUIRE(cpu.instructionDecodeAddiNumber(3545) == 3545);
    REQUIRE(cpu.instructionDecodeAddiNumber(0xFFFFFFF1) == -15);
    REQUIRE(cpu.instructionDecodeAddiNumber(0xFFFFFE56)==-426);

}