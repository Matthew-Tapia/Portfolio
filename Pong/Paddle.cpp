//
// Created by Matthew Tapia on 12/7/22.
//

#include "Paddle.h"

Paddle::Paddle() : Paddle({0,0}, {0,0}, sf::Color::Black){

}

Paddle::Paddle(const sf::Vector2f &size, const sf::Vector2f &position) : sf::RectangleShape(){
    setSize(size);
    sf::RectangleShape::setPosition(position);
}

Paddle::Paddle(const sf::Vector2f &size, const sf::Vector2f &position, sf::Color color) : Paddle(size, position){
    setFillColor(color);
}

void Paddle::shiftUp(const sf::RenderWindow &window){
    if(sf::Keyboard::isKeyPressed(up) && sf::RectangleShape::getPosition().y > 0){
        sf::RectangleShape::move({0, -velocity});
    }

}
void Paddle::shiftDown(const sf::RenderWindow &window){
    if(sf::Keyboard::isKeyPressed(down) && sf::RectangleShape::getPosition().y < window.getSize().y - getSize().y){
        sf::RectangleShape::move({0, velocity});
    }
}

void Paddle::setUp(sf::Keyboard::Key up) {
    Paddle::up = up;
}

void Paddle::setDown(sf::Keyboard::Key down) {
    Paddle::down = down;
}

void Paddle::setVelocity(float speed) {
    velocity = speed;
}
