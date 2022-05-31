#include "InversePendulum.h"
#include <cmath>

State InversePendulum::getState() {
    return InversePendulum::state;
}

void InversePendulum::setState(State new_state) {
    InversePendulum::state = new_state;
}


void InversePendulum::iterate(double u, double time) {
    double Sy = sin(InversePendulum::state.t);
    double Cy = cos(InversePendulum::state.t);

    double x = InversePendulum::getState().x;
    double x_dot = InversePendulum::getState().x_dot;
    double t = InversePendulum::getState().t;
    double t_dot = InversePendulum::getState().t_dot;
    double m = InversePendulum::pend_mass;
    double M = InversePendulum::cart_mass;
    double L = InversePendulum::length;
    double d = InversePendulum::damping;
    double g = -9.81;

    double D = m * L * L * (M + m * (1 - pow(Cy, 2.0)));

    double dx_dt = x_dot;
    double dx_dot_dt = (1.f / D) * (-pow(m, 2.f)*pow(L, 2.f)*g*Cy*Sy +
                              m * pow(L, 2.f) * (m * L * pow(t_dot, 2.f) * Sy - d * x_dot)) + m * L * (1.f / D) * u;
    double dt_dt = t_dot;
    double dt_dot_dt = (1.f / D) * ((m + M) * m * g * L * Sy - m * L * Cy * (m * L * pow(t_dot, 2.f) * Sy - d * x_dot)) -
                 m * L * Cy * (1.f / D) * u;

    State new_state = State(x + dx_dt * time,
                            x_dot + dx_dot_dt * time,
                            t + dt_dt * time,
                            t_dot + dt_dot_dt * time);
    InversePendulum::setState(new_state);
}


State::State() {
    x = 0;
    x_dot = 0;
    t = 0;
    t_dot = 0;
}
