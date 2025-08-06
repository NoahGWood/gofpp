/**
 * @file observer.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Observer pattern implementation
 * @details
 * Provides a simple publish/subscribe event system with optional threading policy.
 *
 * @section features Key Features
 * - Subscribe/unsubscribe using integer IDs.
 * - RAII-friendly, no manual memory management.
 * - Thread-policy configurable (SingleThreaded or MultiThreaded).
 *
 * @section usage Example Usage
 * ```cpp
 * struct ClickEvent { int x, y; };
 * gofpp::Observable<ClickEvent> clicks;
 *
 * int id = clicks.subscribe([](const ClickEvent& e){
 *     std::cout << "Clicked at " << e.x << "," << e.y << "\n";
 * });
 *
 * clicks.notify({100, 200});
 * clicks.unsubscribe(id);
 * ```
 *
 * @section threading Threading
 * - Default: `SingleThreaded` (no locking).
 * - Optional: `MultiThreaded` (mutex-protected).
 *
 * 
 * @version 0.1
 * @date 2025-08-05 
 * @copyright
 * GPLv3 License - Copyright (c) 2025 Noah G. Wood
 */
#pragma once
#include <functional>
#include <unordered_map>
#include <mutex>
#include <gofpp/threading.hpp>

namespace gofpp
{
    // Generic Observer interface
    template<typename T>
    class Observer {
    public:
        virtual ~Observer() = default;
        virtual void onNotify(const T& event) = 0;
    };

    // Observable (subject)
    template<typename T, typename ThreadPolicy = SingleThreaded>
    class Observable {
    public:
        void subscribe(Observer<T>* obs) {
            observers.push_back(obs);
        }

        void unsubscribe(Observer<T>* obs) {
            observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
        }

        void notify(const T& event) {
            for (auto* obs : observers) {
                obs->onNotify(event);
            }
        }

    private:
        std::vector<Observer<T>*> observers;
    };    
} // namespace gofpp
