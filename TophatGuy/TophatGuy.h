//
// Created by Matthew Tapia on 12/8/22.
//

#ifndef PORTFOLIO_TOPHATGUY_H
#define PORTFOLIO_TOPHATGUY_H

#include "../SFML Tools/Component.h"
#include <SFML/Graphics.hpp>

class TophatGuy : public Component{
private:
    sf::RectangleShape top, brim;
    sf::CircleShape face;
public:
    TophatGuy();
    void setPosition(const sf::Vector2f& pos);
    void setPosition(float x, float y);
    void setFaceColor(const sf::Color& color);
    void setBrimColor(const sf::Color& color);
    void setTopColor(const sf::Color& color);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void eventHandler(sf::RenderWindow &window, sf::Event &event) override;
};

#endif //PORTFOLIO_TOPHATGUY_H
