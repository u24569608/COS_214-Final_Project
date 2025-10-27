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

    // ARRANGE 1: Create initial inventory
    Inventory inv1;
    inv1.additem(new StockItem("Rose", 10.0, nullptr));
    inv1.additem(new StockItem("Tulip", 5.5, nullptr));
    ASSERT_EQ_INT(inv1.getStockCount("Rose"), 1, "Initial Rose count");
    ASSERT_EQ_INT(inv1.getStockCount("Tulip"), 1, "Initial Tulip count");

    // ACT 1: Save using CSV Adapter
    CSVAdapter csvAdapter;
    inv1.saveToFile(&csvAdapter, testCsvPath);

    // ASSERT 1: Check if file exists and content (basic check)
    std::ifstream testFile(testCsvPath);
    ASSERT_TRUE(testFile.good(), "Test CSV file should be created");
    std::string line1, line2;
    std::getline(testFile, line1);
    std::getline(testFile, line2);
    testFile.close();
    ASSERT_EQ_STR(line1, "Rose,10", "CSV Line 1 content"); // Price is int in StockItem
    ASSERT_EQ_STR(line2, "Tulip,5", "CSV Line 2 content"); // Price is int in StockItem

    // ARRANGE 2: Prepare import context with greenhouse and prototypes
    PlantPrototypeRegistry registry;
    registerPrototypes(registry, {"Rose", "Tulip"});
    GreenhouseBed importBed("CSV Import Bed");
    Inventory inv2;
    inv2.setGreenhouseRoot(&importBed);
    inv2.setPlantRegistry(&registry);
    ASSERT_EQ_INT(inv2.getStockCount("Rose"), 0, "Inv2 Rose count before load");

    // ACT 2: Load using CSV Adapter
    inv2.loadFromFile(&csvAdapter, testCsvPath);

    // ASSERT 2: Check contents of inv2
    ASSERT_EQ_INT(inv2.getStockCount("Rose"), 1, "Loaded Rose count");
    ASSERT_EQ_INT(inv2.getStockCount("Tulip"), 1, "Loaded Tulip count");
    StockItem* loadedRose = inv2.findItem("Rose");
    ASSERT_TRUE(loadedRose != nullptr, "Loaded Rose should exist");
    // StockItem getPrice returns int
    ASSERT_EQ_INT(loadedRose->getPrice(), 10, "Loaded Rose price");
    StockItem* loadedTulip = inv2.findItem("Tulip");
    ASSERT_TRUE(loadedTulip != nullptr, "Loaded Tulip should exist");
    ASSERT_EQ_INT(loadedTulip->getPrice(), 5, "Loaded Tulip price");

    // ASSERT 3: Greenhouse received live plant instances
    ASSERT_EQ_INT(importBed.getSize(), 2, "Greenhouse should contain two plants");
    ASSERT_TRUE(loadedRose->getplant() != nullptr, "Loaded Rose should have a PlantInstance");
    ASSERT_TRUE(importBed.findPlantInBed(loadedRose->getplant()->getName()) != nullptr,
                "Greenhouse should track the Rose plant");
    ASSERT_TRUE(loadedTulip->getplant() != nullptr, "Loaded Tulip should have a PlantInstance");
    ASSERT_TRUE(importBed.findPlantInBed(loadedTulip->getplant()->getName()) != nullptr,
                "Greenhouse should track the Tulip plant");
}

void testTXTSaveLoadRoundTrip() {
    std::cout << "Running test: testTXTSaveLoadRoundTrip..." << std::endl;

    // ARRANGE 1
    Inventory inv1;
    inv1.additem(new StockItem("Spade", 12.50, nullptr));
    inv1.additem(new StockItem("Gloves", 15.75, nullptr));

    // ACT 1: Save
    TXTAdapter txtAdapter;
    inv1.saveToFile(&txtAdapter, testTxtPath);

    // ASSERT 1
    std::ifstream testFile(testTxtPath);
    ASSERT_TRUE(testFile.good(), "Test TXT file should be created");
    std::string line1, line2;
    std::getline(testFile, line1);
    std::getline(testFile, line2);
    testFile.close();
    ASSERT_EQ_STR(line1, "Spade 12", "TXT Line 1 content"); // Price is int
    ASSERT_EQ_STR(line2, "Gloves 15", "TXT Line 2 content"); // Price is int


    // ARRANGE 2
    Inventory inv2;
    GreenhouseBed toolBed("TXT Import Bed");
    inv2.setGreenhouseRoot(&toolBed);

    // ACT 2: Load
    inv2.loadFromFile(&txtAdapter, testTxtPath);

    // ASSERT 2
    ASSERT_EQ_INT(inv2.getStockCount("Spade"), 1, "Loaded Spade count");
    ASSERT_EQ_INT(inv2.getStockCount("Gloves"), 1, "Loaded Gloves count");
    StockItem* loadedSpade = inv2.findItem("Spade");
    ASSERT_TRUE(loadedSpade != nullptr, "Loaded Spade should exist");
    ASSERT_EQ_INT(loadedSpade->getPrice(), 12, "Loaded Spade price");
    StockItem* loadedGloves = inv2.findItem("Gloves");
    ASSERT_TRUE(loadedGloves != nullptr, "Loaded Gloves should exist");
    ASSERT_EQ_INT(loadedGloves->getPrice(), 15, "Loaded Gloves price");
    ASSERT_EQ_INT(toolBed.getSize(), 0, "No plants should be imported for tool stock");
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
     badTxt << "Spade Twelve\n"; // Bad price
     badTxt << "Gloves 15.75 Extra\n"; // Extra data (TXTAdapter should handle)
     badTxt << "\n"; // Empty line
     badTxt << "Shears 20\n"; // Good line
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
      // ASSERT: Should load items with valid price format (Gloves, Shears)
     ASSERT_EQ_INT(inv.getStockCount("Spade"), 0, "Bad TXT: Spade not loaded");
     ASSERT_EQ_INT(inv.getStockCount("Gloves"), 1, "Bad TXT: Gloves loaded");
     ASSERT_EQ_INT(inv.findItem("Gloves")->getPrice(), 15, "Bad TXT: Gloves price"); // Price is int
     ASSERT_EQ_INT(inv.getStockCount("Shears"), 1, "Bad TXT: Shears loaded");
     ASSERT_EQ_INT(inv.findItem("Shears")->getPrice(), 20, "Bad TXT: Shears price");
     ASSERT_EQ_INT(validationBed.getSize(), 0, "TXT load should not add plants");
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
