//
// Created by Matthew Tapia on 12/8/22.
//

#include "GreenBallProject.h"

GreenBallProject::GreenBallProject() : Application({2560, 1600, 32}, "Green Ball"){
    int radius = 4*getWidth()/144;

    setBackgroundColor(sf::Color::Black);

    b.setVelocity({0,0});
    b.setRadius(radius);
    b.setFillColor(sf::Color::Green);
    b.setPosition({(float)(getWidth()/2),(float)(getHeight()/2)});

    addComponent(b);
}

