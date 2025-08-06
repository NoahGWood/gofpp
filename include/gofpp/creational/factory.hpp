/**
 * @file factory.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Factory pattern implementation
 * @details
 * Provides a type-safe registry for creating polymorphic objects by string key.
 * 
 * @section features Key Features
 * - Register derived types at runtime with string identifiers.
 * - Create instances of registered types using `std::unique_ptr`.
 * - Thread-policy configurable for concurrent registration and creation.
 *
 * @section usage Example Usage
 * ```cpp
 * struct Shape { virtual void draw() = 0; virtual ~Shape() = default; };
 * struct Circle : Shape { void draw() override { ... } };
 * struct Square : Shape { void draw() override { ... } };
 * gofpp::Factory<Shape> factory;
 * factory.registerType<Circle>("circle");
 * factory.registerType<Square>("square");
 *
 * auto shape = factory.create("circle");
 * shape->draw();
 * ```
 *
 * @section threading Threading
 * - Default: `SingleThreaded` (no locking).
 * - Optional: `MultiThreaded` (mutex-protected).
 * 
 * @version 0.1
 * @date 2025-08-05 
 * @copyright
 * GPLv3 License - Copyright (c) 2025 Noah G. Wood
 */

#pragma once
#include <functional>
#include <unordered_map>
#include <memory>
#include <string>
#include <gofpp/threading.hpp>

namespace gofpp {

template <typename Base, typename ThreadPolicy = SingleThreaded>
class Factory : private ThreadPolicy {
public:
    using Creator = std::function<std::unique_ptr<Base>()>;

    template <typename Derived>
    void registerType(const std::string& key) {
        typename ThreadPolicy::Lock lock(*this);
        creators[key] = []() -> std::unique_ptr<Base> {
            return std::make_unique<Derived>();
        };
    }

    std::unique_ptr<Base> create(const std::string& key) {
        typename ThreadPolicy::Lock lock(*this);
        auto it = creators.find(key);
        if (it != creators.end()) {
            return it->second();
        }
        return nullptr;
    }

private:
    std::unordered_map<std::string, Creator> creators;
};

} // namespace gofpp
