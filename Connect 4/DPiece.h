//
// Created by Matthew Tapia on 11/30/22.
//

#ifndef CONNECT_4_DPIECE_H
#define CONNECT_4_DPIECE_H

#include <SFML/Audio.hpp>
#include <iostream>
#include "../SFML Tools/Component.h"
#include "../SFML Tools/Position.h"
#include "Piece.h"
#include "../SFML Tools/Constants.h"

class DPiece : public Component{
private:
    Piece piece;
    sf::CircleShape circle;

    void updateColor();

public:
    DPiece();
    DPiece(int row, int col, PieceColor color);

    sf::Vector2f getPosition() const;
    sf::Color getFillColor() const;
    float getRadius() const;
    sf::FloatRect getGlobalBounds() const;
    int getRow() const;
    int getColumn() const;
    PieceColor getPieceColor() const;

    void setFillColor(const sf::Color& color);
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    void setRadius(float radius);
    void setRow(int row);
    void setColumn(int col);
    void setColor(PieceColor color);
    void setOutlineThickness(float thickness);


    void eventHandler(sf::RenderWindow &window, sf::Event &event) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


};


#endif //CONNECT_4_DPIECE_H
