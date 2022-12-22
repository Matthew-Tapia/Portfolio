//
// Created by Matthew Tapia on 11/30/22.
//

#ifndef CONNECT_4_BOARD_H
#define CONNECT_4_BOARD_H

#include <iostream>
#include "Piece.h"

class Board {
private:
    Piece grid[6][7];
    int turn = 0;

    bool checkLR() const;
    bool checkUD() const;
    bool checkLBTR() const;
    bool checkTLBR() const;

public:
    Board();

    void printBoard();

    int getTurn() const;
    Piece at(int row, int col) const;
    bool hasWon() const;

    void dropPiece(int column, PieceColor color);
    void reset();

};


#endif //CONNECT_4_BOARD_H
