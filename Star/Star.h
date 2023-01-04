#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

class Star {
public:
    Star();
    Star(int watchRadius);
    void setPos(int posX, int posY);
    void setStarColor(sf::Color color);
    void draw(sf::RenderWindow& window);
    void setPolar();
    void setRadian(int radian);
    void setRadius(int radius);
    void setCenter(int x, int y);
    void setRenderSize(int x, int y);
    int getPosX();
    int getPosY();
    int getRadian();
    int getRadius();

private:
    int m_posX = 0;
    int m_posY = 0;
    int m_radian = 0;
    int m_radius = 0;
    int m_centerX = 0;
    int m_centerY = 0;
    int m_renderX = 0;
    int m_renderY = 0;

    sf::CircleShape m_dot;
    sf::Color m_dotColor = sf::Color::White;
    int m_dotRadius = 1;
};
