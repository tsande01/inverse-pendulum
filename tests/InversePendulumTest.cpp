#include <catch2/catch.hpp>
#include "../src/InversePendulum.h"

TEST_CASE("Inverse Pendulum Constructor Test") {

    InversePendulum inversePendulum = InversePendulum(1.0,
                                                      2.0,
                                                      1.0,
                                                      90.5);
    CHECK(inversePendulum.getState().x == 1.0);
    CHECK(inversePendulum.getState().x_dot == 0.0);
    CHECK(inversePendulum.getState().t == 90.5);
    CHECK(inversePendulum.getState().t_dot == 0.0);
    CHECK(inversePendulum.mass == 1.0);
    CHECK(inversePendulum.length == 2);
}

