/**
 * @file builder.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Builder pattern implementation
 * @details
 * Builds complex objects step-by-step, separating construction from representation.
 *
 * @section features Key Features
 * - Incrementally construct objects (e.g., GUI layouts, config objects).
 * - Reusable builders for different products.
 *
 * @section usage Example Usage
 * ```cpp
 * struct Car { int wheels = 0; bool sunroof = false; };
 *
 * class CarBuilder {
 * public:
 *     CarBuilder& setWheels(int w) { car.wheels = w; return *this; }
 *     CarBuilder& addSunroof() { car.sunroof = true; return *this; }
 *     Car build() { return car; }
 * private:
 *     Car car;
 * };
 *
 * Car c = CarBuilder().setWheels(4).addSunroof().build();
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
 * @brief Base interface for builders constructing objects step-by-step.
 */
template <typename Product, typename Derived>
class IBuilder {
public:
    virtual ~IBuilder() = default;
    virtual Derived& reset() = 0;
    virtual Product build() = 0;
};

} // namespace gofpp
