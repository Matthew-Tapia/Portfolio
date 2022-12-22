//
// Created by Matthew Tapia on 12/2/22.
//

#include "DBoardRow.h"

DBoardRow::DBoardRow() : size(0){

}

DBoardRow::DBoardRow(int size) : size(size){
    for(int i = 0; i < size; i++){
        DBoardPeg bp;
        row.push_back(bp);
    }

    setPosition({0,0});
}

sf::Vector2f DBoardRow::getSize() const {
    return {getGlobalBounds().width, getGlobalBounds().height};
}

sf::Vector2f DBoardRow::getPosition() const {
    return {getGlobalBounds().left, getGlobalBounds().top};}

sf::Color DBoardRow::getFillColor() const {
    return row[0].getFillColor();
}

sf::FloatRect DBoardRow::getGlobalBounds() const {
    sf::FloatRect f = row[0].getGlobalBounds();
    f.width *= this->size;
    return f;
}


bool DBoardRow::isFull() const {
    for(int i = 0; i < size; i++){
        if(row[i].getPieceColor() == NULL_COLOR){
            return false;
        }
    }
    return true;
}

void DBoardRow::setFillColor(const sf::Color &color) {
    for(auto & i : row){
        i.setFillColor(color);
    }
}

void DBoardRow::setPosition(const sf::Vector2f &position) {
    row[0].setPosition(position);
    for(int i = 1; i < this->size; i++){
        Position::right(row[i-1], row[i]);
    }
}

void DBoardRow::setPosition(float x, float y) {
    setPosition({x, y});
}

void DBoardRow::setSize(const sf::Vector2f &size) {
    sf::Vector2f sizeOfEachPeg = {size.x/this->size, size.y};

    for(auto & i : row){
        i.setSize(sizeOfEachPeg);
    }
    for(int i = 1; i < this->size; i++){
        Position::bottom(row[i-1], row[i]);
    }
}

void DBoardRow::setSize(float x, float y) {
    setSize({x,y});
}

void DBoardRow::setPieceColor(int col, PieceColor color) {
    row[col].setPieceColor(color);
}

void DBoardRow::setPieceOutlineThickness(int col, float thickness) {
    row[col].setPieceOutlineThickness(thickness);
}

void DBoardRow::reset() {
    for(auto & i : row){
        i.reset();
    }
}

void DBoardRow::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!Stateable::checkState(HIDDEN)){
        for(const auto & i : row){
            target.draw(i);
        }
    }
}

void DBoardRow::eventHandler(sf::RenderWindow &window, sf::Event &event) {

}
