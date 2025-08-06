#pragma once
#include <gofpp/behavioral/observer.hpp>
#include <string>
#include <vector>

struct HistoryEvent {
    std::string description;
};

struct HistoryObserver : gofpp::Observer<HistoryEvent> {
    std::vector<std::string> logs;

    void onNotify(const HistoryEvent& event) override {
        logs.push_back(event.description);
    }

    void clear() {
        logs.clear();
    }
};
