//
// Created by Matthew Tapia on 12/8/22.
//

#include "CardProject.h"

CardProject::CardProject() : Application({2560, 1600, 32}, "Card"){
    setBackgroundColor(sf::Color::Black);
    dc.setPosition({(float)(getWidth()/2 - dc.getSize().x/2), (float)(getHeight()/2) - dc.getSize().y/2});

    addComponent(dc);
}
