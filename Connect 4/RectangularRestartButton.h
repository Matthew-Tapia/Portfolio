//
// Created by Matthew Tapia on 12/2/22.
//

#ifndef CONNECT_4_RECTANGULARRESTARTBUTTON_H
#define CONNECT_4_RECTANGULARRESTARTBUTTON_H

#include <iostream>
#include "RectangularButton.h"


class RectangularRestartButton : public RectangularButton{
public:
    RectangularRestartButton();

    void setSize(const sf::Vector2f& size) override;
    void setSize(float x, float y) override;

    void move(const sf::Vector2f& offset);
    void move(float x, float y);

    void onClick(sf::RenderWindow &window) override;

    void eventHandler(sf::RenderWindow &window, sf::Event &event) override;
};


#endif //CONNECT_4_RECTANGULARRESTARTBUTTON_H
