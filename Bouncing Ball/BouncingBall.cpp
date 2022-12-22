//
// Created by Matthew Tapia on 12/8/22.
//

#include "BouncingBall.h"

void BouncingBall::bounce(const sf::RenderWindow &window) {
    if(ball.getPosition().y > window.getSize().y - (ball.getRadius()*2)  || ball.getPosition().y < 0){
        velocity.y *= -1;
    }

    if(ball.getPosition().x > window.getSize().x - (ball.getRadius()*2) || ball.getPosition().x < 0){
        velocity.x *= -1;
    }

    ball.move(velocity.x, velocity.y);
}

void BouncingBall::setVelocity(sf::Vector2f velocity) {
    this->velocity = velocity;
}

void BouncingBall::setFillColor(const sf::Color &color) {
    ball.setFillColor(color);
}

void BouncingBall::setRadius(int radius) {
    ball.setRadius(radius);
}

void BouncingBall::setPosition(const sf::Vector2f &position) {
    ball.setPosition(position);
}

void BouncingBall::setPosition(float x, float y) {
    setPosition({x, y});
}

void BouncingBall::eventHandler(sf::RenderWindow &window, sf::Event &event) {
    bounce(window);
}

void BouncingBall::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(ball);
}
