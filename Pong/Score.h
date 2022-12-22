//
// Created by Matthew Tapia on 12/7/22.
//

#ifndef PORTFOLIO_SCORE_H
#define PORTFOLIO_SCORE_H

#include <SFML/Graphics.hpp>
#include "../SFML Tools/Fonts.h"

class Score : public sf::Drawable{
private:
    int leftScore, rightScore;
    sf::Text text;

public:
    Score();

    void setString(const std::string& string);
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);

    void addLeftPoint();
    void addRightPoint();

    int& getLeftScore();
    int& getRightScore();

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //PORTFOLIO_SCORE_H
