//
// Created by trevor on 5/14/22.
//

#ifndef INVERSE_PENDULUM_INVERSEPENDULUM_H
#define INVERSE_PENDULUM_INVERSEPENDULUM_H

struct State {

public:
    double x;
    double x_dot;
    double t;
    double t_dot;
    State(double x, double x_dot, double t, double t_dot) :
            x(x),
            x_dot(x_dot),
            t(t),
            t_dot(t_dot) {}

    State();
};

class InversePendulum {
private:
    State state;
public:
    double sled_position;
    double length;
    double cart_mass;
    double pend_mass;
    double theta;
    double damping;

    InversePendulum(double sled_position, double theta,
                    double cart_mass, double pend_mass,
                    double length, double damping) :
            state(State(sled_position, 0, theta, 0)),
            cart_mass(cart_mass),
            pend_mass(pend_mass),
            length(length),
            damping(damping) {}

    State getState();
    void setState(State new_state);
    void iterate(double u, double time);
};


#endif //LEARNOPENGL_CLION_INVERSEPENDULUM_H
