#include <NTest.h>
#include <gofpp/structural/flyweight.hpp>

using namespace gofpp;

struct Glyph {
    char character;
};

TEST(Flyweight_SharedInstances) {
    FlyweightFactory<char, Glyph> factory;
    auto g1 = factory.get('A');
    auto g2 = factory.get('A');
    auto g3 = factory.get('B');

    ASSERT_EQ(g1->character, 'A');
    ASSERT_EQ(g2->character, 'A');
    ASSERT_EQ(g3->character, 'B');
    ASSERT_EQ(g1.get(), g2.get()); // same shared object
    ASSERT_NE(g1.get(), g3.get()); // different object
}

int main() { return NTest::run_all(); }
