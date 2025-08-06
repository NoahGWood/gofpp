#include <NTest.h>
#include <gofpp/behavioral/interpreter.hpp>

using namespace gofpp;

struct Number : Expression<int> {
    int value;
    Number(int v) : value(v) {}
    int interpret() override { return value; }
};

struct Add : Expression<int> {
    Expression<int>& left;
    Expression<int>& right;
    Add(Expression<int>& l, Expression<int>& r) : left(l), right(r) {}
    int interpret() override { return left.interpret() + right.interpret(); }
};

TEST(Interpreter_EvaluatesExpression) {
    Number n1(5), n2(3);
    Add sum(n1, n2);
    ASSERT_EQ(sum.interpret(), 8);
}

int main() { return NTest::run_all(); }
