/**
 * @file gofpp.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief Umbrella header for GoF++ patterns
 * @details
 * Includes all 23 Gang of Four design patterns provided by GoF++,
 * grouped into Creational, Structural, and Behavioral categories.
 *
 * @section usage Example Usage
 * ```cpp
 * #include <gofpp.hpp>
 * 
 * // Now you can use any GoF++ pattern without extra includes
 * auto& s = gofpp::Singleton<MyClass>::Instance();
 * ```
 *
 * @version 0.1
 * @date 2025-08-05
 * @copyright
 * GPLv3 License - Copyright (c) 2025 Noah G. Wood
 */

#pragma once

// Creational
#include <gofpp/creational/singleton.hpp>
#include <gofpp/creational/factory.hpp>
#include <gofpp/creational/abstract_factory.hpp>
#include <gofpp/creational/builder.hpp>
#include <gofpp/creational/prototype.hpp>

// Structural
#include <gofpp/structural/composite.hpp>
#include <gofpp/structural/bridge.hpp>
#include <gofpp/structural/mediator.hpp>
#include <gofpp/structural/adapter.hpp>
#include <gofpp/structural/decorator.hpp>
#include <gofpp/structural/facade.hpp>
#include <gofpp/structural/flyweight.hpp>
#include <gofpp/structural/proxy.hpp>

// Behavioral
#include <gofpp/behavioral/observer.hpp>
#include <gofpp/behavioral/command.hpp>
#include <gofpp/behavioral/state.hpp>
#include <gofpp/behavioral/chain_of_responsibility.hpp>
#include <gofpp/behavioral/strategy.hpp>
#include <gofpp/behavioral/template_method.hpp>
#include <gofpp/behavioral/iterator.hpp>
#include <gofpp/behavioral/memento.hpp>
#include <gofpp/behavioral/interpreter.hpp>
#include <gofpp/behavioral/visitor.hpp>
