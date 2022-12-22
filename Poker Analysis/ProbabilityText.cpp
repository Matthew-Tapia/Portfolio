//
// Created by Matthew Tapia on 12/9/22.
//

#include "ProbabilityText.h"

ProbabilityText::ProbabilityText() {
    text.setFont(Fonts::getFont(OPEN_SANS));
}

void ProbabilityText::setString(const std::string &text) {
    this->text.setString(text);
}

void ProbabilityText::setCharacterSize(int size) {
    text.setCharacterSize(size);
}

void ProbabilityText::setPosition(const sf::Vector2f &position) {
    text.setPosition(position);
}

void ProbabilityText::setPosition(float x, float y) {
    setPosition({x, y});
}

void ProbabilityText::eventHandler(sf::RenderWindow &window, sf::Event &event) {

}

void ProbabilityText::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(text);
}
