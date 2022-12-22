//
// Created by Matthew Tapia on 12/5/22.
//

#include "C4Project.h"

C4Project::C4Project() : Application({2560, 1600, 32}, "Connect 4"){
    setBackgroundColor(Constants::C4_BACKGROUND_COLOR);
    gameBoard.setSize({(float)(1.5*35*getWidth()/96), (float)(1.25*5*getHeight()/9)});
    gameBoard.setFillColor(Constants::C4_BOARD_COLOR);
    gameBoard.setPosition({getWidth()/2 - gameBoard.getGlobalBounds().width/2,  getHeight()/2 - gameBoard.getGlobalBounds().height/2});

    gameBoard.setRestartButtonColor(Constants::C4_RESTART_BUTTON_COLOR);
    gameBoard.setRestartTextColor(Constants::C4_RESTART_BUTTON_TEXT_COLOR);

    addComponent(gameBoard);
}
