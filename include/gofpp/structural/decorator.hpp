/**
 * @file decorator.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Decorator pattern implementation
 * @details
 * Dynamically add behavior to objects without modifying their code.
 *
 * @section features Key Features
 * - Wrap objects to extend functionality at runtime.
 * - Stackable: multiple decorators can be applied in sequence.
 *
 * @section usage Example Usage
 * ```cpp
 * struct Component { virtual int cost() = 0; virtual ~Component() = default; };
 * struct BaseItem : Component { int cost() override { return 10; } };
 * struct BonusDecorator : Component {
 *     Component& inner;
 *     BonusDecorator(Component& c) : inner(c) {}
 *     int cost() override { return inner.cost() + 5; }
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
 * @brief Base decorator interface wrapping components of the same type.
 */
template <typename Component>
class IDecorator : public Component {
public:
    explicit IDecorator(Component& inner) : inner(inner) {}
protected:
    Component& inner;
};

} // namespace gofpp
