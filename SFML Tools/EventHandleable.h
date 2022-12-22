//
// Created by Matthew Tapia on 12/6/22.
//

#ifndef PORTFOLIO_EVENTHANDLEABLE_H
#define PORTFOLIO_EVENTHANDLEABLE_H

#include "SFML/Graphics.hpp"

class EventHandleable{
public:
    virtual void eventHandler(sf::RenderWindow& window, sf::Event& event) = 0;
};

#endif //PORTFOLIO_EVENTHANDLEABLE_H

