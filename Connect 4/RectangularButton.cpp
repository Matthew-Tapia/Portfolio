//
// Created by Matthew Tapia on 12/2/22.
//

#include "RectangularButton.h"

RectangularButton::RectangularButton() : RectangularButton(""){

}

RectangularButton::RectangularButton(std::string title) {
    this->text.setFont(Fonts::getFont(ROBOTO));
    text.setString(title);
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(1);
}

sf::Vector2f RectangularButton::getPosition() const {
    return {getGlobalBounds().left, getGlobalBounds().top};
}

sf::FloatRect RectangularButton::getGlobalBounds() const {
    return box.getGlobalBounds();
}

void RectangularButton::setSize(const sf::Vector2f &size) {
    box.setSize(size);
    Position::centerText(box, text);
}

void RectangularButton::setSize(float x, float y) {
    setSize({x, y});
}

void RectangularButton::setTextSize(unsigned int size) {
    this->text.setCharacterSize(size);
    Position::centerText(box, text);
}

void RectangularButton::setString(const std::string &text) {
    this->text.setString(text);
    Position::centerText(box, this->text);
}

void RectangularButton::setPosition(const sf::Vector2f& position) {
    box.setPosition(position);
    Position::centerText(box, text);
}

void RectangularButton::setPosition(float x, float y) {
    setPosition({x, y});
}

void RectangularButton::setBackgroundColor(const sf::Color& color) {
    backgroundColor = color;
    box.setFillColor(color);
}

void RectangularButton::setTextColor(const sf::Color& color) {
    hoverColor = color;
    text.setFillColor(color);
}

void RectangularButton::onClick(sf::RenderWindow &window) {

}

void RectangularButton::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    if(MouseEvents::isHovered(box, window)){
        box.setFillColor(hoverColor);
        text.setFillColor(backgroundColor);
    } else {
        box.setFillColor(backgroundColor);
        text.setFillColor(hoverColor);
    }
}

void RectangularButton::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(box);
    target.draw(text);
}
