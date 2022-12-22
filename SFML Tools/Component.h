//
// Created by Matthew Tapia on 12/6/22.
//

#ifndef PORTFOLIO_COMPONENT_H
#define PORTFOLIO_COMPONENT_H

#include <SFML/Graphics.hpp>
#include "EventHandleable.h"
#include "Stateable.h"

class Component : public sf::Drawable, public EventHandleable, public Stateable, public sf::Transformable{

};

#endif //CONNECT_4_COMPONENT_H
