#include <NTest.h>
#include <gofpp/behavioral/observer.hpp>

using namespace gofpp;

struct TestEvent { int data; };

TEST(Observer_Notify) {
    Observable<TestEvent> obs;
    bool called = false;

    int id = obs.subscribe([&](const TestEvent& e) {
        ASSERT_EQ(e.data, 42);
        called = true;
    });

    obs.notify({42});
    ASSERT_TRUE(called);
}

TEST(Observer_Unsubscribe) {
    Observable<TestEvent> obs;
    bool called = false;

    int id = obs.subscribe([&](const TestEvent&) { called = true; });
    obs.unsubscribe(id);
    obs.notify({1});
    ASSERT_FALSE(called);
}

int main() {
    return NTest::run_all();
}
