#include <NTest.h>
#include <gofpp/structural/facade.hpp>

using namespace gofpp;

class SubsystemFacade : public IFacade {
    public:
    void initialize() override { init = true; }
    void shutdown() override { shut = true; }
    bool init = false, shut = false;
};

TEST(Facade_ControlsSubsystemLifecycle) {
    SubsystemFacade f;
    f.initialize();
    f.shutdown();
    ASSERT_TRUE(f.init);
    ASSERT_TRUE(f.shut);
}

int main() { return NTest::run_all(); }