//
// Created by Matthew Tapia on 12/9/22.
//

#ifndef PORTFOLIO_PROBABILITYTEXT_H
#define PORTFOLIO_PROBABILITYTEXT_H

#include <SFML/Graphics.hpp>
#include "../SFML Tools/Component.h"
#include "../SFML Tools/Fonts.h"

class ProbabilityText : public Component{
private:
    sf::Text text;

public:
    ProbabilityText();

    void setString(const std::string& text);
    void setCharacterSize(int size);
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);

    void eventHandler(sf::RenderWindow &window, sf::Event &event) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //PORTFOLIO_PROBABILITYTEXT_H
