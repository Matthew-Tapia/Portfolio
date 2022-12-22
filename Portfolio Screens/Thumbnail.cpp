//
// Created by Matthew Tapia on 12/11/22.
//

#include "Thumbnail.h"

Thumbnail::Thumbnail() : Thumbnail(sf::Texture()){

}

Thumbnail::Thumbnail(const sf::Texture &texture) {
    thumbnail.setTexture(texture);
}

void Thumbnail::setPosition(const sf::Vector2f &position) {
    thumbnail.setPosition(position);
}

void Thumbnail::setPosition(float x, float y) {
    setPosition({x, y});
}

void Thumbnail::setScale(const sf::Vector2f &factors) {
    thumbnail.setScale(factors);
}

void Thumbnail::setScale(float x, float y) {
    setScale({x, y});
}

sf::FloatRect Thumbnail::getGlobalBounds() const {
    return thumbnail.getGlobalBounds();
}

void Thumbnail::eventHandler(sf::RenderWindow &window, sf::Event &event) {

}

void Thumbnail::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(thumbnail);
}
