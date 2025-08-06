/**
 * @file template_method.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Template Method pattern implementation
 * @details
 * Defines an algorithm skeleton, allowing subclasses to override steps without changing structure.
 *
 * @section features Key Features
 * - Fixed algorithm sequence with customizable steps.
 * - Common for workflow definitions and lifecycle hooks.
 *
 * @section usage Example Usage
 * ```cpp
 * struct Base {
 *     void run() { step1(); step2(); }
 *     virtual void step1() = 0;
 *     virtual void step2() = 0;
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

class TemplateBase {
public:
    virtual ~TemplateBase() = default;
    void run() {
        step1();
        step2();
    }

protected:
    virtual void step1() = 0;
    virtual void step2() = 0;
};

} // namespace gofpp
