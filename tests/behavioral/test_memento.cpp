#include <NTest.h>
#include <gofpp/behavioral/memento.hpp>

using namespace gofpp;

struct Originator {
    int state = 0;
    Memento<int> save() { return Memento<int>(state); }
    void restore(const Memento<int>& m) { state = m.state; }
};

TEST(Memento_SaveAndRestore) {
    Originator o;
    o.state = 42;

    auto snapshot = o.save();
    o.state = 0;
    o.restore(snapshot);

    ASSERT_EQ(o.state, 42);
}

int main() { return NTest::run_all(); }
