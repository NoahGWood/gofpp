#include <NTest.h>
#include <gofpp/structural/composite.hpp>

using namespace gofpp;

struct TestNode : Composite<TestNode> {
    int count = 0;
    void operation() override { count++; Composite<TestNode>::operation(); }
};

TEST(Composite_RecursiveOperation) {
    TestNode root, child1, child2;
    root.add(&child1);
    root.add(&child2);

    root.operation();

    ASSERT_EQ(root.count, 1);
    ASSERT_EQ(child1.count, 1);
    ASSERT_EQ(child2.count, 1);
}

int main() { return NTest::run_all(); }
