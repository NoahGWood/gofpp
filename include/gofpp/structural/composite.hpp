/**
 * @file composite.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Composite pattern implementation
 * @details
 * Allows tree structures (e.g., scene graphs) where components and composites are treated uniformly.
 *
 * @section features Key Features
 * - Hierarchical parent/child relationships.
 * - Recursive `operation()` for tree traversal.
 * - Ideal for ECS entities or UI widget trees.
 *
 * @section usage Example Usage
 * ```cpp
 * struct Node : gofpp::Composite<Node> {
 *     void operation() override { ... }
 * };
 *
 * Node parent;
 * Node child;
 * parent.add(&child);
 * parent.operation(); // Calls child.operation() recursively
 * ```
 *
 * @version 0.1
 * @date 2025-08-05
 * @copyright
 * GPLv3 License - Copyright (c) 2025 Noah G. Wood
 */

#pragma once
#include <vector>
#include <algorithm>

namespace gofpp {

template <typename T>
class Composite {
public:
    virtual ~Composite() = default;

    void add(T* child) {
        children.push_back(child);
    }

    void remove(T* child) {
        children.erase(std::remove(children.begin(), children.end(), child), children.end());
    }

    virtual void operation() {
        for (auto* child : children) {
            child->operation();
        }
    }

protected:
    std::vector<T*> children;
};

} // namespace gofpp
