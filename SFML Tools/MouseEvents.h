//
// Created by Matthew Tapia on 12/7/22.
//

#ifndef PORTFOLIO_MOUSEEVENTS_H
#define PORTFOLIO_MOUSEEVENTS_H


#include <SFML/Graphics.hpp>

class MouseEvents {
public:
    template<class T>
    static bool isHovered(const T& Obj, const sf::RenderWindow& window);

    template<class T>
    static bool isClicked(const T& Obj, const sf::RenderWindow& window);

    template<class T>
    static bool isNotClicked(const T& Obj, const sf::RenderWindow& window);
};

#include "MouseEvents.cpp"


#endif //PORTFOLIO_MOUSEEVENTS_H
