//
// Created by Matthew Tapia on 12/8/22.
//

#ifndef PORTFOLIO_BOUNCINGBALL_H
#define PORTFOLIO_BOUNCINGBALL_H

#include <SFML/Graphics.hpp>
#include "../SFML Tools/Component.h"

class BouncingBall : public Component{
public:
    void bounce(const sf::RenderWindow &window);
    void setVelocity(sf::Vector2f velocity);
    void setFillColor(const sf::Color& color);
    void setRadius(int radius);
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow &window, sf::Event &event) override;

private:
    sf::CircleShape ball;
    sf::Vector2f velocity;
};


#endif //PORTFOLIO_BOUNCINGBALL_H
