#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath> // For std::abs in ASSERT_NEAR
#include <memory>

// --- Include the code we want to test ---
#include "../include/Inventory.h"
#include "../include/StockItem.h"
#include "../include/FileAdapter.h"
#include "../include/TXTAdapter.h"
#include "../include/CSVAdapter.h"
#include "../include/GreenhouseBed.h"
#include "../include/PlantPrototypeRegistry.h"
#include "../include/Plant.h"
#include "../include/MatureState.h"
// Include necessary stubs for linking
#include "../include/InventoryCollection.h"
#include "../include/InventoryIterator.h"
#include "../include/ConcreteInventoryIterator.h"
#include "../include/PlantInstance.h"
#include "../include/TXTReaderWriter.h" // Needed by TXTAdapter
#include "../include/CSVReaderWriter.h" // Needed by CSVAdapter


// --- Global failure counter ---
static int failures = 0;

// --- Assertion functions (copy-pasted) ---
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
// Helper to compare doubles with tolerance
void ASSERT_NEAR(double a, double b, double tolerance, const std::string& msg) {
     if (std::abs(a - b) <= tolerance) { return; }
     std::cerr << "[ASSERT_NEAR FAILED] " << msg
              << " (expected near " << b << ", got " << a << ")"
              << std::endl;
    failures = failures + 1;
}

// --- Test File Paths ---
// Use different names to avoid conflicts with initial data
const std::string testCsvPath = "data/test_roundtrip.csv";
const std::string testTxtPath = "data/test_roundtrip.txt";
const std::string invalidPath = "data/non_existent_file.bad";
const std::string badCsvPath = "data/bad_data.csv";
const std::string badTxtPath = "data/bad_data.txt";

// --- Test helpers ---
class StubPlant : public Plant {
public:
    StubPlant() = default;
    explicit StubPlant(const std::string& displayName) {
        setName(displayName);
    }
    Plant* clone() const override {
        return new StubPlant(*this);
    }
};

void registerPrototypes(PlantPrototypeRegistry& registry, const std::vector<std::string>& names) {
    for (const std::string& name : names) {
        auto plant = std::make_unique<StubPlant>(name);
        registry.addPrototype(name, std::move(plant));
    }
}

// --- Test Cases ---

