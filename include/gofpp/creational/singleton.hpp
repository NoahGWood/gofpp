/**
 * @file singleton.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Singleton pattern implementation
 * @details
 * Implements a thread-policy based Singleton.
 * 
 * ## Usage
 * ```cpp
 * class Logger : public gofpp::Singleton<Logger> {
 * public:
 *     void log(const std::string& msg) { std::cout << msg << "\n"; }
 * };
 *
 * Logger::Instance().log("Hello!");
 * ```
 *
 * ## Threading
 * Use `SingleThreaded` (default) or `MultiThreaded` policy.
 * 
 * @version 0.1
 * @date 2025-08-05
 * @copyright 
 * GPLv3 License - Copyright (c) 2025
 */

#pragma once
#include <mutex>

#include <gofpp/threading.hpp>
namespace gofpp
{
    template <typename T, typename ThreadPolicy = SingleThreaded>
    class Singleton : private ThreadPolicy {
    public:
        static T& Instance() {
            static T instance;
            return instance;
        }

        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;

    protected:
        Singleton() = default;
        ~Singleton() = default;
    };

} // namespace gofpp
