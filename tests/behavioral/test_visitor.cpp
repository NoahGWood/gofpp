#include <NTest.h>
#include <gofpp/behavioral/visitor.hpp>

using namespace gofpp;

struct ConcreteElement;
struct ConcreteVisitor : Visitor<ConcreteElement> {
    bool visited = false;
    void visit(ConcreteElement&) override { visited = true; }
};

struct ConcreteElement : Visitable<Visitor<ConcreteElement>> {
    void accept(Visitor<ConcreteElement>& v) override { v.visit(*this); }
};

TEST(Visitor_VisitsElement) {
    ConcreteElement element;
    ConcreteVisitor visitor;

    element.accept(visitor);

    ASSERT_TRUE(visitor.visited);
}

int main() { return NTest::run_all(); }
