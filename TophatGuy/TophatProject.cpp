//
// Created by Matthew Tapia on 12/8/22.
//

#include "TophatProject.h"

TophatProject::TophatProject() :  Application({2560, 1600, 32}, "Tophat Guy"){
    setBackgroundColor(sf::Color::Black);
    t.setPosition({(float)(getWidth()/2), (float)(getHeight()/2)});
    t.setFaceColor(sf::Color::Yellow);
    t.setBrimColor(sf::Color::Blue);
    t.setTopColor(sf::Color::Green);

    addComponent(t);
}
