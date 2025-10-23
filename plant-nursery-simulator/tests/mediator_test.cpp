#include "../include/NurseryMediator.h"
#include "../include/Colleague.h"
#include <string>
#include <vector>
#include <iostream>

/*
TestColleague is a testing-only subclass of Colleague
that behaves the same way as the real colleagues (Customer, Staff, etc.)
but instead of printing messages to the console, it stores them in memory so we can check them in a test.
*/

class TestColleague : public Colleague {
public:
    TestColleague(int id, FloorMediator* mediator)
        : Colleague(mediator)
    {
        this->id_ = id;
    }

    int getID() const override {
        return this->id_;
    }

    void send(std::string message, int colleagueID) override {
        if (this->mediator == nullptr) {
            std::cerr << "[TestColleague] Mediator is null; cannot send." << std::endl;
            return;
        }
        this->mediator->distribute(message, this->id_, colleagueID);
    }

    void receive(std::string message) override {
        this->received_.push_back(message);
    }

    const std::vector<std::string>& received() const {
        return this->received_;
    }

private:
    int id_{-1};
    std::vector<std::string> received_;
};

static int failures = 0;

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

int main() {
    std::cout << "== Mediator Basic UNIT TESTS ==" << std::endl;

    NurseryMediator mediator;

    TestColleague alice(1, &mediator);
    TestColleague bob(2, &mediator);
    TestColleague charlie(3, &mediator);

    mediator.addColleague(&alice);
    mediator.addColleague(&bob);
    mediator.addColleague(&charlie);

    // 1) Direct: Alice -> Bob
    alice.send("hello bob", 2);
    ASSERT_EQ_INT((int)bob.received().size(), 1, "Bob receives one direct message.");
    ASSERT_EQ_STR(bob.received()[0], "hello bob", "Bob gets Alice's content.");
    ASSERT_EQ_INT((int)alice.received().size(), 0, "Alice should not receive her own direct message.");

    // 2) Broadcast: Bob -> all except Bob
    bob.send("broadcast from bob", -1);
    ASSERT_EQ_INT((int)alice.received().size(), 1, "Alice should have one message total (broadcast adds one).");
    ASSERT_EQ_INT((int)charlie.received().size(), 1, "Charlie should receive one broadcast message.");
    ASSERT_EQ_STR(alice.received()[0], "broadcast from bob", "Alice should receive broadcast content from Bob.");
    ASSERT_EQ_STR(charlie.received()[0], "broadcast from bob", "Charlie should receive broadcast content from Bob.");

    // 3) Missing recipient: Charlie -> 99 (no deliveries)
    charlie.send("to nowhere", 99);
    ASSERT_EQ_INT((int)alice.received().size(), 1, "Alice should not receive message sent to missing recipient.");
    ASSERT_EQ_INT((int)bob.received().size(), 1, "Bob should not receive message sent to missing recipient.");
    ASSERT_EQ_INT((int)charlie.received().size(), 1, "Charlie should not receive message sent to missing recipient.");

    if (failures == 0) {
        std::cout << "[PASS] All mediator unit tests passed." << std::endl;
        return 0;
    } else {
        std::cerr << "[FAIL] " << failures << " test(s) failed." << std::endl;
        return 1;
    }
}