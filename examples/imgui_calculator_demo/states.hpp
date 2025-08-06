#pragma once
#include <gofpp.hpp>
#include <imgui.h>
#include <calc_command.hpp>

// Abstract state
struct CalculatorState {
    virtual ~CalculatorState() = default;
    virtual void renderUI(double& result, double& input,
                          gofpp::CommandStack& history,
                          gofpp::Observable<HistoryEvent>& events) = 0;
};

// Basic calculator (add, subtract, multiply, divide)
struct BasicState : CalculatorState {
    void renderUI(double& result, double& input,
                  gofpp::CommandStack& history,
                  gofpp::Observable<HistoryEvent>& events) override {
        if (ImGui::Button("+")) {
            history.doCommand(std::make_unique<CalcCommand>(result, input, '+'));
            events.notify({ "Added " + std::to_string(input) });
        }
        ImGui::SameLine();
        if (ImGui::Button("-")) {
            history.doCommand(std::make_unique<CalcCommand>(result, input, '-'));
            events.notify({ "Subtracted " + std::to_string(input) });
        }
        ImGui::SameLine();
        if (ImGui::Button("*")) {
            history.doCommand(std::make_unique<CalcCommand>(result, input, '*'));
            events.notify({ "Multiplied by " + std::to_string(input) });
        }
        ImGui::SameLine();
        if (ImGui::Button("/")) {
            history.doCommand(std::make_unique<CalcCommand>(result, input, '/'));
            events.notify({ "Divided by " + std::to_string(input) });
        }
    }
};

// Scientific calculator (sqrt, pow2)
struct ScientificState : CalculatorState {
    void renderUI(double& result, double& input,
                  gofpp::CommandStack& history,
                  gofpp::Observable<HistoryEvent>& events) override {
        if (ImGui::Button("sqrt")) {
            history.doCommand(std::make_unique<CalcCommand>(result, std::sqrt(input), '+'));
            events.notify({ "Square root of " + std::to_string(input) });
        }
        ImGui::SameLine();
        if (ImGui::Button("pow2")) {
            history.doCommand(std::make_unique<CalcCommand>(result, input * input, '+'));
            events.notify({ "Squared " + std::to_string(input) });
        }
    }
};
