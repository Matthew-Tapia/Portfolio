//
// Created by Matthew Tapia on 12/7/22.
//

#include "PongProject.h"

PongProject::PongProject() : Application({2560, 1600, 32}, "Pong"){
    setBackgroundColor(sf::Color::White);
    float speed = (float)(getWidth()/100.0);
    int radius = 4*getWidth()/144;
    const sf::Vector2f start_position = {(float)(getWidth()/2), (float)(getHeight()/2)};

    game.setScorePosition({(float)(getWidth()/2)-40,5});
    game.setBallRadius(radius);
    game.setBallVelocity({(float) 1.25*speed, (float) 1.25*speed});
    game.setBallPosition(start_position);
    game.setBallFillColor(sf::Color::Magenta);

    game.setLeftPaddleSize({(float)(5*getWidth()/144),(float)(5*getHeight()/14)});
    game.setLeftPaddlePosition({10, 10});
    game.setLeftPaddleSpeed(speed);

    game.setRightPaddleSize({(float)(5*getWidth()/144), (float)(5*getHeight()/14)});
    game.setRightPaddlePosition({getWidth()-game.getRightPaddleSize().x-10, 10});
    game.setRightPaddleSpeed(speed);

    addComponent(game);
}
