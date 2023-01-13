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

    setPos(m_posX, m_posY);
};

void Star::setSize(int size) {
    m_dotRadius = size;
    m_dot = sf::CircleShape(m_dotRadius);
    m_dot.setFillColor(sf::Color::White);

    setPos(m_posX, m_posY);

}

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

void Star::frame() {
    m_frameCount++;
    if (m_frameCount >= m_speed) {
        m_frameCount = 0;
        m_isNewRender = 1;
    }
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
}

void Star::setRenderSize(int x, int y) {
    m_renderX = x;
    m_renderY = y;
}

void Star::setSpeed(int speed) {
    m_speed = speed / 10;
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

int Star::getSpeed() {
    return m_speed;
}

int Star::getFrameCount() {
    return m_frameCount;
}

bool Star::outOfRender() {
    return (m_dot.getPosition().x < 0 || m_dot.getPosition().y < 0 || m_dot.getPosition().x > m_renderX || m_dot.getPosition().y > m_renderY);
}

bool Star::isNewRender() {
    bool tmp = m_isNewRender;
    m_isNewRender = 0;
    return tmp;
}
