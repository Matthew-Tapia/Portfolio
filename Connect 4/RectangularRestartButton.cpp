//
// Created by Matthew Tapia on 12/2/22.
//

#include "RectangularRestartButton.h"

RectangularRestartButton::RectangularRestartButton() : RectangularButton("RESTART"){

}

void RectangularRestartButton::setSize(const sf::Vector2f &size) {
    RectangularButton::setSize(size);
    RectangularButton::setTextSize((int)(size.x/6));
}

void RectangularRestartButton::setSize(float x, float y) {
    RectangularButton::setSize(x, y);
}

void RectangularRestartButton::move(const sf::Vector2f &offset) {
    setPosition(getPosition() + offset);
}

void RectangularRestartButton::move(float x, float y) {
    move({x,y});
}

void RectangularRestartButton::onClick(sf::RenderWindow &window) {

}

void RectangularRestartButton::eventHandler(sf::RenderWindow &window, sf::Event &event) {
    RectangularButton::eventHandler(window, event);
}
