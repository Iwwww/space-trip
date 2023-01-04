#include "Star/Star.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Stars", sf::Style::Default, settings);

    int windows_size_x = window.getSize().x;
    int windows_size_y = window.getSize().y;


    // Star star = Star(6);
    // star.setCenter(500, 500);
    // star.setRadius(10);
    // star.setRadian(10);
    // star.setStarColor(sf::Color::Red);
    // star.setPos(0,0);

    const int STARS_COUNT = 15;
    std::vector<Star> stars(STARS_COUNT);
    for (int i = 0; i < STARS_COUNT; i++) {
        stars[i] = Star(6);
        int rad = rand() % 100;
        // int rad = 10;
        stars[i].setCenter(500, 500);
        stars[i].setRadius(10);
        stars[i].setRadian(rad);
        stars[i].setStarColor(sf::Color::Red);
        stars[i].setPos(0,0);
    }

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        sf::Time elapsed = clock.getElapsedTime();

        // star.
        window.clear(sf::Color::Black);
        // stars[0].draw(window);
        // star.draw(window);
        // star.setRadius(star.getRadius() + 1);
        // star.setPolar();
        for (int i = 0; i < STARS_COUNT; i++) {
            stars[i].draw(window);
            stars[i].setRadius(stars[i].getRadius() + 1);
            stars[i].setPolar();
        }

        window.display();
    }

    return 0;
}

