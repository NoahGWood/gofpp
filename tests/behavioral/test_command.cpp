#include <NTest.h>
#include <gofpp/behavioral/command.hpp>

using namespace gofpp;

struct AddCommand : ICommand {
    int& target;
    int value;
    AddCommand(int& t, int v) : target(t), value(v) {}
    void execute() override { target += value; }
    void undo() override { target -= value; }
};

TEST(Command_DoAndUndo) {
    int x = 0;
    CommandStack stack;

    stack.doCommand(std::make_unique<AddCommand>(x, 10));
    ASSERT_EQ(x, 10);

    stack.undo();
    ASSERT_EQ(x, 0);
}

TEST(Command_MultipleUndo) {
    int x = 0;
    CommandStack stack;

    stack.doCommand(std::make_unique<AddCommand>(x, 5));
    stack.doCommand(std::make_unique<AddCommand>(x, 3));
    ASSERT_EQ(x, 8);

    stack.undo();
    ASSERT_EQ(x, 5);

    stack.undo();
    ASSERT_EQ(x, 0);
}

int main() {
    return NTest::run_all();
}