void testCSVSaveLoadRoundTrip() {
    std::cout << "Running test: testCSVSaveLoadRoundTrip..." << std::endl;

    // ARRANGE 1: Create initial inventory with mixed stock
    PlantPrototypeRegistry exportRegistry;
    registerPrototypes(exportRegistry, {"Rose", "Tulip"});
    GreenhouseBed exportBed("CSV Export Greenhouse");
    Inventory inv1;
    inv1.setGreenhouseRoot(&exportBed);
    inv1.setPlantRegistry(&exportRegistry);
    inv1.registerPlantType("Rose");
    inv1.registerPlantType("Tulip");
    PlantInstance* roseInstance = inv1.createPlantInstance("Rose");
    roseInstance->setState(std::make_unique<MatureState>());
    PlantInstance* tulipInstance = inv1.createPlantInstance("Tulip");
    tulipInstance->setState(std::make_unique<MatureState>());
    inv1.additem(std::make_unique<StockItem>("Rose", 10.0, roseInstance));
    inv1.additem(std::make_unique<StockItem>("Tulip", 6.0, tulipInstance));
    inv1.additem(std::make_unique<StockItem>("Spade", 12.0, nullptr));

    ASSERT_EQ_INT(exportBed.getSize(), 2, "Export greenhouse should contain two plants");

    // ACT 1: Save using CSV Adapter
    CSVAdapter csvAdapter;
    inv1.saveToFile(&csvAdapter, testCsvPath);

    // ASSERT 1: Verify saved CSV content preserves all items
    std::ifstream testFile(testCsvPath);
    ASSERT_TRUE(testFile.good(), "Test CSV file should be created");
    std::vector<std::string> lines;
    for (std::string line; std::getline(testFile, line);) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }
    testFile.close();
    ASSERT_EQ_INT(static_cast<int>(lines.size()), 3, "CSV should contain three rows");
    ASSERT_EQ_STR(lines[0], "Rose,10", "CSV Rose row");
    ASSERT_EQ_STR(lines[1], "Tulip,6", "CSV Tulip row");
    ASSERT_EQ_STR(lines[2], "Spade,12", "CSV Spade row");

    // ARRANGE 2: Prepare import context with greenhouse and prototypes
    PlantPrototypeRegistry importRegistry;
    registerPrototypes(importRegistry, {"Rose", "Tulip"});
    GreenhouseBed importBed("CSV Import Bed");
    Inventory inv2;
    inv2.setGreenhouseRoot(&importBed);
    inv2.setPlantRegistry(&importRegistry);

    // ACT 2: Load using CSV Adapter
    inv2.loadFromFile(&csvAdapter, testCsvPath);

    // ASSERT 2: Check contents of inv2
    ASSERT_EQ_INT(inv2.getStockCount("Rose"), 1, "Loaded Rose count");
    ASSERT_EQ_INT(inv2.getStockCount("Tulip"), 1, "Loaded Tulip count");
    ASSERT_EQ_INT(inv2.getStockCount("Spade"), 1, "Loaded Spade count");
    StockItem* loadedRose = inv2.findItem("Rose");
    StockItem* loadedTulip = inv2.findItem("Tulip");
    StockItem* loadedSpade = inv2.findItem("Spade");
    ASSERT_TRUE(loadedRose != nullptr, "Loaded Rose should exist");
    ASSERT_TRUE(loadedTulip != nullptr, "Loaded Tulip should exist");
    ASSERT_TRUE(loadedSpade != nullptr, "Loaded Spade should exist");
    ASSERT_EQ_INT(loadedRose->getPrice(), 10, "Loaded Rose price");
    ASSERT_EQ_INT(loadedTulip->getPrice(), 6, "Loaded Tulip price");
    ASSERT_EQ_INT(loadedSpade->getPrice(), 12, "Loaded Spade price");

    // ASSERT 3: Greenhouse reflects only plant-backed stock
    ASSERT_EQ_INT(importBed.getSize(), 2, "Greenhouse should contain two plants post-import");
    ASSERT_TRUE(loadedRose->getplant() != nullptr, "Loaded Rose should have a PlantInstance");
    ASSERT_TRUE(importBed.findPlantInBed(loadedRose->getplant()->getName()) != nullptr,
                "Greenhouse should track the Rose plant");
    ASSERT_TRUE(loadedTulip->getplant() != nullptr, "Loaded Tulip should have a PlantInstance");
    ASSERT_TRUE(importBed.findPlantInBed(loadedTulip->getplant()->getName()) != nullptr,
                "Greenhouse should track the Tulip plant");
    ASSERT_TRUE(loadedSpade->getplant() == nullptr, "Non-plant stock should not spawn PlantInstance");
}

