/**
 * @file chain_of_responsibility.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Chain of Responsibility pattern implementation
 * @details
 * Allows a request to be passed along a chain of handlers until one handles it.
 *
 * @section features Key Features
 * - Decouples senders from receivers.
 * - Handlers can process or pass requests along.
 *
 * @section usage Example Usage
 * ```cpp
 * struct Handler {
 *     Handler* next = nullptr;
 *     virtual bool handle(int value) {
 *         return next ? next->handle(value) : false;
 *     }
 * };
 *
 * struct EvenHandler : Handler {
 *     bool handle(int value) override { return value % 2 == 0 ? true : Handler::handle(value); }
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

template <typename Request>
class Handler {
public:
    virtual ~Handler() = default;

    void setNext(Handler* nextHandler) { next = nextHandler; }

    virtual bool handle(const Request& req) {
        return next ? next->handle(req) : false;
    }

protected:
    Handler* next = nullptr;
};

} // namespace gofpp
