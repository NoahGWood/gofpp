#include <NTest.h>
#include <gofpp/structural/proxy.hpp>

struct Service {
    virtual ~Service() = default;
    virtual int request() = 0;
};

struct RealService : Service {
    int request() override { return 42; }
};

struct ProxyService : Service {
    RealService real;
    int request() override { return real.request(); }
};

TEST(Proxy_DelegatesToRealService) {
    ProxyService proxy;
    ASSERT_EQ(proxy.request(), 42);
}

int main() { return NTest::run_all(); }
