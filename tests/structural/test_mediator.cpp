#include <NTest.h>
#include <gofpp/structural/mediator.hpp>
#include <string>

using namespace gofpp;

struct TestMediator : Mediator {
    std::string lastEvent;
    void notify(const std::string& sender, const std::string& event) override {
        lastEvent = sender + ":" + event;
    }
};

TEST(Mediator_Notify) {
    TestMediator m;
    m.notify("PanelA", "Update");
    ASSERT_EQ(m.lastEvent, "PanelA:Update");
}

int main() { return NTest::run_all(); }
