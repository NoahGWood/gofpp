/**
 * @file strategy.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Strategy pattern implementation
 * @details
 * Encapsulates interchangeable algorithms for runtime selection.
 *
 * @section features Key Features
 * - Switch strategies dynamically.
 * - Decouples algorithm from context.
 *
 * @section usage Example Usage
 * ```cpp
 * struct SortStrategy { virtual void sort(std::vector<int>&) = 0; };
 * struct QuickSort : SortStrategy { void sort(std::vector<int>&) override { } };
 * struct BubbleSort : SortStrategy { void sort(std::vector<int>&) override { }  };
 *
 * class Context {
 *     std::unique_ptr<SortStrategy> strategy;
 * public:
 *     void setStrategy(std::unique_ptr<SortStrategy> s) { strategy = std::move(s); }
 *     void execute(std::vector<int>& data) { strategy->sort(data); }
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

template <typename Strategy>
class Context {
public:
    void setStrategy(std::unique_ptr<Strategy> s) { strategy = std::move(s); }
    template <typename... Args>
    void execute(Args&&... args) {
        if (strategy) strategy->execute(std::forward<Args>(args)...);
    }
private:
    std::unique_ptr<Strategy> strategy;
};

} // namespace gofpp
