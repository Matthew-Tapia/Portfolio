//
// Created by Matthew Tapia on 12/7/22.
//

#include "Ball.h"

void Ball::bounce(const sf::RenderWindow &window, const sf::FloatRect leftPaddle, const sf::FloatRect rightPaddle, int &leftScore, int &rightScore){
    //Bounce off left paddle
    if(sf::CircleShape::getPosition().x < leftPaddle.left + leftPaddle.width && sf::CircleShape::getPosition().y > leftPaddle.top - (getRadius() / 2)  &&
            sf::CircleShape::getPosition().y < leftPaddle.top + leftPaddle.height + (getRadius() / 2)){
        velocity.x *= -1;
    }

    //Bounce off right paddle
    if(sf::CircleShape::getPosition().x > rightPaddle.left - (getRadius()*2)  && sf::CircleShape::getPosition().y > rightPaddle.top - (getRadius() / 2) &&
            sf::CircleShape::getPosition().y < rightPaddle.top + leftPaddle.height + (getRadius() / 2)){
        velocity.x *= -1;
    }

    //Bounce off top and bottom
    if(sf::CircleShape::getPosition().y > window.getSize().y - (getRadius()*2)  || sf::CircleShape::getPosition().y < 0){
        velocity.y *= -1;
    }

    //Right scored
    if(sf::CircleShape::getPosition().x < leftPaddle.left - getRadius()){
        sf::CircleShape::setPosition(window.getSize().x/2, window.getSize().y/2);
        rightScore++;

    }

    //Left scored
    if(sf::CircleShape::getPosition().x > rightPaddle.left + rightPaddle.width + getRadius()){
        sf::CircleShape::setPosition(window.getSize().x/2, window.getSize().y/2);
        leftScore++;
    }

    sf::CircleShape::move(velocity.x, velocity.y);
}

void Ball::setVelocity(sf::Vector2f velocity){
    this->velocity = velocity;
}

