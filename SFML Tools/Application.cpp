//
// Created by Matthew Tapia on 12/6/22.
//

#include "Application.h"


Application::Application() : Application({2560, 1600, 32}, "Application"){

}

Application::Application(sf::VideoMode videoMode, const std::string &title) : videoMode(videoMode), title(title){
    backgroundColor = sf::Color::White;
    width = videoMode.width;
    height = videoMode.height;
}

Application::Application(const Application &application) {
    for(int i = 0; i < application.components.size(); i++){
        this->components.push_back(application.components[i]);
    }

    this->videoMode = application.videoMode;
    this->title = application.title;
    this->width = application.width;
    this->height = application.height;
    this->backgroundColor = application.backgroundColor;
}

void Application::run() {
    sf::RenderWindow window(videoMode, title);
    window.setFramerateLimit(60);

    while(window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
        }

        for(EventHandleable *c : components){
            c -> eventHandler(window, event);
        }

        window.clear(backgroundColor);

        for(sf::Drawable* c : components){
            window.draw(*c);
        }

        window.display();
    }
}

void Application::addComponent(Component &component) {
    components.push_back(&component);
}

int Application::getWidth() const {
    return width;
}

int Application::getHeight() const {
    return height;
}

void Application::setBackgroundColor(const sf::Color &color) {
    backgroundColor = color;
}
