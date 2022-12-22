//
// Created by Matthew Tapia on 11/30/22.
//

#include "DBoardColumn.h"

DBoardColumn::DBoardColumn() : DBoardColumn(0){

}

DBoardColumn::DBoardColumn(int size) : size(size){
    for(int i = 0; i < size; i++){
        DBoardPeg bp;
        bp.setPieceOutlineThickness(1);
        column.push_back(bp);
    }

    setPosition({0,0});
}

sf::FloatRect DBoardColumn::getGlobalBounds() const {
    sf::FloatRect f = column[0].getGlobalBounds();
    f.height *= this->size;
    return f;
}

sf::Vector2f DBoardColumn::getSize() const {
    return {getGlobalBounds().width, getGlobalBounds().height};
}

sf::Vector2f DBoardColumn::getPosition() const {
    return {getGlobalBounds().left, getGlobalBounds().top};
}

sf::Color DBoardColumn::getFillColor() const {
    return column[0].getFillColor();
}

bool DBoardColumn::isFull() const {
    for(int i = 0; i < size; i++){
        if(column[i].getPieceColor() == NULL_COLOR){
            return false;
        }
    }
    return true;
}

void DBoardColumn::setFillColor(const sf::Color &color) {
    for(auto & i : column){
        i.setFillColor(color);
    }
}

void DBoardColumn::setPosition(const sf::Vector2f &position) {
    column[0].setPosition(position);
    for(int i = 1; i < size; i++){
        Position::bottom(column[i-1], column[i]);
    }
}

void DBoardColumn::setPosition(float x, float y) {
    setPosition({x, y});
}

void DBoardColumn::setSize(const sf::Vector2f &size) {
    sf::Vector2f sizeOfEachPeg = {size.x, size.y/this->size};

    for(auto & i : column){
        i.setSize(sizeOfEachPeg);
    }
    for(int i = 1; i < this->size; i++){
        Position::bottom(column[i-1], column[i]);
    }
}

void DBoardColumn::setSize(float x, float y) {
    setSize({x, y});
}

void DBoardColumn::animateDroppingPiece(sf::RenderWindow &window, PieceColor color) {
    if (!isFull()){
        int row = 0;

        while(column[row+1].getPieceColor() == NULL_COLOR && row != size-1){
            column[row].setPieceColor(color);
            window.draw(*this);
            window.display();
            std::this_thread::sleep_for(std::chrono::milliseconds(((size-1)*10)-(row*(row-1))));


            column[row].setPieceColor(NULL_COLOR);
            window.draw(*this);
            window.display();
            std::this_thread::sleep_for(std::chrono::milliseconds(((size-1)*10)-(row*(row-1))));

            row++;
        }
    }
}

void DBoardColumn::dropPiece(PieceColor color) {
    if (!isFull()){
        int row = 0;

        while(column[row+1].getPieceColor() == NULL_COLOR && row != 5){
            row++;
        }

        column[row].setPieceColor(color);
    }
}

void DBoardColumn::onClick(sf::RenderWindow &window, PieceColor color) {
    for(int i = 0; i < this->size; i++){
        if(MouseEvents::isClicked(column[i], window)){
            dropPiece(color);
        }
    }
}

void DBoardColumn::reset() {
    for(auto & i : column){
        i.reset();
    }
}

void DBoardColumn::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!Stateable::checkState(HIDDEN)){
        for(const auto & i : column){
            target.draw(i);
        }
    }
}

void DBoardColumn::eventHandler(sf::RenderWindow &window, sf::Event &event) {

}
