/**
 * @file command.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Command pattern implementation
 * @details
 * Encapsulates actions and supports undo/redo via a command stack.
 *
 * @section features Key Features
 * - Each command defines `execute()` and `undo()`.
 * - Central `CommandStack` manages history and undo/redo operations.
 * - RAII-friendly using `std::unique_ptr<ICommand>`.
 *
 * @section usage Example Usage
 * ```cpp
 * struct AddCommand : gofpp::ICommand {
 *     int& target; int value;
 *     AddCommand(int& t, int v) : target(t), value(v) {}
 *     void execute() override { target += value; }
 *     void undo() override { target -= value; }
 * };
 *
 * gofpp::CommandStack stack;
 * int x = 0;
 * stack.doCommand(std::make_unique<AddCommand>(x, 5)); // x = 5
 * stack.undo(); // x = 0
 * ```
 *
 * @version 0.1
 * @date 2025-08-05
 * @copyright
 * GPLv3 License - Copyright (c) 2025 Noah G. Wood
 */

#pragma once
#include <memory>
#include <vector>

namespace gofpp {

struct ICommand {
    virtual ~ICommand() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class CommandStack {
public:
    void doCommand(std::unique_ptr<ICommand> cmd) {
        cmd->execute();
        history.push_back(std::move(cmd));
    }

    void undo() {
        if (!history.empty()) {
            history.back()->undo();
            history.pop_back();
        }
    }

    bool empty() const { return history.empty(); }

private:
    std::vector<std::unique_ptr<ICommand>> history;
};

} // namespace gofpp
