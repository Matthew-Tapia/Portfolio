//
// Created by Matthew Tapia on 12/8/22.
//

#include "TophatGuy.h"

TophatGuy::TophatGuy(){
    top.setSize({50,70});
    brim.setSize({70,25});
    face.setRadius(30);

    top.setPosition({0, 0});
    brim.setPosition({top.getPosition().x - 10, top.getPosition().y + 65});
    face.setPosition({top.getPosition().x - 5, top.getPosition().y + 80});
}

void TophatGuy::setPosition(const sf::Vector2f& pos) {
    sf::Transformable::setPosition(pos);
}

void TophatGuy::setPosition(float x, float y) {
    setPosition({x, y});
}

void TophatGuy::setFaceColor(const sf::Color &color) {
    face.setFillColor(color);
}

void TophatGuy::setBrimColor(const sf::Color &color) {
    brim.setFillColor(color);
}

void TophatGuy::setTopColor(const sf::Color &color) {
    top.setFillColor(color);
}

void TophatGuy::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    states.transform = getTransform();
    window.draw(face, states);
    window.draw(top, states);
    window.draw(brim, states);
}

void TophatGuy::eventHandler(sf::RenderWindow &window, sf::Event &event) {

}
