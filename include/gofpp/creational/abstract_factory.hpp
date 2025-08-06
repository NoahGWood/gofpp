/**
 * @file abstract_factory.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Abstract Factory pattern implementation
 * @details
 * Allows creation of related object families without specifying exact concrete types.
 *
 * @section features Key Features
 * - Create related objects (e.g., UI widgets) via a unified interface.
 * - Combine with Factory for dynamic type registration.
 * - Thread-policy configurable.
 *
 * @section usage Example Usage
 * ```cpp
 * struct Button { virtual ~Button() = default; virtual const char* label() = 0; };
 * struct WinButton : Button { const char* label() override { return "Windows"; } };
 * struct MacButton : Button { const char* label() override { return "Mac"; } };
 *
 * struct UIFactory {
 *     virtual std::unique_ptr<Button> createButton() = 0;
 * };
 *
 * struct WinFactory : UIFactory {
 *     std::unique_ptr<Button> createButton() override { return std::make_unique<WinButton>(); }
 * };
 *
 * struct MacFactory : UIFactory {
 *     std::unique_ptr<Button> createButton() override { return std::make_unique<MacButton>(); }
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

/**
 * @brief Base interface for abstract factories creating product families.
*/
template <typename AbstractProduct>
class IAbstractFactory {
public:
    virtual ~IAbstractFactory() = default;
    virtual std::unique_ptr<AbstractProduct> create() = 0;
};
} // namespace gofpp
