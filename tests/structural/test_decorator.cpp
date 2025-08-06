#include <NTest.h>
#include <gofpp/structural/decorator.hpp>


using namespace gofpp;

struct Component {
    virtual ~Component() = default;
    virtual int cost() = 0;
};

struct BaseItem : Component {
    int cost() override { return 10; }
};

struct BonusDecorator : IDecorator<Component> {
    BonusDecorator(Component& c) : IDecorator<Component>(c) {}
    int cost() override { return inner.cost() + 5; }
};

TEST(Decorator_ExtendsBehavior) {
    BaseItem base;
    BonusDecorator decorated(base);
    ASSERT_EQ(decorated.cost(), 15);
}

int main() { return NTest::run_all(); }