//
// Created by Matthew Tapia on 12/2/22.
//

#ifndef CONNECT_4_RECTANGULARBUTTON_H
#define CONNECT_4_RECTANGULARBUTTON_H

#include "../SFML Tools/Component.h"
#include <functional>
#include <iostream>
#include "../SFML Tools/MouseEvents.h"
#include "../SFML Tools/Position.h"
#include "../SFML Tools/Fonts.h"

class RectangularButton : public Component{
private:
    sf::RectangleShape box;
    sf::Text text;
    sf::Color backgroundColor, hoverColor;

public:
    RectangularButton();
    RectangularButton(std::string title);

    sf::FloatRect getGlobalBounds() const;
    sf::Vector2f getPosition() const;

    virtual void setSize(const sf::Vector2f& size);
    virtual void setSize(float x, float y);

    void setTextSize(unsigned int size);
    void setString(const std::string& text);
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    void setBackgroundColor(const sf::Color& color);
    void setTextColor(const sf::Color& color);

    virtual void onClick(sf::RenderWindow &window);

    void eventHandler(sf::RenderWindow& window, const sf::Event& event);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


};


#endif //CONNECT_4_RECTANGULARBUTTON_H
