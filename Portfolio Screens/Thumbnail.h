//
// Created by Matthew Tapia on 12/11/22.
//

#ifndef PORTFOLIO_THUMBNAIL_H
#define PORTFOLIO_THUMBNAIL_H

#include <SFML/Graphics.hpp>
#include "../SFML Tools/Component.h"

class Thumbnail : public Component{
private:
    sf::Sprite thumbnail;

public:
    Thumbnail();
    Thumbnail(const sf::Texture& texture);

    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    void setScale(const sf::Vector2f& factors);
    void setScale(float x, float y);

    sf::FloatRect getGlobalBounds() const;

    void eventHandler(sf::RenderWindow &window, sf::Event &event) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //PORTFOLIO_THUMBNAIL_H
