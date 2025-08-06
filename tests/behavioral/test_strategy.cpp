#include <NTest.h>
#include <gofpp/behavioral/strategy.hpp>

using namespace gofpp;

struct PrintStrategy {
    virtual void execute(const std::string& msg) = 0;
    virtual ~PrintStrategy() = default;
};

struct UpperPrint : PrintStrategy {
    void execute(const std::string& msg) override {
        for (char c : msg) putchar(::toupper(c));
    }
};

struct LowerPrint : PrintStrategy {
    void execute(const std::string& msg) override {
        for (char c : msg) putchar(::tolower(c));
    }
};

TEST(Strategy_SwitchAlgorithms) {
    Context<PrintStrategy> ctx;
    ctx.setStrategy(std::make_unique<UpperPrint>());
    ctx.execute("Hi\n");

    ctx.setStrategy(std::make_unique<LowerPrint>());
    ctx.execute("Hi\n");
}

int main() { return NTest::run_all(); }
