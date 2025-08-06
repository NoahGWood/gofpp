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
    template<typename Event, typename ThreadPolicy = SingleThreaded>
    class Observable : private ThreadPolicy {
        public:
            using Handler = std::function<void(const Event& e)>;

            int subscribe(Handler handler) {
                typename ThreadPolicy::Lock lock(*this);
                int id = next_id++;
                handlers[id] = std::move(handler);
                return id;
            }

            void unsubscribe(int id) {
                typename ThreadPolicy::Lock lock(*this);
                handlers.erase(id);
            }

            void notify(const Event& event) {
                typename ThreadPolicy::Lock lock(*this);
                for (auto& [_, handler] : handlers) {
                    handler(event);
                }
            }

        private:
            std::unordered_map<int, Handler> handlers;
            int next_id = 0;
    };
} // namespace gofpp
