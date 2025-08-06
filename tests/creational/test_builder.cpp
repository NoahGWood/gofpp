#include <NTest.h>
#include <gofpp/creational/builder.hpp>

using namespace gofpp;

struct Car { int wheels = 0; bool sunroof = false; };

struct CarBuilder : IBuilder<Car, CarBuilder> {
    Car car;
    CarBuilder& reset() override { car = Car{}; return *this; }
    CarBuilder& setWheels(int w) { car.wheels = w; return *this; }
    CarBuilder& addSunroof() { car.sunroof = true; return *this; }
    Car build() override { return car; }
};

TEST(Builder_ConstructsCar) {
    CarBuilder builder;
    Car c = builder.reset().setWheels(4).addSunroof().build();
    ASSERT_EQ(c.wheels, 4);
    ASSERT_TRUE(c.sunroof);
}

int main() { return NTest::run_all(); }