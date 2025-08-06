/**
 * @file bridge.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Bridge pattern implementation
 * @details
 * Separates abstraction from implementation, enabling interchangeable backends (e.g., OpenGL, Vulkan).
 *
 * @section features Key Features
 * - Abstraction holds pointer to implementation interface.
 * - Swap implementations at runtime (mock, real, different APIs).
 *
 * @section usage Example Usage
 * ```cpp
 * struct RendererImpl {
 *     virtual void draw() = 0;
 *     virtual ~RendererImpl() = default;
 * };
 *
 * struct OpenGLRenderer : RendererImpl {
 *     void draw() override { ...  }
 * };
 *
 * class Renderer {
 *     std::unique_ptr<RendererImpl> impl;
 * public:
 *     Renderer(std::unique_ptr<RendererImpl> i) : impl(std::move(i)) {}
 *     void render() { impl->draw(); }
 * };
 * ```
 *
 * @version 0.1
 * @date 2025-08-05
 * @copyright
 * GPLv3 License - Copyright (c) 2025 Noah G. Wood
 */

#pragma once
#include <memory>

namespace gofpp {

template <typename Impl>
class Bridge {
public:
    explicit Bridge(std::unique_ptr<Impl> impl) : impl(std::move(impl)) {}
    void setImpl(std::unique_ptr<Impl> newImpl) { impl = std::move(newImpl); }
protected:
    std::unique_ptr<Impl> impl;
};

} // namespace gofpp
