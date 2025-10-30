/**
 * @file prototype_test.cpp
 * @brief Validates prototype pattern cloning for plant definitions and registries.
 */
#include <iostream>
#include <memory>
#include <string>

#include "../include/Plant.h"
#include "../include/PlantPrototypeRegistry.h"

namespace {

class StubPlant : public Plant {
public:
    StubPlant(const std::string& nameValue, const std::string& typeValue) {
        setName(nameValue);
        setType(typeValue);
    }

    StubPlant(const StubPlant&) = default;

    Plant* clone() const override {
        return new StubPlant(*this);
    }
};

int failures = 0;

void assertTrue(bool expression, const std::string& message) {
    if (!expression) {
        std::cerr << "[ASSERT_TRUE FAILED] " << message << std::endl;
        ++failures;
    }
}

void assertEqStr(const std::string& actual, const std::string& expected, const std::string& message) {
    if (actual == expected) {
        return;
    }

    std::cerr << "[ASSERT_EQ_STR FAILED] " << message
              << " (expected \"" << expected << "\", got \"" << actual << "\")" << std::endl;
    ++failures;
}

void assertPtrNotSame(const void* lhs, const void* rhs, const std::string& message) {
    if (lhs != rhs) {
        return;
    }

    std::cerr << "[ASSERT_PTR_NOT_SAME FAILED] " << message << std::endl;
    ++failures;
}

} // namespace

void testBaseCloneProducesDistinctInstance() {
    std::cout << "Running test: testBaseCloneProducesDistinctInstance..." << std::endl;

    StubPlant prototype("Prototype Basil", "Herb");
    Plant* clone = prototype.clone();

    assertTrue(clone != nullptr, "clone() should produce a valid object");
    if (clone != nullptr) {
        assertPtrNotSame(clone, &prototype, "clone() should not return the same pointer");
        assertEqStr(clone->getName(), "Prototype Basil", "clone() should copy the prototype name");
        assertEqStr(clone->getType(), "Herb", "clone() should copy the prototype type");
        delete clone;
    }
}

void testRegistryCreatesPlantFromPrototype() {
    std::cout << "Running test: testRegistryCreatesPlantFromPrototype..." << std::endl;

    PlantPrototypeRegistry registry;
    auto prototype = std::make_unique<StubPlant>("Registry Rose", "Flower");
    const Plant* original = prototype.get();
    registry.addPrototype("rose", std::move(prototype));

    Plant* clone = registry.createPlant("rose", "");
    assertTrue(clone != nullptr, "createPlant() should return a clone when the key exists");
    if (clone != nullptr) {
        assertPtrNotSame(clone, original, "createPlant() should return a new instance");
        assertEqStr(clone->getName(), "Registry Rose", "Cloned plant should copy the prototype name");
        assertEqStr(clone->getType(), "Flower", "Cloned plant should preserve the prototype type when no override is supplied");
        delete clone;
    }
}

void testRegistryAppliesTypeOverride() {
    std::cout << "Running test: testRegistryAppliesTypeOverride..." << std::endl;

    PlantPrototypeRegistry registry;
    auto prototype = std::make_unique<StubPlant>("Lavender", "Herb");
    registry.addPrototype("lavender", std::move(prototype));

    Plant* overridden = registry.createPlant("lavender", "Medicinal");
    assertTrue(overridden != nullptr, "createPlant() should succeed for registered keys");
    if (overridden != nullptr) {
        assertEqStr(overridden->getType(), "Medicinal", "createPlant() should apply the provided type override");
        delete overridden;
    }

    Plant* missing = registry.createPlant("unknown", "");
    assertTrue(missing == nullptr, "createPlant() should return nullptr for an unknown key");
}

int main() {
    int testsPassed = 0;
    int baseline = failures;

    testBaseCloneProducesDistinctInstance();
    if (failures == baseline) { ++testsPassed; }
    baseline = failures;

    testRegistryCreatesPlantFromPrototype();
    if (failures == baseline) { ++testsPassed; }
    baseline = failures;

    testRegistryAppliesTypeOverride();
    if (failures == baseline) { ++testsPassed; }

    std::cout << "\n---------------------------\n";
    std::cout << "     TEST SUMMARY          \n";
    std::cout << " Tests Passed: " << testsPassed << " / 3" << std::endl;
    std::cout << "---------------------------\n";

    if (failures == 0) {
        return 0;
    }
    std::cerr << "[FAIL] " << failures << " test(s) failed." << std::endl;
    return 1;
}
