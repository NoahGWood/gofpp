#pragma once
#include <gofpp/behavioral/command.hpp>

// Arithmetic command (supports undo)
struct CalcCommand : gofpp::ICommand {
    double& result;
    double value;
    char op;

    CalcCommand(double& res, double val, char oper)
        : result(res), value(val), op(oper) {}

    void execute() override {
        switch (op) {
            case '+': result += value; break;
            case '-': result -= value; break;
            case '*': result *= value; break;
            case '/': if (value != 0) result /= value; break;
        }
    }

    void undo() override {
        switch (op) {
            case '+': result -= value; break;
            case '-': result += value; break;
            case '*': if (value != 0) result /= value; break;
            case '/': result *= value; break;
        }
    }
};
