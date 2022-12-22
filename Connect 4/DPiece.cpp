//
// Created by Matthew Tapia on 11/30/22.
//

#include "DPiece.h"

DPiece::DPiece() : DPiece(0, 0, NULL_COLOR){

}

DPiece::DPiece(int row, int col, PieceColor color) {
    piece.setRow(row);
    piece.setColumn(col);
    piece.setColor(color);
    circle.setOutlineColor(sf::Color::Black);

    updateColor();

    setPosition({0,0});
}

void DPiece::updateColor() {
    PieceColor color = piece.getColor();
    if(color == RED){
        setFillColor(Constants::C4_RED_PIECE_COLOR);
    } else if (color == YELLOW){
        setFillColor(Constants::C4_YELLOW_PIECE_COLOR);
    } else if(color == NULL_COLOR){
        setFillColor(sf::Color(Constants::C4_BACKGROUND_COLOR));
    }
}

sf::Vector2f DPiece::getPosition() const {
    return circle.getPosition();
}

sf::Color DPiece::getFillColor() const {
    PieceColor color = piece.getColor();
    if(color == RED){
        return Constants::C4_RED_PIECE_COLOR;
    } else if (color == YELLOW){
        return Constants::C4_YELLOW_PIECE_COLOR;
    } else if(color == NULL_COLOR){
        return Constants::C4_BACKGROUND_COLOR;
    }
}

float DPiece::getRadius() const {
    return circle.getRadius();
}

sf::FloatRect DPiece::getGlobalBounds() const {
    return circle.getGlobalBounds();
}

int DPiece::getRow() const {
    return piece.getRow();
}

int DPiece::getColumn() const {
    return piece.getColumn();
}

PieceColor DPiece::getPieceColor() const {
    return piece.getColor();
}

void DPiece::setFillColor(const sf::Color& color) {
    circle.setFillColor(color);
}

void DPiece::setPosition(const sf::Vector2f& position) {
    circle.setPosition(position);
}

void DPiece::setPosition(float x, float y) {
    setPosition({x, y});
}

void DPiece::setRadius(float radius) {
    circle.setRadius(radius);
}

void DPiece::setRow(int row) {
    piece.setRow(row);
}

void DPiece::setColumn(int col) {
    piece.setColumn(col);
}

void DPiece::setColor(PieceColor color) {
    piece.setColor(color);
    updateColor();
}

void DPiece::setOutlineThickness(float thickness) {
    circle.setOutlineThickness(thickness);
}

void DPiece::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!Stateable::checkState(HIDDEN)){
        target.draw(circle);
    }
}

void DPiece::eventHandler(sf::RenderWindow &window, sf::Event &event) {

}
