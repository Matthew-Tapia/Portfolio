//
// Created by Matthew Tapia on 11/30/22.
//

#ifndef CONNECT_4_DBOARDPEG_H
#define CONNECT_4_DBOARDPEG_H

#include <SFML/Graphics.hpp>
#include "DPiece.h"
#include "../SFML Tools/MouseEvents.h"

class DBoardPeg : public Component{
private:
    sf::RectangleShape background;
    DPiece piece;

public:
    DBoardPeg();
    DBoardPeg(DPiece piece);

    sf::Vector2f getSize() const;
    sf::Vector2f getPosition() const;
    sf::Color getFillColor() const;
    sf::FloatRect getGlobalBounds() const;
    int getPieceRow() const;
    int getPieceColumn() const;
    PieceColor getPieceColor() const;

    void setFillColor(const sf::Color& color);
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    void setSize(const sf::Vector2f& size);
    void setSize(float x, float y);
    void setPieceRow(int row);
    void setPieceColumn(int col);
    void setPieceColor(PieceColor color);
    void setPieceOutlineThickness(float thickness);

    void reset();

    void eventHandler(sf::RenderWindow &window, sf::Event &event) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //CONNECT_4_DBOARDPEG_H
