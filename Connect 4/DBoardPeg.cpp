//
// Created by Matthew Tapia on 11/30/22.
//

#include "DBoardPeg.h"

DBoardPeg::DBoardPeg() : DBoardPeg(DPiece()){

}

DBoardPeg::DBoardPeg(DPiece piece) {
    this->piece = piece;
    background.setSize({piece.getRadius()*2, piece.getRadius()*2});

    setPosition({0,0});
}

sf::Vector2f DBoardPeg::getSize() const {
    return background.getSize();
}

sf::Vector2f DBoardPeg::getPosition() const {
    return background.getPosition();
}

sf::Color DBoardPeg::getFillColor() const {
    return background.getFillColor();
}

sf::FloatRect DBoardPeg::getGlobalBounds() const {
    return background.getGlobalBounds();
}

int DBoardPeg::getPieceRow() const {
    return piece.getRow();
}

int DBoardPeg::getPieceColumn() const {
    return piece.getColumn();
}

PieceColor DBoardPeg::getPieceColor() const {
    return piece.getPieceColor();
}

void DBoardPeg::setFillColor(const sf::Color &color) {
    background.setFillColor(color);
}

void DBoardPeg::setPosition(const sf::Vector2f &position) {
    background.setPosition(position);
    Position::center(background, piece);
}

void DBoardPeg::setPosition(float x, float y) {
    setPosition({x,y});
}

void DBoardPeg::setSize(const sf::Vector2f &size) {
    background.setSize(size);
    piece.setRadius(size.x/3);
    Position::center(background, piece);
}

void DBoardPeg::setSize(float x, float y) {
    setSize({x, y});
}

void DBoardPeg::setPieceRow(int row) {
    piece.setRow(row);
}

void DBoardPeg::setPieceColumn(int col) {
    piece.setColumn(col);
}

void DBoardPeg::setPieceColor(PieceColor color) {
    piece.setColor(color);
}

void DBoardPeg::setPieceOutlineThickness(float thickness) {
    piece.setOutlineThickness(thickness);
}

void DBoardPeg::reset() {
    this->piece = DPiece();
    background.setSize({piece.getRadius()*2, piece.getRadius()*2});
}

void DBoardPeg::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!Stateable::checkState(HIDDEN)){
        target.draw(background);
        target.draw(piece);
    }
}

void DBoardPeg::eventHandler(sf::RenderWindow &window, sf::Event &event) {

}
