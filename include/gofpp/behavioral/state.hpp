/**
 * @file state.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ State pattern implementation
 * @details
 * Provides a generic state machine for mode-driven behavior.
 *
 * @section features Key Features
 * - `State<Context>` base class with `enter()`, `update()`, `exit()`.
 * - `StateMachine<Context>` manages transitions and lifecycle.
 *
 * @section usage Example Usage
 * ```cpp
 * struct Context { int data = 0; };
 *
 * struct PlayState : gofpp::State<Context> {
 *     void enter(Context& ctx) override { ctx.data = 1; }
 *     void update(Context& ctx) override { ctx.data++; }
 * };
 *
 * gofpp::StateMachine<Context> sm;
 * sm.changeState(std::make_unique<PlayState>());
 * sm.update(); // data increments
 * ```
 *
 * @version 0.1
 * @date 2025-08-05
 * @copyright
 * GPLv3 License - Copyright (c) 2025 Noah G. Wood
 */

#pragma once
#include <memory>

namespace gofpp {

template <typename Context>
class State {
public:
    virtual ~State() = default;
    virtual void enter(Context&) {}
    virtual void update(Context&) {}
    virtual void exit(Context&) {}
};

template <typename Context>
class StateMachine {
public:
    explicit StateMachine(Context ctx = Context{}) : context(std::move(ctx)) {}

    void changeState(std::unique_ptr<State<Context>> newState) {
        if (state) state->exit(context);
        state = std::move(newState);
        if (state) state->enter(context);
    }

    void update() {
        if (state) state->update(context);
    }

    Context& getContext() { return context; }

private:
    std::unique_ptr<State<Context>> state;
    Context context;
};

} // namespace gofpp
