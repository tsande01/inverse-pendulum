#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../src/InversePendulum.h"

TEST_CASE("Inverse Pendulum Constructor Test") {

    InversePendulum inversePendulum = InversePendulum(1.0,
                                                      90.5,
                                                      1.0,
                                                      1.0,
                                                      2.0,
                                                      0.1);
    CHECK(inversePendulum.getState().x == 1.0);
    CHECK(inversePendulum.getState().x_dot == 0.0);
    CHECK(inversePendulum.getState().t == 90.5);
    CHECK(inversePendulum.getState().t_dot == 0.0);
    CHECK(inversePendulum.cart_mass == 1.0);
    CHECK(inversePendulum.pend_mass == 1.0);
    CHECK(inversePendulum.length == 2);
    CHECK(inversePendulum.damping == 0.1);
}

TEST_CASE("Can iterate") {
    InversePendulum inversePendulum = InversePendulum(1.0,
                                                      90.5,
                                                      1.0,
                                                      1.0,
                                                      2.0,
                                                      0.1);

    inversePendulum.iterate(0.0, .01);
    CHECK(inversePendulum.getState().x != 1.0);
}