#include <NTest.h>
#include <gofpp/behavioral/state.hpp>

using namespace gofpp;

struct Context { int value = 0; };

struct IncrementState : State<Context> {
    void enter(Context& ctx) override { ctx.value = 1; }
    void update(Context& ctx) override { ctx.value += 2; }
};

struct ResetState : State<Context> {
    void enter(Context& ctx) override { ctx.value = 0; }
};

TEST(State_ChangeAndUpdate) {
    StateMachine<Context> sm;

    sm.changeState(std::make_unique<IncrementState>());
    ASSERT_EQ(sm.getContext().value, 1);

    sm.update();
    ASSERT_EQ(sm.getContext().value, 3);

    sm.changeState(std::make_unique<ResetState>());
    ASSERT_EQ(sm.getContext().value, 0);
}

int main() {
    return NTest::run_all();
}
