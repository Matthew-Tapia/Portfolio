//
// Created by Matthew Tapia on 11/30/22.
//

#ifndef CONNECT_4_PIECE_H
#define CONNECT_4_PIECE_H

#include "PieceColorEnum.h"

class Piece {
private:
    int row, col;
    PieceColor color;

public:
    Piece();
    Piece(int row, int col, PieceColor color);

    int getRow() const;
    int getColumn() const;
    PieceColor getColor() const;

    void setRow(int row);
    void setColumn(int column);
    void setColor(PieceColor color);
};


#endif //CONNECT_4_PIECE_H
