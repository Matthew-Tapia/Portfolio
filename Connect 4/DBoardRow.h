//
// Created by Matthew Tapia on 12/2/22.
//

#ifndef CONNECT_4_DBOARDROW_H
#define CONNECT_4_DBOARDROW_H

#include "DBoardPeg.h"
#include <vector>

class DBoardRow : public Component{
private:
    int size;
    std::vector<DBoardPeg> row;

public:
    DBoardRow();
    DBoardRow(int size);

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
    void setPieceColor(int col, PieceColor color);
    void setPieceOutlineThickness(int col, float thickness);

    void reset();

    void eventHandler(sf::RenderWindow &window, sf::Event &event) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};



#endif //CONNECT_4_DBOARDROW_H
