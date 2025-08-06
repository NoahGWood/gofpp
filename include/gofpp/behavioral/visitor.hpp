/**
 * @file visitor.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Visitor pattern implementation
 * @details
 * Separates algorithms from object structures; add new operations without modifying elements.
 *
 * @section features Key Features
 * - Double-dispatch: Visitor visits concrete elements.
 * - Useful for ASTs, UI trees, ECS entities.
 *
 * @section usage Example Usage
 * ```cpp
 * struct Element; struct Visitor { virtual void visit(Element&) = 0; };
 * struct Element { virtual void accept(Visitor&) = 0; };
 * ```
 *
 * @version 0.1
 * @date 2025-08-05
 * @copyright
 * GPLv3 License - Copyright (c) 2025 Noah G. Wood
 */

#pragma once

namespace gofpp {

template <typename ElementType>
class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visit(ElementType&) = 0;
};

template <typename VisitorType>
class Visitable {
public:
    virtual ~Visitable() = default;
    virtual void accept(VisitorType& visitor) = 0;
};

} // namespace gofpp
