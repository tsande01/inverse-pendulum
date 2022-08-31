#include <SFML/Graphics.hpp>
#include "src/InversePendulum.h"
#include <cmath>
#include <iostream>

float FLOOR_HEIGHT = 25;
float CART_WIDTH = 100;
float CART_HEIGHT = 50;

int WINDOW_WIDTH = 800;
int WINDOW_HEIGHT = 600;

float LINE_WIDTH = 3.f;

int INTERVAL = 100000; // milliseconds

int main() {
    float length = 50.f;
    InversePendulum inversePendulum = InversePendulum(5.f, M_PI + .01f, 4.f, 4.f, length, 3.0f);


    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Inverted Pendulum Simulation");

    sf::RectangleShape cart(sf::Vector2f(CART_WIDTH, CART_HEIGHT));
    cart.setOutlineColor(sf::Color::Black);
    cart.setOutlineThickness(LINE_WIDTH);

    sf::CircleShape mass(2 * inversePendulum.pend_mass);
    mass.setFillColor(sf::Color::Black);

    sf::RectangleShape line(sf::Vector2f((float)inversePendulum.length, 0.f));
    line.setOutlineColor(sf::Color::Black);
    line.setOutlineThickness(LINE_WIDTH / 2);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            for (int i = 0; i <= 200; i++) {
                inversePendulum.iterate(0.0f, (float) INTERVAL / 100000);

                window.clear(sf::Color::White);
                window.draw(cart);
                window.draw(mass);
                window.draw(line);
                float cart_position = (float) (WINDOW_WIDTH / 2.5 + inversePendulum.getState().x);
                float line_anchor = cart_position + CART_WIDTH / 2.f - LINE_WIDTH;
                float cart_top = (float) WINDOW_HEIGHT - FLOOR_HEIGHT - CART_HEIGHT - LINE_WIDTH;
                float line_rotation = (float) inversePendulum.getState().t;
                sf::Vector2f mass_position = sf::Vector2f(
                        (float) (line_anchor + inversePendulum.length * sin(inversePendulum.getState().t) - 3 * LINE_WIDTH),
                        (float) (cart_top + inversePendulum.length * cos(inversePendulum.getState().t)) - 3 * LINE_WIDTH);


                cart.setPosition(cart_position, (float) WINDOW_HEIGHT - FLOOR_HEIGHT - CART_HEIGHT);
                line.setPosition(line_anchor, cart_top);
                line.setRotation(90.f - line_rotation * 180 / M_PI);
                mass.setPosition(mass_position);
                window.display();
                sf::sleep(sf::microseconds(INTERVAL));

            }
        }


        window.close();
    }

    return 0;
}