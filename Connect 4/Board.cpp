//
// Created by Matthew Tapia on 11/30/22.
//

#include "Board.h"

Board::Board() {
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            grid[i][j] = Piece(i, j, NULL_COLOR);
        }
    }
}

void Board::printBoard() {
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            std::cout << grid[i][j].getColor();
        }
        std::cout << std::endl;
    }
    std::cout << "\n\n";
}

int Board::getTurn() const {
    return turn;
}

Piece Board::at(int row, int col) const {
    return grid[row][col];
}

void Board::dropPiece(int column, PieceColor color) {
    if (grid[0][column].getColor() == NULL_COLOR){
        int row = 0;

        while(grid[row+1][column].getColor() == NULL_COLOR && row != 5){
            row++;
        }

        grid[row][column].setColor(color);
    }

    turn++;
}

void Board::reset() {
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            grid[i][j].setColor(NULL_COLOR);
        }
    }

    turn = 0;
}

bool Board::checkLR() const{
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 4; j++){
            PieceColor p1 = grid[i][j].getColor();
            PieceColor p2 = grid[i][j+1].getColor();
            PieceColor p3 = grid[i][j+2].getColor();
            PieceColor p4 = grid[i][j+3].getColor();

            if(p1 != NULL_COLOR && p1 == p2 && p2 == p3 && p3 == p4){
                return true;
            }
        }
    }

    return false;
}

bool Board::checkUD() const{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 7; j++){
            PieceColor p1 = grid[i][j].getColor();
            PieceColor p2 = grid[i+1][j].getColor();
            PieceColor p3 = grid[i+2][j].getColor();
            PieceColor p4 = grid[i+3][j].getColor();

            if(p1 != NULL_COLOR && p1 == p2 && p2 == p3 && p3 == p4){
                return true;
            }
        }
    }

    return false;
}

bool Board::checkLBTR() const{
    for(int i = 5; i >= 3; i--){
        for(int j = 0; j < 4; j++){
            PieceColor p1 = grid[i][j].getColor();
            PieceColor p2 = grid[i-1][j+1].getColor();
            PieceColor p3 = grid[i-2][j+2].getColor();
            PieceColor p4 = grid[i-3][j+3].getColor();


            if(p1 != NULL_COLOR && p1 == p2 && p2 == p3 && p3 == p4){
                return true;
            }
        }
    }
    return false;
}

bool Board::checkTLBR() const{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            PieceColor p1 = grid[i][j].getColor();
            PieceColor p2 = grid[i+1][j+1].getColor();
            PieceColor p3 = grid[i+2][j+2].getColor();
            PieceColor p4 = grid[i+3][j+3].getColor();

            if(p1 != NULL_COLOR && p1 == p2 && p2 == p3 && p3 == p4){
                return true;
            }
        }
    }

    return false;
}

bool Board::hasWon() const{
    return checkLBTR() || checkTLBR() || checkLR() || checkUD();
}

