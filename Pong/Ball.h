//
// Created by Matthew Tapia on 12/7/22.
//

#ifndef PORTFOLIO_BALL_H
#define PORTFOLIO_BALL_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Ball : public sf::CircleShape{
public:
    void bounce(const sf::RenderWindow &window, const sf::FloatRect leftPaddle, const sf::FloatRect rightPaddle, int &leftScore, int &rightScore);
    void setVelocity(sf::Vector2f velocity);


private:
    sf::Vector2f velocity;
};


#endif //PORTFOLIO_BALL_H
