//
// Created by Matthew Tapia on 11/30/22.
//

#include "Piece.h"

Piece::Piece() : Piece(0, 0, PieceColor::NULL_COLOR){

}

Piece::Piece(int row, int col, PieceColor color) {
    this->row = row;
    this->col = col;
    this->color = color;
}

int Piece::getRow() const {
    return row;
}

int Piece::getColumn() const {
    return col;
}

PieceColor Piece::getColor() const {
    return color;
}

void Piece::setRow(int row) {
    this->row = row;
}

void Piece::setColumn(int column) {
    this->col = column;
}

void Piece::setColor(PieceColor color) {
    this->color = color;
}
