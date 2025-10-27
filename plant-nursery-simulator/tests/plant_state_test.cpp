#include <iostream>
#include <string>

#include "../include/Plant.h"
#include "../include/PlantInstance.h"
#include "../include/WaterStrategy.h"
#include "../include/FertilizeStrategy.h"

namespace {

class DummyPlant : public Plant {
public:
    explicit DummyPlant(const std::string& label) {
        name = label;
    }

    Plant* clone() const override {
        return new DummyPlant(*this);
    }
};

class TrackingWaterStrategy : public WaterStrategy {
public:
    TrackingWaterStrategy() : callCount(0) {}

    void water(PlantInstance& plant) const override {
        plant.changeWaterLevel(35);
        plant.changeHealth(2);
        ++callCount;
    }

    WaterStrategy* clone() const override {
        return new TrackingWaterStrategy(*this);
    }

    void reset() {
        callCount = 0;
    }

    int getCallCount() const {
        return callCount;
    }

private:
    mutable int callCount;
};

class TrackingFertilizeStrategy : public FertilizeStrategy {
public:
    TrackingFertilizeStrategy() : callCount(0) {}

    void fertilize(PlantInstance& plant) const override {
        plant.changeNutrientLevel(30);
        plant.changeHealth(2);
        ++callCount;
    }

    FertilizeStrategy* clone() const override {
        return new TrackingFertilizeStrategy(*this);
    }

    void reset() {
        callCount = 0;
    }

    int getCallCount() const {
        return callCount;
    }

private:
    mutable int callCount;
};

int failures = 0;

void assertTrue(bool expression, const std::string& message) {
    if (expression) {
        return;
    }
    std::cerr << "[ASSERT_TRUE FAILED] " << message << std::endl;
    ++failures;
}

void assertEqStr(const std::string& actual, const std::string& expected, const std::string& message) {
    if (actual == expected) {
        return;
    }
    std::cerr << "[ASSERT_EQ_STR FAILED] " << message
              << " (expected \"" << expected << "\", got \"" << actual << "\")" << std::endl;
    ++failures;
}

void assertEqInt(int actual, int expected, const std::string& message) {
    if (actual == expected) {
        return;
    }
    std::cerr << "[ASSERT_EQ_INT FAILED] " << message
              << " (expected " << expected << ", got " << actual << ")" << std::endl;
    ++failures;
}

void driveToMature(PlantInstance& plant,
                   TrackingWaterStrategy& waterStrategy,
                   TrackingFertilizeStrategy& fertilizeStrategy) {
    assertTrue(plant.getState() != nullptr, "Seed state should be initialised");
    plant.applyGrowthTick(); // Seed -> Growing

    waterStrategy.reset();
    fertilizeStrategy.reset();

    plant.performWater();
    plant.performFertilize();

    assertEqStr(plant.getState()->getName(), "Mature",
                "Plant should reach Mature state after sufficient care");
    assertEqInt(waterStrategy.getCallCount(), 1,
                "Water strategy should be invoked when watering seeds/growing plants");
    assertEqInt(fertilizeStrategy.getCallCount(), 1,
                "Fertilize strategy should be invoked when feeding seeds/growing plants");
}

} // namespace

void testLifecycleTransitions() {
    std::cout << "Running test: testLifecycleTransitions..." << std::endl;

    DummyPlant prototype("Lifecycle Rose");
    PlantInstance plant(&prototype);
    TrackingWaterStrategy waterStrategy;
    TrackingFertilizeStrategy fertilizeStrategy;
    plant.setWaterStrategy(&waterStrategy);
    plant.setFertilizeStrategy(&fertilizeStrategy);

    assertEqStr(plant.getState()->getName(), "Seed", "Initial state should be Seed");

    driveToMature(plant, waterStrategy, fertilizeStrategy);

    // Drift forward until the plant withers.
    int ticks = 0;
    while (plant.getState()->getName() != "Withering" && ticks < 25) {
        plant.applyGrowthTick();
        ++ticks;
    }
    assertTrue(ticks < 25, "Plant should wither after prolonged neglect");
    assertEqStr(plant.getState()->getName(), "Withering", "Plant should enter Withering after stress");

    // Continue neglect until the plant dies.
    int deathTicks = 0;
    while (plant.getState()->getName() != "Dead" && deathTicks < 40) {
        plant.applyGrowthTick();
        ++deathTicks;
    }
    assertTrue(deathTicks < 40, "Plant should eventually die when neglected");
    assertEqStr(plant.getState()->getName(), "Dead", "Plant should end lifecycle in Dead state");
}

