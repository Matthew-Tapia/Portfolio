//
// Created by Matthew Tapia on 12/8/22.
//

#include "BouncingBallProject.h"

BouncingBallProject::BouncingBallProject() : Application({2560, 1600, 32}, "Bouncing Ball"){
    setBackgroundColor(sf::Color::Black);

    float speed = (float)(getWidth()/200.0);
    int radius = 4*getWidth()/144;

    b.setVelocity({speed, speed});
    b.setRadius(radius);
    b.setFillColor(sf::Color::Blue);
    b.setPosition({(float)(getWidth()/2),(float)(getHeight()/2)});

    addComponent(b);
}
