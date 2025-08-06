#pragma once
#include <mutex>

namespace gofpp
{
    // Default threading policy (single-threaded = no lock)
    struct SingleThreaded {
        struct Lock {
            Lock() {}
            template <typename T>
            Lock(const T&) {} // Accepts any argument but does nothing
        };
    };
    
    struct MultiThreaded {
        std::mutex m;
        struct Lock {
            std::unique_lock<std::mutex> lock;
            Lock(MultiThreaded& mt) : lock(mt.m) {}
        };
    };
} // namespace gofpp
