//
// Created by Matthew Tapia on 12/5/22.
//

#include "../SFML Tools/Application.h"
#include "DBoard.h"

#ifndef CONNECT_4_C4PROJECT_H
#define CONNECT_4_C4PROJECT_H


class C4Project : public Application{
private:
    DBoard gameBoard = DBoard(6, 7);

public:
    C4Project();
};


#endif //CONNECT_4_C4PROJECT_H
