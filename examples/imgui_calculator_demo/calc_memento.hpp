#pragma once
#include <gofpp/behavioral/memento.hpp>

// Stores and restores calculator state
struct CalcMemento {
    double value;
};

struct CalcOriginator {
    double result = 0.0;

    gofpp::Memento<double> save() {
        return gofpp::Memento<double>(result);
    }

    void restore(const gofpp::Memento<double>& m) {
        result = m.state;
    }
};
