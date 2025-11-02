/**
 * @file iterator_test.cpp
 * @brief Validates inventory iterator behaviour through custom traversal checks.
 */
#include <iostream>
#include <string>
#include <memory>
#include <vector>

// --- Include the code we want to test ---
#include "../include/Inventory.h"
#include "../include/InventoryIterator.h"
#include "../include/ConcreteInventoryIterator.h"
#include "../include/StockItem.h"
#include "../include/PlantInstance.h"
#include "../include/PlantPrototypeRegistry.h"
#include "../include/GreenhouseBed.h"
#include "../include/GreenhouseIterator.h"
#include "../include/MatureState.h"
#include "../include/Plant.h"

// --- Global failure counter ---
static int failures = 0;

// --- Assertion functions (copy-pasted from builder_test.cpp) ---
void ASSERT_TRUE(bool expr, const std::string& msg) {
    if (expr == false) {
        std::cerr << "[ASSERT_TRUE FAILED] " << msg << std::endl;
        failures = failures + 1;
    }
}
void ASSERT_EQ_INT(int a, int b, const std::string& msg) {
    if (a == b) { return; }
    std::cerr << "[ASSERT_EQ_INT FAILED] " << msg
              << " (expected " << b << ", got " << a << ")"
              << std::endl;
    failures = failures + 1;
}
void ASSERT_EQ_STR(const std::string& a, const std::string& b, const std::string& msg) {
    if (a == b) { return; }
    std::cerr << "[ASSERT_EQ_STR FAILED] " << msg
              << " (expected \"" << b << "\", got \"" << a << "\")"
              << std::endl;
    failures = failures + 1;
}


class IteratorStubPlant : public Plant {
public:
    explicit IteratorStubPlant(const std::string& displayName = "IteratorStub") {
        setName(displayName);
    }

    Plant* clone() const override {
        return new IteratorStubPlant(*this);
    }
};

void registerIteratorPrototype(PlantPrototypeRegistry& registry, const std::string& name) {
    auto plant = std::make_unique<IteratorStubPlant>(name);
    registry.addPrototype(name, std::move(plant));
}

std::vector<std::string> collectIteratorNames(InventoryIterator* iterator) {
    std::vector<std::string> names;
    if (!iterator) {
        return names;
    }
    for (StockItem* item = iterator->first(); item != nullptr; item = iterator->next()) {
        names.emplace_back(item->getname());
    }
    return names;
}

// --- Our Individual Test Cases (now void) ---

/**
 * @brief Tests how the iterator behaves on an empty inventory.
 */
void testEmptyInventory() {
    std::cout << "Running test: testEmptyInventory..." << std::endl;

    // ARRANGE
    Inventory inv;

    // ACT
    InventoryIterator* iter = inv.createIterator();

    // ASSERT
    ASSERT_TRUE(iter->hasNext() == false, "hasNext() should be false");
    ASSERT_TRUE(iter->currentItem() == nullptr, "currentItem() should be nullptr");
    ASSERT_TRUE(iter->first() == nullptr, "first() should be nullptr");
    ASSERT_TRUE(iter->next() == nullptr, "next() should be nullptr");

    delete iter;
}

/**
 * @brief Ensures the iterator prioritises greenhouse-backed, market-ready plants and
 *        appends non-plant stock while skipping unavailable plants.
 */
void testGreenhouseBackedTraversal() {
    std::cout << "Running test: testGreenhouseBackedTraversal..." << std::endl;

    GreenhouseBed greenhouse("Iterator Bed");
    PlantPrototypeRegistry registry;
    Inventory inv;
    inv.setPlantRegistry(&registry);
    inv.setGreenhouseRoot(&greenhouse);

    registerIteratorPrototype(registry, "Rose");
    registerIteratorPrototype(registry, "Lily");
    inv.registerPlantType("Rose");
    inv.registerPlantType("Lily");

    PlantInstance* rose = inv.createPlantInstance("Rose");
    rose->setState(std::make_unique<MatureState>());
    inv.additem(std::make_unique<StockItem>("Rose", 12.0, rose));

    PlantInstance* lily = inv.createPlantInstance("Lily");
    inv.additem(std::make_unique<StockItem>("Lily", 9.0, lily)); // Seed state, not market ready

    inv.additem(std::make_unique<StockItem>("Gloves", 5.0, nullptr));

    std::unique_ptr<InventoryIterator> iter(inv.createIterator());

    const std::vector<std::string> names = collectIteratorNames(iter.get());
    ASSERT_EQ_INT(static_cast<int>(names.size()), 2, "Only market-ready plants and non-plant stock should be returned");
    ASSERT_EQ_STR(names[0], "Rose", "Market-ready greenhouse plant should appear first");
    ASSERT_EQ_STR(names[1], "Gloves", "Non-plant stock should follow greenhouse plants");
    ASSERT_TRUE(iter->hasNext() == false, "Iterator should report no remaining items after traversal");
}

