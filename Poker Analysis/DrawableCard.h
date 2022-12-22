//
// Created by Matthew Tapia on 11/3/22.
//

#ifndef POKER_ANALYSIS_DRAWABLECARD_H
#define POKER_ANALYSIS_DRAWABLECARD_H

#include <SFML/Graphics.hpp>
#include "../SFML Tools/Component.h"
#include "../SFML Tools/Fonts.h"
#include "Card.h"

class DrawableCard : public Component{
public:
    DrawableCard();
    DrawableCard(SuitEnum suit, RankEnum rank);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void eventHandler(sf::RenderWindow &window, sf::Event &event) override;

    void setFillColor(const sf::Color& color);
    void setSize(const sf::Vector2f& size);
    void setSize(float x, float y);
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);

    sf::Vector2f getSize() const;

private:
    sf::Font font;
    sf::Texture texture;

    Card baseCard;
    sf::RectangleShape background;
    sf::Text rankText, secondRankText;
    sf::Sprite suitSprite;

    void init();
    void setupSuit();
    void setupRank();
    void setupBackground();

    void fixSuitScale();
    void fixRankScale();

    std::string suitToFileName();
    std::string rankToCharacter();
};


#endif //POKER_ANALYSIS_DRAWABLECARD_H
