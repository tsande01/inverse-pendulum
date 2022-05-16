#include "InversePendulum.h"


InversePendulum::InversePendulum(float sled_position,
                                 float length_init,
                                 float mass_init,
                                 float theta) {
    state = State(sled_position, 0, theta, 0);
    mass = mass_init;
    length = length_init;
}

State InversePendulum::getState() {
    return InversePendulum::state;
}

State::State(float x_init, float x_dot_init, float t_init, float t_dot_init) {
    x = x_init;
    x_dot = x_dot_init;
    t = t_init;
    t_dot = t_dot_init;
}

State::State() {
    x = 0;
    x_dot = 0;
    t = 0;
    t_dot = 0;
}
