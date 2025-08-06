#include "NTest.h"
#include "gofpp/behavioral/chain_of_responsibility.hpp"

using namespace gofpp;

struct EvenHandler : Handler<int> {
    bool handle(const int& v) override { return v % 2 == 0 ? true : Handler::handle(v); }
};

struct PositiveHandler : Handler<int> {
    bool handle(const int& v) override { return v > 0 ? true : Handler::handle(v); }
};

TEST(ChainOfResponsibility_HandlesInChain) {
    EvenHandler even;
    PositiveHandler positive;

    even.setNext(&positive);

    ASSERT_TRUE(even.handle(2));  // Even handler handles
    ASSERT_TRUE(even.handle(3));  // Positive handler handles
    ASSERT_FALSE(even.handle(-1)); // None handle
}

int main() { return NTest::run_all(); }