void testTXTSaveLoadRoundTrip() {
    std::cout << "Running test: testTXTSaveLoadRoundTrip..." << std::endl;

    // ARRANGE 1: Mixed inventory with a single plant-backed entry
    PlantPrototypeRegistry exportRegistry;
    registerPrototypes(exportRegistry, {"Succulent"});
    GreenhouseBed exportBed("TXT Export Greenhouse");
    Inventory inv1;
    inv1.setGreenhouseRoot(&exportBed);
    inv1.setPlantRegistry(&exportRegistry);
    inv1.registerPlantType("Succulent");
    PlantInstance* succulentInstance = inv1.createPlantInstance("Succulent");
    succulentInstance->setState(std::make_unique<MatureState>());
    inv1.additem(std::make_unique<StockItem>("Succulent", 18.0, succulentInstance));
    inv1.additem(std::make_unique<StockItem>("Pot", 7.0, nullptr));

    // ACT 1: Save
    TXTAdapter txtAdapter;
    inv1.saveToFile(&txtAdapter, testTxtPath);

    // ASSERT 1: Saved TXT contains both items
    std::ifstream testFile(testTxtPath);
    ASSERT_TRUE(testFile.good(), "Test TXT file should be created");
    std::vector<std::string> lines;
    for (std::string line; std::getline(testFile, line);) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }
    testFile.close();
    ASSERT_EQ_INT(static_cast<int>(lines.size()), 2, "TXT should contain two rows");
    ASSERT_EQ_STR(lines[0], "Plant,Succulent,18,Mature", "TXT Succulent row");
    ASSERT_EQ_STR(lines[1], "Item,Pot,7", "TXT Pot row");

    // ARRANGE 2: Prepare import context
    PlantPrototypeRegistry importRegistry;
    registerPrototypes(importRegistry, {"Succulent"});
    GreenhouseBed importBed("TXT Import Bed");
    Inventory inv2;
    inv2.setGreenhouseRoot(&importBed);
    inv2.setPlantRegistry(&importRegistry);

    // ACT 2: Load
    inv2.loadFromFile(&txtAdapter, testTxtPath);

    // ASSERT 2: Validate imported items
    ASSERT_EQ_INT(inv2.getStockCount("Succulent"), 1, "Loaded Succulent count");
    ASSERT_EQ_INT(inv2.getStockCount("Pot"), 1, "Loaded Pot count");
    StockItem* loadedSucculent = inv2.findItem("Succulent");
    StockItem* loadedPot = inv2.findItem("Pot");
    ASSERT_TRUE(loadedSucculent != nullptr, "Loaded Succulent should exist");
    ASSERT_TRUE(loadedPot != nullptr, "Loaded Pot should exist");
    ASSERT_EQ_INT(loadedSucculent->getPrice(), 18, "Loaded Succulent price");
    ASSERT_EQ_INT(loadedPot->getPrice(), 7, "Loaded Pot price");
    const PlantState* succulentState = loadedSucculent->getplant() ? loadedSucculent->getplant()->getState() : nullptr;
    ASSERT_TRUE(succulentState != nullptr, "Loaded Succulent should expose its state");
    ASSERT_EQ_STR(succulentState->getName(), "Mature", "Succulent state should persist through TXT round-trip");

    // ASSERT 3: Only plant-backed items reach the greenhouse
    ASSERT_EQ_INT(importBed.getSize(), 1, "Greenhouse should contain one plant");
    ASSERT_TRUE(loadedSucculent->getplant() != nullptr, "Loaded Succulent should have a PlantInstance");
    ASSERT_TRUE(importBed.findPlantInBed(loadedSucculent->getplant()->getName()) != nullptr,
                "Greenhouse should track the Succulent plant");
    ASSERT_TRUE(loadedPot->getplant() == nullptr, "Pot should remain a simple stock item");
}

