/**
 * @file memento.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Memento pattern implementation
 * @details
 * Stores snapshots of object state for undo/redo functionality.
 *
 * @section features Key Features
 * - Captures internal state without exposing details to external code.
 * - Often used with Command or State for undo systems.
 *
 * @section usage Example Usage
 * ```cpp
 * struct Originator {
 *     int state = 0;
 *     auto save() { return gofpp::Memento<int>(state); }
 *     void restore(const gofpp::Memento<int>& m) { state = m.state; }
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

template <typename State>
struct Memento {
    explicit Memento(const State& s) : state(s) {}
    State state;
};

} // namespace gofpp
