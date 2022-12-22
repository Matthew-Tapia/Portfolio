//
// Created by Matthew Tapia on 11/30/22.
//

#include "DBoard.h"

DBoard::DBoard() : DBoard(0,0){


}

DBoard::DBoard(int rows, int cols) : rows(rows), cols(cols){
    for(int i = 0; i < this->cols; i++){
        DBoardColumn bc(rows);
        visibleBoard.push_back(bc);
    }
    topRow = DBoardRow(cols);

    setPosition({0,0});
}

sf::Vector2f DBoard::getSize() const {
    return {getGlobalBounds().width, getGlobalBounds().height};
}

sf::Vector2f DBoard::getPosition() const {
    return {getGlobalBounds().left, getGlobalBounds().top};
}

sf::Color DBoard::getFillColor() const{
    return visibleBoard[0].getFillColor();
}

sf::FloatRect DBoard::getGlobalBounds() const {
    sf::FloatRect f = visibleBoard[0].getGlobalBounds();
    f.width *= this->cols;
    return f;
}

PieceColor DBoard::getTurnColor() const {
    if(logicGrid.getTurn() % 2 == 0){
        return RED;
    } else{
        return YELLOW;
    }
}

void DBoard::setFillColor(const sf::Color &color) {
    topRow.setFillColor(Constants::C4_TRANSPARENT_COLOR);
    for(auto & i : visibleBoard){
        i.setFillColor(color);
    }

}

void DBoard::setPosition(const sf::Vector2f &position) {
    visibleBoard[0].setPosition(position);
    Position::top(visibleBoard[0], topRow);

    for(int i = 1; i < this->cols; i++){
        Position::right(visibleBoard[i-1], visibleBoard[i]);
    }

    Position::bottom(visibleBoard[0], restartButton, getGlobalBounds().height/100);
    restartButton.move({getGlobalBounds().width/2 - restartButton.getGlobalBounds().width/2, 0});

}

void DBoard::setPosition(float x, float y) {
    setPosition({x, y});
}

void DBoard::setSize(const sf::Vector2f &size) {
    sf::Vector2f sizeOfEachColumn = {size.x/this->cols, size.y};

    for(auto & i : visibleBoard){
        i.setSize(sizeOfEachColumn);
    }
    topRow.setSize(size.x, size.y/this->rows);

    for(int i = 1; i < this->cols; i++){
        Position::right(visibleBoard[i-1], visibleBoard[i]);
    }

    restartButton.setSize({300, 100});
}

void DBoard::setSize(float x, float y) {
    setPosition({x, y});
}

void DBoard::setRestartTextColor(const sf::Color &color) {
    restartButton.setTextColor(color);
}

void DBoard::setRestartButtonColor(const sf::Color &color) {
    restartButton.setBackgroundColor(color);
}

void DBoard::animateDroppingPiece(sf::RenderWindow &window, int col, PieceColor color) {
    visibleBoard[col].animateDroppingPiece(window, color);
}

void DBoard::dropPiece(int col, PieceColor color) {
    visibleBoard[col].dropPiece(color);
}

void DBoard::onClick(sf::RenderWindow &window) {
    if(logicGrid.hasWon()){
        return;
    }
    for(int i = 0; i < this->cols; i++){
        PieceColor turnColor = getTurnColor();

        if(MouseEvents::isClicked(visibleBoard[i], window) && !visibleBoard[i].isFull()){
            sf::Sound slidingSound(Sounds::getSound(PIECE_SLIDING));
            slidingSound.play();

            animateDroppingPiece(window, i , turnColor);
            dropPiece(i, turnColor);
            logicGrid.dropPiece(i,turnColor);
        }
    }
}

void DBoard::onHover(sf::RenderWindow &window) {
    if(logicGrid.hasWon()){
        for(int i = 0; i < this->cols; i++){
            topRow.setPieceOutlineThickness(i , 0);
            topRow.setPieceColor(i, NULL_COLOR);
        }
        return;
    }
    for(int i = 0; i < this->cols; i++){
        PieceColor turnColor = getTurnColor();

        if(MouseEvents::isHovered(visibleBoard[i], window) && !visibleBoard[i].isFull()){
            topRow.setPieceOutlineThickness(i , 2);
            topRow.setPieceColor(i, turnColor);
        } else {
            topRow.setPieceOutlineThickness(i , 0);
            topRow.setPieceColor(i, NULL_COLOR);
        }
    }
}

void DBoard::reset() {
    sf::Vector2f size = getSize();
    sf::Vector2f pos = getPosition();
    sf::Color color = getFillColor();

    logicGrid.reset();

    for(auto & i : visibleBoard){
        DBoardColumn bc(rows);
        i = bc;
    }

    setSize(size);
    setFillColor(color);
    setPosition(pos);
}

void DBoard::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!Stateable::checkState(HIDDEN)){
        target.draw(topRow);
        target.draw(restartButton);
        for(const auto & i : visibleBoard){
            target.draw(i);
        }
    }
}

void DBoard::eventHandler(sf::RenderWindow &window, sf::Event &event) {
    onClick(window);
    onHover(window);
    restartButton.eventHandler(window, event);

    if(MouseEvents::isClicked(restartButton, window)){
        reset();
    }
}
