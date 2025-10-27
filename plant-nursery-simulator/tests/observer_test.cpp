#include <iostream>
#include <memory>
#include <string>

#include "../include/FloorMediator.h"
#include "../include/MatureState.h"
#include "../include/Plant.h"
#include "../include/PlantInstance.h"
#include "../include/Staff.h"
#include "../include/StockItem.h"
#include "../include/WitheringState.h"

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

class NullMediator : public FloorMediator {
public:
    void addColleague(Colleague* /*colleague*/) override {}
    void distribute(std::string /*message*/, int /*senderID*/, int /*recipientID*/) override {}
};

int failures = 0;

void assertTrue(bool expression, const std::string& message) {
    if (!expression) {
        std::cerr << "[ASSERT_TRUE FAILED] " << message << std::endl;
        ++failures;
    }
}

void assertEqInt(int actual, int expected, const std::string& message) {
    if (actual != expected) {
        std::cerr << "[ASSERT_EQ_INT FAILED] " << message
                  << " (expected " << expected << ", got " << actual << ")" << std::endl;
        ++failures;
    }
}

void assertEqStr(const std::string& actual, const std::string& expected, const std::string& message) {
    if (actual != expected) {
        std::cerr << "[ASSERT_EQ_STR FAILED] " << message
                  << " (expected \"" << expected << "\", got \"" << actual << "\")" << std::endl;
        ++failures;
    }
}

void testAttachDetachObservers() {
    std::cout << "Running test: testAttachDetachObservers..." << std::endl;

    DummyPlant prototype("Notifier");
    PlantInstance plant(&prototype);
    StockItem stock("Notifier Item", 20.0, &plant);
    NullMediator mediator;
    Staff staff(1, &mediator);

    staff.observePlant(&plant);

    plant.setState(std::make_unique<MatureState>());

    assertTrue(stock.getIsAvailible(), "Stock item should remain available after maturity");
    assertEqStr(stock.getDisplayStatus(), "Plant ready for sale",
                "Stock item should reflect availability change message");
    assertEqInt(staff.getCareReminderCount(), 1,
                "Staff should receive an availability reminder when plant matures");

    staff.stopObservingPlant(&plant);
    plant.setState(std::make_unique<WitheringState>());

    assertEqStr(stock.getDisplayStatus(), "Plant unavailable for sale",
                "Stock item should track unavailability after state regression");
    assertEqInt(staff.getCareReminderCount(), 1,
                "Detached staff should not receive additional reminders");
}

void testCareNotificationsReachObservers() {
    std::cout << "Running test: testCareNotificationsReachObservers..." << std::endl;

    DummyPlant prototype("CareCheck");
    PlantInstance plant(&prototype);
    StockItem stock("Care Item", 15.0, &plant);
    NullMediator mediator;
    Staff staff(7, &mediator);

    staff.observePlant(&plant);

    const bool initialAvailability = stock.getIsAvailible();

    plant.setWaterLevel(5);
    plant.setNutrientLevel(5);
    plant.applyGrowthTick();

    assertEqInt(staff.getCareReminderCount(), 1,
                "Care events should add a reminder for the assigned staff member");
    assertTrue(staff.getCareReminders().back().find("CareCheck") != std::string::npos,
               "Reminder message should reference the plant type");

    // Ensure stock item ignores care notifications.
    assertTrue(stock.getIsAvailible() == initialAvailability,
               "Stock item availability should remain unchanged by care events");
}

void testCareNotificationsThrottled() {
    std::cout << "Running test: testCareNotificationsThrottled..." << std::endl;

    DummyPlant prototype("Throttle");
    PlantInstance plant(&prototype);
    NullMediator mediator;
    Staff staff(11, &mediator);
    staff.observePlant(&plant);

    plant.setWaterLevel(5);
    plant.setNutrientLevel(5);
    plant.applyGrowthTick();

    assertEqInt(staff.getCareReminderCount(), 1,
                "First care alert should be recorded");

    plant.applyGrowthTick(); // Repeated stress should not duplicate alert.
    assertEqInt(staff.getCareReminderCount(), 1,
                "Repeated stress should not spam care reminders");

    plant.setWaterLevel(90);
    plant.setNutrientLevel(90);
    plant.applyGrowthTick(); // Resets throttle.

    plant.setWaterLevel(5);
    plant.applyGrowthTick();
    assertEqInt(staff.getCareReminderCount(), 2,
                "Care alert should trigger again after recovery");
}

void testStaffIgnoresUntrackedPlants() {
    std::cout << "Running test: testStaffIgnoresUntrackedPlants..." << std::endl;

    DummyPlant observedProto("Observed");
    DummyPlant otherProto("Other");
    PlantInstance observed(&observedProto);
    PlantInstance other(&otherProto);
    NullMediator mediator;
    Staff staff(22, &mediator);

    staff.observePlant(&observed);
    other.attach(&staff); // Staff was not asked to track this plant.

    observed.setWaterLevel(5);
    observed.applyGrowthTick();
    assertEqInt(staff.getCareReminderCount(), 1,
                "Tracked plant should generate a reminder");

    other.setWaterLevel(5);
    other.applyGrowthTick();
    assertEqInt(staff.getCareReminderCount(), 1,
                "Untracked plant should not generate reminders");

    other.detach(&staff);
}

void testStockHandlesPlantDestruction() {
    std::cout << "Running test: testStockHandlesPlantDestruction..." << std::endl;

    DummyPlant prototype("ShortLived");
    StockItem stock("Ephemeral", 12.0, nullptr);

    {
        PlantInstance transient(&prototype);
        stock.setPlant(&transient);
        assertTrue(stock.getplant() == &transient, "Stock should bind to the transient plant");
    }

    assertTrue(stock.getplant() == nullptr, "Stock should release reference when plant is destroyed");
    assertTrue(!stock.getIsAvailible(), "Stock should mark itself unavailable after plant destruction");
}

} // namespace

int main() {
    int testsPassed = 0;
    int baseline = failures;

    testAttachDetachObservers();
    if (failures == baseline) { ++testsPassed; }
    baseline = failures;

    testCareNotificationsReachObservers();
    if (failures == baseline) { ++testsPassed; }
    baseline = failures;

    testCareNotificationsThrottled();
    if (failures == baseline) { ++testsPassed; }
    baseline = failures;

    testStaffIgnoresUntrackedPlants();
    if (failures == baseline) { ++testsPassed; }
    baseline = failures;

    testStockHandlesPlantDestruction();
    if (failures == baseline) { ++testsPassed; }

    std::cout << "\n---------------------------\n";
    std::cout << "     TEST SUMMARY          \n";
    std::cout << " Tests Passed: " << testsPassed << " / 5" << std::endl;
    std::cout << "---------------------------\n";

    if (failures == 0) {
        return 0;
    }
    std::cerr << "[FAIL] " << failures << " test(s) failed." << std::endl;
    return 1;
}
