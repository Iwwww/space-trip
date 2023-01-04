#include "Star.h"

Star::Star() {
    m_dot = sf::CircleShape(m_dotRadius);
    m_dot.setFillColor(sf::Color::White);

    setPos(m_posX, m_posY);
};

Star::Star(int dotRadius) {
    m_dotRadius = dotRadius;
    m_dot = sf::CircleShape(m_dotRadius);
    m_dot.setFillColor(sf::Color::White);
    // m_dot.getPosition

    setPos(m_posX, m_posY);
};

void Star::setPos(int posX, int posY) {
    m_posX = posX;
    m_posY = posY;
    m_dot.setPosition(m_posX, m_posY);
}

void Star::setStarColor(sf::Color color) {
    m_dot.setFillColor(color);
}

void Star::draw(sf::RenderWindow& window) {
    window.draw(m_dot);
}

void Star::setPolar() {
    int radian = this->getRadian();
    int radius = this->getRadius();
    int x = radius * std::cos(radian) + m_centerX;
    int y = radius * std::sin(radian) + m_centerY;
    this->setPos(x, y);
}

void Star::setRadian(int radian) {
    m_radian = radian;
}

void Star::setRadius(int radius) {
    m_dotRadius = radius;
}

void Star::setCenter(int x, int y) {
    m_centerX = x;
    m_centerY = y;
    // this->setPos(m_centerX, m_centerY);
}

void Star::setRenderSize(int x, int y) {
    m_renderX = x;
    m_renderY = y;
}

int Star::getPosX() {
    return m_posX;
}

int Star::getPosY() {
    return m_posY;
}

int Star::getRadian() {
    return m_radian;
}

int Star::getRadius() {
    return m_dotRadius;
}
