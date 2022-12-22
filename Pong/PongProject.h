//
// Created by Matthew Tapia on 12/7/22.
//

#ifndef PORTFOLIO_PONGPROJECT_H
#define PORTFOLIO_PONGPROJECT_H

#include "../SFML Tools/Application.h"
#include "Pong.h"

class PongProject : public Application{
private:
    Pong game;

public:
    PongProject();
};


#endif //PORTFOLIO_PONGPROJECT_H
