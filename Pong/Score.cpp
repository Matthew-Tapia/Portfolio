//
// Created by Matthew Tapia on 12/7/22.
//

#include "Score.h"

Score::Score() : leftScore(0), rightScore(0){
    text = sf::Text(std::to_string(leftScore) + " | " + std::to_string(rightScore), Fonts::getFont(GAMEPLAY));
    text.setFillColor(sf::Color::Black);
    text.setPosition({0, 0});
}

void Score::setString(const std::string &string) {
    text.setString(string);
}

void Score::setPosition(const sf::Vector2f &position) {
    text.setPosition(position);
}

void Score::setPosition(float x, float y) {
    setPosition({x,y});
}

void Score::addLeftPoint() {
    leftScore++;
}

void Score::addRightPoint() {
    rightScore++;
}

int &Score::getLeftScore() {
    return leftScore;
}

int &Score::getRightScore() {
    return rightScore;
}

void Score::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(text);
}
