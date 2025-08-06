/**
 * @file mediator.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Mediator pattern implementation
 * @details
 * Central hub for communication between components (e.g., UI panels).
 *
 * @section features Key Features
 * - Components interact via Mediator, not directly with each other.
 * - Decouples complex dependency webs (e.g., Editor panels).
 *
 * @section usage Example Usage
 * ```cpp
 * struct PanelMediator {
 *     virtual void notify(const std::string& sender, const std::string& event) = 0;
 * };
 *
 * struct ConcreteMediator : PanelMediator {
 *     void notify(const std::string& sender, const std::string& event) override {
 *         // Handle communication
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
#include <string>

namespace gofpp {

class Mediator {
public:
    virtual ~Mediator() = default;
    virtual void notify(const std::string& sender, const std::string& event) = 0;
};

} // namespace gofpp
