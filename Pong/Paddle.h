//
// Created by Matthew Tapia on 12/7/22.
//

#ifndef PORTFOLIO_PADDLE_H
#define PORTFOLIO_PADDLE_H


#include <SFML/Graphics.hpp>
#include <iostream>

class Paddle : public sf::RectangleShape{
public:
    Paddle();
    Paddle(const sf::Vector2f &size, const sf::Vector2f &position);
    Paddle(const sf::Vector2f &size, const sf::Vector2f &position, sf::Color color);

    void shiftUp(const sf::RenderWindow &window);
    void shiftDown(const sf::RenderWindow &window);

    void setUp(sf::Keyboard::Key up);
    void setDown(sf::Keyboard::Key down);

    void setVelocity(float speed);

private:
    float velocity;
    sf::Keyboard::Key up, down;
};


#endif //PORTFOLIO_PADDLE_H
