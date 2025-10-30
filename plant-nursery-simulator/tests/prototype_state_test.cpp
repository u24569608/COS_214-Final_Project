/**
 * @file prototype_state_test.cpp
 * @brief Exercises cloning of plants and their states in the prototype registry.
 */
#include <iostream>
#include <memory>

#include "../include/PlantPrototypeRegistry.h"
#include "../include/PlantInstance.h"
#include "../include/MatureState.h"
#include "../include/Plant.h"

namespace {

class CountingPlant : public Plant {
public:
    CountingPlant() {
        setName("Counting");
    }

    explicit CountingPlant(int* counter) : cloneCounter(counter) {
        setName("Counting");
    }

    Plant* clone() const override {
        if (cloneCounter) {
            ++(*cloneCounter);
        }
        return new CountingPlant(cloneCounter);
    }

    void setCloneCounter(int* counter) {
        cloneCounter = counter;
    }

private:
    mutable int* cloneCounter{nullptr};
};

int failures = 0;

void ASSERT_TRUE(bool expr, const std::string& msg) {
    if (!expr) {
        std::cerr << "[ASSERT_TRUE FAILED] " << msg << std::endl;
        ++failures;
    }
}

void ASSERT_EQ_INT(int actual, int expected, const std::string& msg) {
    if (actual != expected) {
        std::cerr << "[ASSERT_EQ_INT FAILED] " << msg
                  << " (expected " << expected << ", got " << actual << ")" << std::endl;
        ++failures;
    }
}

} // namespace

void testRegistryOwnsPrototype() {
    std::cout << "Running test: testRegistryOwnsPrototype..." << std::endl;
    PlantPrototypeRegistry registry;

    CountingPlant* rawPrototype = new CountingPlant();
    rawPrototype->setCloneCounter(nullptr);
    registry.addPrototype("Counting", std::unique_ptr<Plant>(rawPrototype));

    ASSERT_TRUE(registry.hasPrototype("Counting"), "Registry should expose stored prototype");
}

void testCreatePlantTransfersOwnership() {
    std::cout << "Running test: testCreatePlantTransfersOwnership..." << std::endl;

    PlantPrototypeRegistry registry;
    int cloneCount = 0;
    auto prototype = std::make_unique<CountingPlant>(&cloneCount);
    registry.addPrototype("Counting", std::move(prototype));

    std::unique_ptr<Plant> clone(registry.createPlant("Counting", "Mature"));
    ASSERT_TRUE(clone != nullptr, "Registry should produce a clone");
    ASSERT_EQ_INT(cloneCount, 1, "clone() must be invoked exactly once");
    ASSERT_TRUE(clone->getType() == "Mature", "Type override should be applied to clone");
}

int main() {
    std::cout << "== Prototype Registry Ownership Tests ==" << std::endl;

    testRegistryOwnsPrototype();
    testCreatePlantTransfersOwnership();

    if (failures == 0) {
        std::cout << "\n[PASS] All prototype ownership tests passed." << std::endl;
        return 0;
    }
    std::cerr << "\n[FAIL] " << failures << " test(s) failed." << std::endl;
    return 1;
}