void testMatureStateIdempotency() {
    std::cout << "Running test: testMatureStateIdempotency..." << std::endl;

    DummyPlant prototype("Stable Lily");
    PlantInstance plant(&prototype);
    TrackingWaterStrategy waterStrategy;
    TrackingFertilizeStrategy fertilizeStrategy;
    plant.setWaterStrategy(&waterStrategy);
    plant.setFertilizeStrategy(&fertilizeStrategy);

    driveToMature(plant, waterStrategy, fertilizeStrategy);

    waterStrategy.reset();
    fertilizeStrategy.reset();

    plant.performWater();
    plant.performWater();
    plant.performFertilize();
    plant.performFertilize();

    assertEqStr(plant.getState()->getName(), "Mature",
                "Repeated care should keep a mature plant in the Mature state");
    assertEqInt(waterStrategy.getCallCount(), 2,
                "Water strategy should be invoked for every watering request");
    assertEqInt(fertilizeStrategy.getCallCount(), 2,
                "Fertilize strategy should be invoked for every fertilising request");
}

void testFertilizePromotionReplaysOnce() {
    std::cout << "Running test: testFertilizePromotionReplaysOnce..." << std::endl;

    DummyPlant prototype("Fertilize Daisy");
    PlantInstance plant(&prototype);
    TrackingWaterStrategy waterStrategy;
    TrackingFertilizeStrategy fertilizeStrategy;
    plant.setWaterStrategy(&waterStrategy);
    plant.setFertilizeStrategy(&fertilizeStrategy);

    assertEqStr(plant.getState()->getName(), "Seed", "Initial state should be Seed");

    plant.performFertilize();

    assertEqStr(plant.getState()->getName(), "Mature",
                "Fertilizing a healthy seed should advance through the lifecycle");
    assertEqInt(fertilizeStrategy.getCallCount(), 1,
                "Fertilize strategy should execute once despite state promotion");
}

void testWitheringRecovery() {
    std::cout << "Running test: testWitheringRecovery..." << std::endl;

    DummyPlant prototype("Resilient Ivy");
    PlantInstance plant(&prototype);
    TrackingWaterStrategy waterStrategy;
    TrackingFertilizeStrategy fertilizeStrategy;
    plant.setWaterStrategy(&waterStrategy);
    plant.setFertilizeStrategy(&fertilizeStrategy);

    driveToMature(plant, waterStrategy, fertilizeStrategy);

    // Induce withering by starving resources and letting a tick pass.
    plant.setWaterLevel(10);
    plant.setNutrientLevel(10);
    plant.setHealth(80);
    waterStrategy.reset();
    fertilizeStrategy.reset();

    plant.applyGrowthTick();
    assertEqStr(plant.getState()->getName(), "Withering",
                "Low resources should transition the plant to Withering");

    plant.performWater();
    plant.performFertilize();

    const std::string finalState = plant.getState()->getName();
    assertTrue(finalState == "Growing" || finalState == "Mature",
               "Recovery actions should lift the plant out of Withering");
    assertEqInt(waterStrategy.getCallCount(), 1,
                "Water strategy should be invoked once during recovery");
    assertEqInt(fertilizeStrategy.getCallCount(), 1,
                "Fertilize strategy should be invoked once during recovery");
}

int main() {
    int testsPassed = 0;
    int baseline = failures;

    testLifecycleTransitions();
    if (failures == baseline) { ++testsPassed; }
    baseline = failures;

    testMatureStateIdempotency();
    if (failures == baseline) { ++testsPassed; }
    baseline = failures;

    testFertilizePromotionReplaysOnce();
    if (failures == baseline) { ++testsPassed; }
    baseline = failures;

    testWitheringRecovery();
    if (failures == baseline) { ++testsPassed; }

    std::cout << "\n---------------------------\n";
    std::cout << "     TEST SUMMARY          \n";
    std::cout << " Tests Passed: " << testsPassed << " / 4" << std::endl;
    std::cout << "---------------------------\n";

    if (failures == 0) {
        return 0;
    }
    std::cerr << "[FAIL] " << failures << " test(s) failed." << std::endl;
    return 1;
}
