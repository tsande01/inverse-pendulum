//
// Created by trevor on 5/14/22.
//

#ifndef INVERSE_PENDULUM_INVERSEPENDULUM_H
#define INVERSE_PENDULUM_INVERSEPENDULUM_H

struct State {
    float x{};
    float x_dot{};
    float t{};
    float t_dot{};
    State(float x, float x_dot, float t, float t_dot);
    State();
};

class InversePendulum {
private:
    State state;
public:
    InversePendulum(float sled_position,
                    float length,
                    float mass,
                    float theta);
    float mass{};
    float length{};
    State getState();
};


#endif //LEARNOPENGL_CLION_INVERSEPENDULUM_H
