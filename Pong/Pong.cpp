//
// Created by Matthew Tapia on 12/7/22.
//

#include "Pong.h"

Pong::Pong() {
    leftPaddle.setUp(sf::Keyboard::W);
    leftPaddle.setDown(sf::Keyboard::S);
    rightPaddle.setUp(sf::Keyboard::Up);
    rightPaddle.setDown(sf::Keyboard::Down);
}

void Pong::setLeftPaddlePosition(const sf::Vector2f &position) {
    leftPaddle.setPosition(position);
}


void Pong::setLeftPaddlePosition(float x, float y) {
    setLeftPaddlePosition({x,y});
}

void Pong::setLeftPaddleSize(const sf::Vector2f &position) {
    leftPaddle.setSize(position);
}

void Pong::setLeftPaddleSize(float x, float y) {
    setLeftPaddleSize({x,y});
}

void Pong::setLeftPaddleSpeed(float speed) {
    leftPaddle.setVelocity(speed);
}

sf::Vector2f Pong::getLeftPaddleSize() const {
    return leftPaddle.getSize();
}

void Pong::setRightPaddlePosition(const sf::Vector2f &position) {
    rightPaddle.setPosition(position);
}

void Pong::setRightPaddlePosition(float x, float y) {
    setRightPaddlePosition({x,y});
}

void Pong::setRightPaddleSize(const sf::Vector2f &position) {
    rightPaddle.setSize(position);
}

void Pong::setRightPaddleSize(float x, float y) {
    setRightPaddleSize({x,y});
}

void Pong::setRightPaddleSpeed(float speed) {
    rightPaddle.setVelocity(speed);
}

sf::Vector2f Pong::getRightPaddleSize() const {
    return rightPaddle.getSize();
}

void Pong::setScorePosition(const sf::Vector2f &position) {
    gameScore.setPosition(position);
}

void Pong::setScorePosition(float x, float y) {
    setScorePosition({x, y});
}

void Pong::setBallPosition(const sf::Vector2f &position) {
    ball.setPosition(position);
}

void Pong::setBallPosition(float x, float y) {
    setBallPosition({x,y});
}

void Pong::setBallRadius(int radius) {
    ball.setRadius(radius);
}

void Pong::setBallVelocity(const sf::Vector2f &velocity) {
    ball.setVelocity(velocity);
}

void Pong::setBallFillColor(const sf::Color &color) {
    ball.setFillColor(color);
}

void Pong::eventHandler(sf::RenderWindow &window, sf::Event &event) {
    leftPaddle.shiftDown(window);
    leftPaddle.shiftUp(window);

    rightPaddle.shiftDown(window);
    rightPaddle.shiftUp(window);

    ball.bounce(window,leftPaddle.getGlobalBounds(), rightPaddle.getGlobalBounds(), gameScore.getLeftScore(), gameScore.getRightScore());
    gameScore.setString(std::to_string(gameScore.getLeftScore()) + " | " + std::to_string(gameScore.getRightScore()));
}

void Pong::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(leftPaddle);
    target.draw(rightPaddle);
    target.draw(gameScore);
    target.draw(ball);

}
