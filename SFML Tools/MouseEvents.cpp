//
// Created by Matthew Tapia on 12/7/22.
//

#ifndef PORTFOLIO_MOUSEEVENTS_CPP
#define PORTFOLIO_MOUSEEVENTS_CPP

#include "MouseEvents.h"

template<class T>
bool MouseEvents::isHovered(const T &Obj, const sf::RenderWindow &window) {
    return Obj.getGlobalBounds().contains((sf::Vector2f)(sf::Mouse::getPosition(window)));
}

template<class T>
bool MouseEvents::isClicked(const T &Obj, const sf::RenderWindow &window) {
    return isHovered(Obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

template<class T>
bool MouseEvents::isNotClicked(const T &Obj, const sf::RenderWindow &window) {
    return !isHovered(Obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

#endif
