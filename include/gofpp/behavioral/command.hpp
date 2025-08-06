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
        done.push_back(std::move(cmd));
        undone.clear(); // Clear redo history after new command
    }

    void undo() {        
        if (done.empty()) return;
        auto cmd = std::move(done.back());
        done.pop_back();
        cmd->undo();
        undone.push_back(std::move(cmd));
    }

    void redo() {
        if (undone.empty()) return;
        auto cmd = std::move(undone.back());
        undone.pop_back();
        cmd->execute();
        done.push_back(std::move(cmd));
    }

    
    bool canUndo() const { return !done.empty(); }
    bool canRedo() const { return !undone.empty(); }

    void clear() {
        done.clear();
        undone.clear();
    }

private:
    std::vector<std::unique_ptr<ICommand>> done;
    std::vector<std::unique_ptr<ICommand>> undone;
};

} // namespace gofpp
