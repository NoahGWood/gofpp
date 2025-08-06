#include <NTest.h>
#include <gofpp/creational/abstract_factory.hpp>

using namespace gofpp;

struct Product { virtual ~Product() = default; virtual int id() const = 0; };

struct ConcreteProductA : Product { int id() const override { return 1; } };
struct ConcreteProductB : Product { int id() const override { return 2; } };

struct FactoryA : IAbstractFactory<Product> {
    std::unique_ptr<Product> create() override { return std::make_unique<ConcreteProductA>(); }
};

struct FactoryB : IAbstractFactory<Product> {
    std::unique_ptr<Product> create() override { return std::make_unique<ConcreteProductB>(); }
};

TEST(AbstractFactory_CreatesCorrectProducts) {
    FactoryA fa;
    FactoryB fb;

    auto a = fa.create();
    auto b = fb.create();

    ASSERT_EQ(a->id(), 1);
    ASSERT_EQ(b->id(), 2);
}

int main() { return NTest::run_all(); }