#include "../include/CareRequestHandler.h"
#include "../include/WateringHandler.h"
#include "../include/FertilizingHandler.h"
#include "../include/PlantInstance.h"

/**
 * @file chain_of_responsibility_test.cpp
 * @brief Exercises the care request chain-of-responsibility flow with manual tests.
 */
#include <iostream>
#include <string>

static int failures = 0;

void ASSERT_TRUE(bool expr, const char* msg) {
    if (expr == false) {
        std::cerr << "[ASSERT_TRUE FAILED] " << msg << std::endl;
        failures = failures + 1;
    }
}

void ASSERT_FALSE(bool expr, const char* msg) {
    if (expr == true) {
        std::cerr << "[ASSERT_FALSE FAILED] " << msg << std::endl;
        failures = failures + 1;
    }
}

struct TestWateringHandler : public WateringHandler {
    void link(CareRequestHandler* next) { this->nextHandler = next; }
};

int main() {
    // 0) Construct handlers
    TestWateringHandler water;   // test subclass with link()
    FertilizingHandler fert;

    // 1) canHandle() mapping (case-insensitive variants are allowed by our impl)
    ASSERT_TRUE(water.canHandle("water"), "WateringHandler should handle 'water'.");
    ASSERT_TRUE(water.canHandle("WATERING"), "WateringHandler should handle 'WATERING' (case-insensitive).");
    ASSERT_FALSE(water.canHandle("fertilize"), "WateringHandler should NOT handle 'fertilize'.");

    ASSERT_TRUE(fert.canHandle("fertilize"), "FertilizingHandler should handle 'fertilize'.");
    ASSERT_TRUE(fert.canHandle("FERTILIZING"), "FertilizingHandler should handle 'FERTILIZING' (case-insensitive).");
    ASSERT_FALSE(fert.canHandle("water"), "FertilizingHandler should NOT handle 'water'.");

    // 2) Link the chain: Watering -> Fertilizing (using test-only helper)
    water.link(&fert);

    // 3) Build a PlantInstance using the constructor present in your codebase
    PlantInstance plant(nullptr); // matches your constructor that accepts a prototype pointer

    // 4) Route 'water' (handled by first handler)
    water.handleRequest(&plant, "water");

    // 5) Route 'fertilize' (forward from Watering -> Fertilizing)
    water.handleRequest(&plant, "fertilize");

    // 6) Route unknown -> end-of-chain message (should not crash)
    water.handleRequest(&plant, "prune");

    if (failures == 0) {
        std::cout << "[PASS] All Chain of Responsibility UNIT TESTS PASSED." << std::endl;
        return 0;
    } else {
        std::cerr << "[FAIL] " << failures << " test(s) FAILED." << std::endl;
        return 1;
    }
}
