/**
 * @file interpreter.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Interpreter pattern implementation
 * @details
 * Evaluates expressions defined by a grammar (simple arithmetic, boolean logic, etc.).
 *
 * @section features Key Features
 * - Defines abstract `Expression` interface.
 * - Concrete expressions implement `interpret(context)`.
 *
 * @section usage Example Usage
 * ```cpp
 * struct Number : gofpp::Expression<int> {
 *     int value;
 *     Number(int v) : value(v) {}
 *     int interpret() override { return value; }
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

template <typename Result>
class Expression {
public:
    virtual ~Expression() = default;
    virtual Result interpret() = 0;
};

} // namespace gofpp
