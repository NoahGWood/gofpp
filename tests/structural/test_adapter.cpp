#include <NTest.h>
#include <gofpp/structural/adapter.hpp>

using namespace gofpp;

struct LegacyService {
    int legacyOp() { return 77; }
};

struct Service {
    virtual int op() = 0;
};

struct ServiceAdapter : Service, IAdapter<LegacyService> {
    LegacyService legacy;
    LegacyService& getAdapted() override { return legacy; }
    int op() override { return legacy.legacyOp(); }
};

TEST(Adapter_WrapsLegacyService) {
    ServiceAdapter adapter;
    ASSERT_EQ(adapter.op(), 77);
    ASSERT_EQ(adapter.getAdapted().legacyOp(), 77);
}

int main() { return NTest::run_all(); }