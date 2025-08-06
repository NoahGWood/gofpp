#include <NTest.h>
#include <gofpp/behavioral/template_method.hpp>

using namespace gofpp;

struct ConcreteTemplate : TemplateBase {
    bool s1 = false, s2 = false;
    void step1() override { s1 = true; }
    void step2() override { s2 = true; }
};

TEST(TemplateMethod_ExecutesSteps) {
    ConcreteTemplate t;
    t.run();
    ASSERT_TRUE(t.s1);
    ASSERT_TRUE(t.s2);
}

int main() { return NTest::run_all(); }
