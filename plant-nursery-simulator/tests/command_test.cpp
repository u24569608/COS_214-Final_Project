#include "PlantCommand.h"
#include "WaterPlant.h"
#include "FertilizePlant.h"
#include "PlantInstance.h"

#include <type_traits>
#include <iostream>
#include <string>

static int failures = 0;

void ASSERT_TRUE(bool expr, const char* msg) {
    if (expr == false) {
        std::cerr << "[ASSERT_TRUE FAILED] " << msg << std::endl;
        failures = failures + 1;
    }
}

void ASSERT_EQ_INT(int a, int b, const char* msg) {
    if (a == b) { 
        return; 
    }
    std::cerr << "[ASSERT_EQ_INT FAILED] " << msg
              << " (expected " << b << ", got " << a << ")" << std::endl;
    failures = failures + 1;
}


static_assert(std::is_base_of<PlantCommand, WaterPlant>::value,
              "WaterPlant must derive from PlantCommand");
static_assert(std::is_base_of<PlantCommand, FertilizePlant>::value,
              "FertilizePlant must derive from PlantCommand");
static_assert(std::is_member_function_pointer<decltype(&PlantCommand::handleRequest)>::value,
              "PlantCommand::handleRequest must exist");


int main() {
    // 1) Null receiver safety — should not crash
    {
        WaterPlant waterNull(nullptr);
        FertilizePlant fertNull(nullptr);

        waterNull.handleRequest();   // allowed to print a warning
        fertNull.handleRequest();    // allowed to print a warning
        ASSERT_TRUE(true, "Null receiver commands executed without crashing.");
    }

    // 2) Non-null receiver path — just construct and call
    {
        // Use the default PlantInstance constructor as defined in your PlantInstance.h
        PlantInstance plant(nullptr);

        WaterPlant waterCmd(&plant);
        FertilizePlant fertCmd(&plant);

        waterCmd.handleRequest();
        fertCmd.handleRequest();

        ASSERT_TRUE(true, "Non-null receiver commands executed without crashing.");
    }

    if (failures == 0) {
        std::cout << "[PASS] All command unit tests passed." << std::endl;
        return 0;
    } else {
        std::cerr << "[FAIL] " << failures << " test(s) failed." << std::endl;
        return 1;
    }
}