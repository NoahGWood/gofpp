/**
 * @file iterator.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Iterator pattern implementation
 * @details
 * Encapsulates iteration logic for containers, providing a uniform interface.
 *
 * @section features Key Features
 * - Decouples traversal from container implementation.
 * - Supports forward iteration; extendable for bidirectional/random.
 *
 * @section usage Example Usage
 * ```cpp
 * gofpp::Iterator<std::vector<int>> it(myVector);
 * while(it.hasNext()) { std::cout << it.next(); }
 * ```
 *
 * @version 0.1
 * @date 2025-08-05
 * @copyright
 * GPLv3 License - Copyright (c) 2025 Noah G. Wood
 */

#pragma once
#include <cstddef>

namespace gofpp {

template <typename Container>
class Iterator {
public:
    explicit Iterator(Container& c) : container(c), index(0) {}
    bool hasNext() const { return index < container.size(); }
    auto& next() { return container[index++]; }

private:
    Container& container;
    size_t index;
};

} // namespace gofpp
