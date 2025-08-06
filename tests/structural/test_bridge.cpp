#include <NTest.h>
#include <gofpp/structural/bridge.hpp>

using namespace gofpp;

struct RendererImpl {
    virtual ~RendererImpl() = default;
    virtual int draw() = 0;
};

struct GLRenderer : RendererImpl {
    int draw() override { return 1; }
};

struct VulkanRenderer : RendererImpl {
    int draw() override { return 2; }
};

class Renderer : public Bridge<RendererImpl> {
public:
    using Bridge::Bridge;
    int render() { return impl->draw(); }
};

TEST(Bridge_SwitchImplementations) {
    Renderer r(std::make_unique<GLRenderer>());
    ASSERT_EQ(r.render(), 1);

    r.setImpl(std::make_unique<VulkanRenderer>());
    ASSERT_EQ(r.render(), 2);
}

int main() { return NTest::run_all(); }