void testLoadInvalidFile() {
     std::cout << "Running test: testLoadInvalidFile..." << std::endl;
     PlantPrototypeRegistry registry;
     registerPrototypes(registry, {"Orchid"});
     GreenhouseBed validationBed("Validation Bed");
     Inventory inv;
     inv.setPlantRegistry(&registry);
     inv.setGreenhouseRoot(&validationBed);
     CSVAdapter csvAdapter;
     TXTAdapter txtAdapter;

     // ACT: Try loading non-existent files (should print errors, not crash)
     std::cout << "--- Testing non-existent files (expect errors) ---" << std::endl;
     inv.loadFromFile(&csvAdapter, invalidPath);
     // ASSERT: Inventory should still be empty
     ASSERT_TRUE(inv.findItem("Anything") == nullptr, "Inventory empty after loading bad CSV path");
     ASSERT_EQ_INT(validationBed.getSize(), 0, "Greenhouse remains empty after failed load");

     inv.loadFromFile(&txtAdapter, invalidPath);
     ASSERT_TRUE(inv.findItem("Anything") == nullptr, "Inventory empty after loading bad TXT path");
     ASSERT_EQ_INT(validationBed.getSize(), 0, "Greenhouse still empty after failed TXT load");
     std::cout << "--- Done testing non-existent files ---" << std::endl;


     // ARRANGE: Create bad data files
     std::ofstream badCsv(badCsvPath);
     badCsv << "Rose,Ten\n"; // Bad price
     badCsv << "Tulip,5,ExtraField\n"; // Bad number of fields
     badCsv << "\n"; // Empty line
     badCsv << "Orchid,25.5\n"; // Good line
     badCsv.close();

    std::ofstream badTxt(badTxtPath);
    badTxt << "Plant,Spade,Twelve,Mature\n"; // Bad price
    badTxt << "Item,Gloves,15.75,Extra\n"; // Too many fields
    badTxt << "Unknown,Shears,20\n"; // Unknown entry type
    badTxt << "Item,Shears,20\n"; // Only valid row
    badTxt.close();

     // ACT: Load the bad files
     std::cout << "--- Testing bad CSV file (expect warnings) ---" << std::endl;
     inv.loadFromFile(&csvAdapter, badCsvPath);
     // ASSERT: Should load only the valid item (Orchid)
     ASSERT_EQ_INT(inv.getStockCount("Rose"), 0, "Bad CSV: Rose not loaded");
     ASSERT_EQ_INT(inv.getStockCount("Tulip"), 0, "Bad CSV: Tulip not loaded");
     ASSERT_EQ_INT(inv.getStockCount("Orchid"), 1, "Bad CSV: Orchid loaded");
     ASSERT_EQ_INT(inv.findItem("Orchid")->getPrice(), 25, "Bad CSV: Orchid price"); // Price is int
     ASSERT_EQ_INT(validationBed.getSize(), 1, "Greenhouse tracks Orchid plant");
     std::cout << "--- Done testing bad CSV file ---" << std::endl;


     // Clear inventory by loading non-existent file again
     inv.loadFromFile(&csvAdapter, invalidPath);
     ASSERT_EQ_INT(inv.getStockCount("Orchid"), 0, "Inventory cleared");
     ASSERT_EQ_INT(validationBed.getSize(), 0, "Greenhouse cleared after invalid load");


     std::cout << "--- Testing bad TXT file (expect warnings) ---" << std::endl;
     inv.loadFromFile(&txtAdapter, badTxtPath);
     // ASSERT: Entries with recoverable issues should be normalised during load
    ASSERT_EQ_INT(inv.getStockCount("Spade"), 1, "Bad TXT: Spade defaulted to zero price");
    ASSERT_EQ_INT(inv.findItem("Spade")->getPrice(), 0, "Bad TXT: Spade price defaults to zero");
    ASSERT_EQ_INT(inv.getStockCount("Gloves"), 1, "Bad TXT: Gloves entry retained");
    ASSERT_EQ_INT(inv.findItem("Gloves")->getPrice(), 15, "Bad TXT: Gloves price truncated to int");
    ASSERT_EQ_INT(inv.getStockCount("Shears"), 1, "Bad TXT: Shears loaded from final valid row");
    ASSERT_EQ_INT(inv.findItem("Shears")->getPrice(), 20, "Bad TXT: Shears price");
    ASSERT_EQ_INT(validationBed.getSize(), 0, "TXT load should not add plants for invalid input");
     std::cout << "--- Done testing bad TXT file ---" << std::endl;
}


// --- Test Runner MAIN ---
int main() {
    std::cout << "== Adapter Pattern UNIT TESTS ==" << std::endl;

    testCSVSaveLoadRoundTrip();
    testTXTSaveLoadRoundTrip();
    testLoadInvalidFile();

    // --- Print Summary ---
    if (failures == 0) {
        std::cout << "\n[PASS] All adapter unit tests passed." << std::endl;
        // Clean up test files
        remove(testCsvPath.c_str());
        remove(testTxtPath.c_str());
        remove(badCsvPath.c_str());
        remove(badTxtPath.c_str());
        return 0; // SUCCESS
    } else {
        std::cerr << "\n[FAIL] " << failures << " test(s) failed." << std::endl;
        return 1; // FAILURE
    }
}
