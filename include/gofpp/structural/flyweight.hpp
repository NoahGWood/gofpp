/**
 * @file flyweight.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Flyweight pattern implementation
 * @details
 * Shares heavy immutable data across multiple objects to reduce memory overhead.
 *
 * @section features Key Features
 * - Central registry of shared flyweight objects.
 * - Clients store lightweight state externally.
 *
 * @section usage Example Usage
 * ```cpp
 * struct Glyph { char character; };
 * class GlyphFactory {
 *     std::unordered_map<char, std::shared_ptr<Glyph>> pool;
 * public:
 *     std::shared_ptr<Glyph> get(char c) {
 *         if (!pool.count(c)) pool[c] = std::make_shared<Glyph>(Glyph{c});
 *         return pool[c];
 *     }
 * };
 * ```
 *
 * @version 0.1
 * @date 2025-08-05
 * @copyright
 * GPLv3 License - Copyright (c) 2025 Noah G. Wood
 */

#pragma once
#include <unordered_map>
#include <memory>

namespace gofpp {

template <typename Key, typename Value>
class FlyweightFactory {
public:
    std::shared_ptr<Value> get(const Key& key) {
        auto it = pool.find(key);
        if (it != pool.end()) return it->second;
        auto val = std::make_shared<Value>(Value{key});
        pool[key] = val;
        return val;
    }

private:
    std::unordered_map<Key, std::shared_ptr<Value>> pool;
};

} // namespace gofpp
