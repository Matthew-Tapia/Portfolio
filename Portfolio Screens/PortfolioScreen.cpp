//
// Created by Matthew Tapia on 12/10/22.
//

#include "PortfolioScreen.h"

PortfolioScreen::PortfolioScreen() {
    Application app;
    PortfolioScreen("DEFAULT SCREEN", sf::Texture(), app);
}

PortfolioScreen::PortfolioScreen(const std::string& title, const sf::Texture& thumbnailTexture, Application &backgroundProject) : thumbnail(thumbnailTexture), project(backgroundProject){
    thumbnail.setScale({0.5, 0.5});
    thumbnail.setPosition({(float)(1280 - thumbnail.getGlobalBounds().width/2),(float)(800 - thumbnail.getGlobalBounds().height/2)});

    this->title.setString(title);
    this->title.setFont(Fonts::getFont(ROBOTO));
    this->title.setCharacterSize(100);
    this->title.setPosition({(float)(thumbnail.getGlobalBounds().left + thumbnail.getGlobalBounds().width/2 - this->title.getGlobalBounds().width/2),(float)(thumbnail.getGlobalBounds().top/2 - this->title.getGlobalBounds().height/2)});

    spaceText.setString("PRESS SPACE TO PLAY");
    spaceText.setFont(Fonts::getFont(ROBOTO));
    spaceText.setCharacterSize(100);
    spaceText.setPosition({(float)(1280 - spaceText.getGlobalBounds().width/2),(float)(thumbnail.getGlobalBounds().top + thumbnail.getGlobalBounds().height)});
}

void PortfolioScreen::eventHandler(sf::RenderWindow &window, sf::Event &event) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        project.run();
    }
}

void PortfolioScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(thumbnail);
    target.draw(title);
    target.draw(spaceText);
}

