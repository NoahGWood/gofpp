#include <cmath>
#include <imgui.h>
#include <gofpp.hpp>
#include <app_facade.hpp>
#include <calc_command.hpp>
#include <calc_memento.hpp>
#include <history.hpp>
#include <states.hpp>
struct UIPanel {
    virtual void render() = 0;
    virtual ~UIPanel() = default;
};

struct CalculatorPanel : UIPanel {
    double& result;
    double& input;
    gofpp::CommandStack& history;
    gofpp::Observable<HistoryEvent>& events;
    CalculatorState* state;
    CalculatorPanel(double& r, double& i, gofpp::CommandStack& h,
                    gofpp::Observable<HistoryEvent>& e, CalculatorState* s)
        : result(r), input(i), history(h), events(e), state(s) {}

    void render() override {
        ImGui::Text("Result: %.2f", result);
        ImGui::InputDouble("Input", &input);
        state->renderUI(result, input, history, events);
        if (ImGui::Button("Undo")) history.undo();
        ImGui::SameLine();
        if (ImGui::Button("Redo")) history.redo();
    }
};

struct HistoryPanel : UIPanel {
    HistoryObserver& observer;
    HistoryPanel(HistoryObserver& o) : observer(o) {}
    void render() override {
        ImGui::BeginChild("History", ImVec2(0, 0), true);
        for (auto& log : observer.logs)
            ImGui::TextUnformatted(log.c_str());
        ImGui::EndChild();
    }
};

static double result = 0.0;
static double input = 0.0;

int main() {
    AppFacade app("GoF++ Calculator", 500, 400);


    gofpp::CommandStack history;
    gofpp::Observable<HistoryEvent> events;
    HistoryObserver historyObs;
    events.subscribe(&historyObs);

    BasicState basicState;
    ScientificState scientificState;
    CalculatorState* currentState = &basicState;

    CalculatorPanel calcPanel(result, input, history, events, currentState);
    HistoryPanel histPanel(historyObs);

    gofpp::Memento<double> savedState(result);

    bool running = true;
    SDL_Event e;

    while (running) {
        while (SDL_PollEvent(&e)) {
            ImGui_ImplSDL2_ProcessEvent(&e);
            if (e.type == SDL_QUIT) running = false;
        }

        app.newFrame();

        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::MenuItem("Basic Mode")) currentState = &basicState;
            if (ImGui::MenuItem("Scientific Mode")) currentState = &scientificState;
            if (ImGui::MenuItem("Save State")) savedState = gofpp::Memento<double>(result);
            if (ImGui::MenuItem("Restore State")) result = savedState.state;
            ImGui::EndMainMenuBar();
        }

        ImGui::Begin("Calculator");
        calcPanel.render();
        ImGui::End();

        ImGui::Begin("History");
        histPanel.render();
        ImGui::End();

        app.render();
    }

    return 0;
}
