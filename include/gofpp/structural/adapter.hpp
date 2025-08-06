/**
 * @file adapter.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Adapter pattern implementation
 * @details
 * Wraps an existing class with a compatible interface.
 *
 * @section features Key Features
 * - Adapts incompatible APIs without modifying existing code.
 * - Supports both class and object adapters.
 *
 * @section usage Example Usage
 * ```cpp
 * struct LegacyRenderer { void oldDraw() { ... } };
 * struct IRenderer { virtual void draw() = 0; };
 *
 * struct RendererAdapter : IRenderer {
 *     LegacyRenderer& legacy;
 *     RendererAdapter(LegacyRenderer& l) : legacy(l) {}
 *     void draw() override { legacy.oldDraw(); }
 * };
 * ```
 *
 * @version 0.1
 * @date 2025-08-05
 * @copyright
 * GPLv3 License - Copyright (c) 2025 Noah G. Wood
 */

#pragma once

namespace gofpp {

/**
 * @brief Marker interface for adapters converting legacy APIs to new ones.
 */
template <typename Target>
class IAdapter {
public:
    virtual ~IAdapter() = default;
    virtual Target& getAdapted() = 0;
};

} // namespace gofpp
