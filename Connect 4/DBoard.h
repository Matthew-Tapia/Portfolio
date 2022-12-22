//
// Created by Matthew Tapia on 11/30/22.
//

#ifndef CONNECT_4_DBOARD_H
#define CONNECT_4_DBOARD_H

#include <iostream>
#include "DBoardColumn.h"
#include "DBoardRow.h"
#include "Board.h"
#include "../SFML Tools/Sounds.h"
#include "RectangularRestartButton.h"

class DBoard : public Component{
private:
    int rows, cols;
    DBoardRow topRow;
    std::vector<DBoardColumn> visibleBoard;
    RectangularRestartButton restartButton;
    Board logicGrid;


public:
    DBoard();
    DBoard(int rows, int cols);

    sf::Vector2f getSize() const;
    sf::Vector2f getPosition() const;
    sf::Color getFillColor() const;
    sf::FloatRect getGlobalBounds() const;
    PieceColor getTurnColor() const;

    void setFillColor(const sf::Color& color);
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    void setSize(const sf::Vector2f& size);
    void setSize(float x, float y);
    void setRestartTextColor(const sf::Color& color);
    void setRestartButtonColor(const sf::Color& color);

    void animateDroppingPiece(sf::RenderWindow& window, int col, PieceColor color);
    void dropPiece(int col, PieceColor color);
    void onClick(sf::RenderWindow& window);
    void onHover(sf::RenderWindow& window);
    void reset();

    void eventHandler(sf::RenderWindow &window, sf::Event &event) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


};


#endif //CONNECT_4_DBOARD_H
