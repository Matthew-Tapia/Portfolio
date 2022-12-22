//
// Created by Matthew Tapia on 12/10/22.
//

#ifndef PORTFOLIO_PORTFOLIOSCREEN_H
#define PORTFOLIO_PORTFOLIOSCREEN_H

#include <SFML/Graphics.hpp>
#include "../SFML Tools/Application.h"
#include "../Connect 4/C4Project.h"
#include "../SFML Tools/Fonts.h"
#include "Thumbnail.h"

class PortfolioScreen : public Component{
private:
    Application project;
    Thumbnail thumbnail;
    sf::Text title, spaceText;

public:
    PortfolioScreen();
    PortfolioScreen(const std::string& title, const sf::Texture& thumbnailTexture, Application& backgroundProject);

    void eventHandler(sf::RenderWindow &window, sf::Event &event) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //PORTFOLIO_PORTFOLIOSCREEN_H
