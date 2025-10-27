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

    plant.attach(&stock);
    plant.attach(&staff);

    plant.setState(std::make_unique<MatureState>());

    assertTrue(stock.getIsAvailible(), "Stock item should remain available after maturity");
    assertEqStr(stock.getDisplayStatus(), "Plant ready for sale",
                "Stock item should reflect availability change message");
    assertEqInt(staff.getCareReminderCount(), 1,
                "Staff should receive an availability reminder when plant matures");

    plant.detach(&staff);
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

    plant.attach(&stock);
    plant.attach(&staff);

    plant.setWaterLevel(5);
    plant.setNutrientLevel(5);
    plant.applyGrowthTick();

    assertEqInt(staff.getCareReminderCount(), 2,
                "Staff should have availability and care reminders recorded");
    assertTrue(staff.getCareReminders().back().find("CareCheck") != std::string::npos,
               "Reminder message should reference the plant type");

    // Ensure stock item ignores care notifications.
    assertTrue(stock.getIsAvailible(), "Stock item availability should remain unchanged by care events");
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

    std::cout << "\n---------------------------\n";
    std::cout << "     TEST SUMMARY          \n";
    std::cout << " Tests Passed: " << testsPassed << " / 2" << std::endl;
    std::cout << "---------------------------\n";

    if (failures == 0) {
        return 0;
    }
    std::cerr << "[FAIL] " << failures << " test(s) failed." << std::endl;
    return 1;
}
