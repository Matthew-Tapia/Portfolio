//
// Created by Matthew Tapia on 11/30/22.
//

#ifndef CONNECT_4_DBOARDCOLUMN_H
#define CONNECT_4_DBOARDCOLUMN_H

#include "DBoardPeg.h"
#include <vector>
#include <chrono>
#include <thread>


class DBoardColumn : public Component{
private:
    int size;
    std::vector<DBoardPeg> column;

public:
    DBoardColumn();
    DBoardColumn(int size);

    sf::Vector2f getSize() const;
    sf::Vector2f getPosition() const;
    sf::Color getFillColor() const;
    sf::FloatRect getGlobalBounds() const;
    bool isFull() const;

    void setFillColor(const sf::Color& color);
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    void setSize(const sf::Vector2f& size);
    void setSize(float x, float y);

    void animateDroppingPiece(sf::RenderWindow& window, PieceColor color);
    void dropPiece(PieceColor color);
    void onClick(sf::RenderWindow& window, PieceColor color);
    void reset();

    void eventHandler(sf::RenderWindow &window, sf::Event &event) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //CONNECT_4_DBOARDCOLUMN_H
