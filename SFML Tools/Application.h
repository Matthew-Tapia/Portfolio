//
// Created by Matthew Tapia on 12/6/22.
//

#ifndef PORTFOLIO_APPLICATION_H
#define PORTFOLIO_APPLICATION_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Component.h"
#include "Constants.h"
#include <iostream>

class Application {
private:
    std::vector<Component*> components;
    sf::VideoMode videoMode;
    std::string title;
    int width, height;
    sf::Color backgroundColor;

public:
    Application();
    Application(const Application& application);
    Application(sf::VideoMode videoMode, const std::string& title);

    void run();

    void addComponent(Component& component);
    void setBackgroundColor(const sf::Color& color);

    int getWidth() const;
    int getHeight() const;
};


#endif //PORTFOLIO_APPLICATION_H
