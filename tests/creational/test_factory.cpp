#include <gofpp/creational/factory.hpp>
#include <NTest.h>

using namespace gofpp;

// Base and derived classes for testing
struct Shape { virtual ~Shape() = default; virtual int sides() const = 0; };
struct Circle : Shape { int sides() const override { return 0; } };
struct Square : Shape { int sides() const override { return 4; } };

TEST(Factory_RegisterAndCreate) {
    Factory<Shape> factory;

    factory.registerType<Circle>("circle");
    factory.registerType<Square>("square");

    auto c = factory.create("circle");
    ASSERT_TRUE(c != nullptr);
    ASSERT_EQ(c->sides(), 0);

    auto s = factory.create("square");
    ASSERT_TRUE(s != nullptr);
    ASSERT_EQ(s->sides(), 4);
}

TEST(Factory_UnknownKeyReturnsNull) {
    Factory<Shape> factory;
    auto missing = factory.create("triangle");
    ASSERT_TRUE(missing == nullptr);
}

int main() {
    return NTest::run_all();
}
