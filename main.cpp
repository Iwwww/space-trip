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

    const int STARS_COUNT = 105;
    std::vector<Star> stars(STARS_COUNT);
    for (int i = 0; i < STARS_COUNT; i++) {
        int rad = rand() % 100;
        stars[i] = Star(20 / rad + 1);
        stars[i].setCenter(windows_size_x / 2, windows_size_y / 2);
        stars[i].setRadius(10);
        stars[i].setRadian(rad);
        stars[i].setStarColor(sf::Color::Red);
        stars[i].setPos(0,0);
        stars[i].setSpeed(rad);
        stars[i].setRenderSize(windows_size_x, windows_size_y);
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

        window.clear(sf::Color::Black);
        for (int i = 0; i < STARS_COUNT; i++) {
            stars[i].draw(window);
            stars[i].frame();
            if (stars[i].isNewRender()) {
                if (stars[i].outOfRender()) {
                    int rad = rand() % 5000;
                    stars[i].setRadius(rad);
                    stars[i].setPolar();
                    // std::cout << "pos:" << stars[i].getPosX() << " " << stars[i].getPosY() << std::endl;
                } else {
                    stars[i].setRadius(stars[i].getRadius() + 1);
                    stars[i].setPolar();
                }
            }
        }

        window.display();
    }

    return 0;
}

