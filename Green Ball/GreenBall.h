//
// Created by Matthew Tapia on 12/8/22.
//

#ifndef PORTFOLIO_GREENBALL_H
#define PORTFOLIO_GREENBALL_H

#include <SFML/Graphics.hpp>
#include "../Bouncing Ball/BouncingBall.h"

class GreenBall : public BouncingBall{
public:
    void eventHandler(sf::RenderWindow &window, sf::Event &event) override;
};


#endif //PORTFOLIO_GREENBALL_H
