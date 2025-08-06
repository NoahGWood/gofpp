/**
 * @file prototype.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Prototype pattern implementation
 * @details
 * Enables cloning of objects without knowing their concrete type.
 *
 * @section features Key Features
 * - Each prototype defines `clone()` returning `std::unique_ptr`.
 * - Useful for prefabs, templates, and runtime cloning.
 *
 * @section usage Example Usage
 * ```cpp
 * struct Shape {
 *     virtual ~Shape() = default;
 *     virtual std::unique_ptr<Shape> clone() const = 0;
 * };
 *
 * struct Circle : Shape {
 *     std::unique_ptr<Shape> clone() const override {
 *         return std::make_unique<Circle>(*this);
 *     }
 * };
 *
 * Circle c1;
 * auto c2 = c1.clone();
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

template <typename T>
struct Prototype {
    virtual ~Prototype() = default;
    virtual std::unique_ptr<T> clone() const = 0;
};

} // namespace gofpp