/**
 * @brief Verifies that resetting the iterator reflects updates to plant availability.
 */
void testIteratorResetReflectsStateChanges() {
    std::cout << "Running test: testIteratorResetReflectsStateChanges..." << std::endl;

    GreenhouseBed greenhouse("Reset Bed");
    PlantPrototypeRegistry registry;
    Inventory inv;
    inv.setPlantRegistry(&registry);
    inv.setGreenhouseRoot(&greenhouse);

    registerIteratorPrototype(registry, "Rose");
    registerIteratorPrototype(registry, "Tulip");
    inv.registerPlantType("Rose");
    inv.registerPlantType("Tulip");

    PlantInstance* rose = inv.createPlantInstance("Rose");
    rose->setState(std::make_unique<MatureState>());
    inv.additem(std::make_unique<StockItem>("Rose", 11.0, rose));

    PlantInstance* tulip = inv.createPlantInstance("Tulip");
    inv.additem(std::make_unique<StockItem>("Tulip", 7.0, tulip)); // Not yet market ready

    std::unique_ptr<InventoryIterator> iter(inv.createIterator());

    std::vector<std::string> initialNames = collectIteratorNames(iter.get());
    ASSERT_EQ_INT(static_cast<int>(initialNames.size()), 1, "Only Rose should be available initially");
    ASSERT_EQ_STR(initialNames[0], "Rose", "Rose should be the only item initially");

    tulip->setState(std::make_unique<MatureState>());
    ASSERT_TRUE(tulip->isAvailableForSale(), "Tulip should be market ready after state change");
    ASSERT_EQ_STR(tulip->getState() ? tulip->getState()->getName() : "", "Mature", "Tulip state should now be Mature");
    {
        std::unique_ptr<GreenhouseIterator> greenhouseIter = greenhouse.createIterator();
        int greenhouseCount = 0;
        bool foundTulip = false;
        bool tulipReportedReady = false;
        for (PlantInstance* plant = greenhouseIter ? greenhouseIter->first() : nullptr;
             plant != nullptr;
             plant = greenhouseIter->next()) {
            ++greenhouseCount;
            if (plant == tulip) {
                foundTulip = true;
                tulipReportedReady = plant->isAvailableForSale();
            }
        }
        ASSERT_EQ_INT(greenhouseCount, 2, "Greenhouse should still track both plants");
        ASSERT_TRUE(foundTulip, "Greenhouse iterator should visit Tulip instance");
        ASSERT_TRUE(tulipReportedReady, "Tulip should be reported market ready via greenhouse iterator");
    }
    StockItem* tulipStock = inv.findItem("Tulip");
    ASSERT_TRUE(tulipStock != nullptr, "Stock item for Tulip should exist");
    ASSERT_TRUE(tulipStock->getplant() == tulip, "Stock item should reference the Tulip plant instance");
    ASSERT_TRUE(tulipStock->getplant()->isAvailableForSale(), "Stock item plant pointer should confirm availability");
    iter->reset();

    std::vector<std::string> updatedNames = collectIteratorNames(iter.get());
    ASSERT_EQ_INT(static_cast<int>(updatedNames.size()), 2, "Both plants should be returned after Tulip matures");
    ASSERT_EQ_STR(updatedNames[0], "Rose", "Rose should remain first after reset");
    ASSERT_EQ_STR(updatedNames[1], "Tulip", "Tulip should now appear after becoming market ready");
    ASSERT_TRUE(iter->hasNext() == false, "Iterator should reach the end after traversal");
}


// --- Our Test Runner MAIN Function (now matches builder_test) ---

int main() {
    std::cout << "== Iterator Basic UNIT TESTS ==" << std::endl;

    // Run all test functions
    testEmptyInventory();
    testGreenhouseBackedTraversal();
    testIteratorResetReflectsStateChanges();

    // --- Print Summary ---
    if (failures == 0) {
        std::cout << "\n[PASS] All iterator unit tests passed." << std::endl;
        return 0; // Exit with 0 for SUCCESS
    } else {
        std::cerr << "\n[FAIL] " << failures << " test(s) failed." << std::endl;
        return 1; // Exit with 1 for FAILURE
    }
}
