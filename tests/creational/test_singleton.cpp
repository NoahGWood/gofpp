#include <NTest.h>
#include <gofpp/creational/singleton.hpp>

class TestSingleton : public gofpp::Singleton<TestSingleton> {
public:
    int value = 0;
};

TEST(Singleton_Identity) {
    auto& a = TestSingleton::Instance();
    auto& b = TestSingleton::Instance();
    ASSERT_EQ(&a, &b);
}

TEST(Singleton_StatePersistence) {
    auto& a = TestSingleton::Instance();
    a.value = 123;
    auto& b = TestSingleton::Instance();
    ASSERT_EQ(b.value, 123);
}

int main() {
    return NTest::run_all();
}
