#include <NTest.h>
#include <gofpp/creational/prototype.hpp>

using namespace gofpp;

struct Shape : Prototype<Shape> {
    int sides = 0;
    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Shape>(*this);
    }
};

TEST(Prototype_CloneObject) {
    Shape original;
    original.sides = 5;

    auto copy = original.clone();
    ASSERT_EQ(copy->sides, 5);
}

int main() { return NTest::run_all(); }
