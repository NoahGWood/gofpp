#include <NTest.h>
#include <gofpp/behavioral/observer.hpp>

struct TestEvent {
    int data;
};

// Simple observer for testing
struct TestObserver : gofpp::Observer<TestEvent> {
    bool called = false;
    int lastData = 0;

    void onNotify(const TestEvent& e) override {
        called = true;
        lastData = e.data;
    }
};

TEST(Observer_Notify) {
    gofpp::Observable<TestEvent> obs;
    TestObserver o;
    obs.subscribe(&o);

    obs.notify({42});
    ASSERT_TRUE(o.called);
    ASSERT_EQ(o.lastData, 42);
}

TEST(Observer_Unsubscribe) {
    gofpp::Observable<TestEvent> obs;
    TestObserver o;
    obs.subscribe(&o);

    obs.unsubscribe(&o);
    obs.notify({99});
    ASSERT_FALSE(o.called);
}

int main() { return NTest::run_all(); }
