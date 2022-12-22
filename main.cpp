#include "Connect 4/C4Project.h"
#include "Pong/PongProject.h"
#include "TophatGuy/TophatProject.h"
#include "Bouncing Ball/BouncingBallProject.h"
#include "Green Ball/GreenBallProject.h"
#include "Card/CardProject.h"
#include "Poker Analysis/PokerAnalysisProject.h"
#include "Portfolio Screens/PortfolioScreen.h"
#include "SFML Tools/Images.h"

int main() {
    sf::RenderWindow window({2560, 1600, 32}, "Portfolio");
    window.setFramerateLimit(60);
    std::vector<PortfolioScreen> screens;

    sf::Texture thumbnails[7] = {
            Images::getImage(GREEN_BALL_THUMBNAIL),
            Images::getImage(BOUNCING_BALL_THUMBNAIL),
            Images::getImage(PONG_THUMBNAIL),
            Images::getImage(TOPHATGUY_THUMBNAIL),
            Images::getImage(CARD_THUMBNAIL),
            Images::getImage(POKER_THUMBNAIL),
            Images::getImage(C4_THUMBNAIL)
    };

    GreenBallProject gb;
    BouncingBallProject bb;
    PongProject p;
    TophatProject th;
    CardProject c;
    PokerAnalysisProject pa;
    C4Project c4;

    Application hiddenProjects[7] = {gb, bb, p, th, c, pa, c4};

    std::string titles[7] = {"Green Ball", "Bouncing Ball", "Pong", "Tophat Guy", "Card", "Poker Analysis",
                             "Connect 4"};

    for (int i = 0; i < 7; i++) {
        Application app;
        screens.push_back(PortfolioScreen(titles[i], thumbnails[i], hiddenProjects[i]));
    }

    auto iter = screens.begin();

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                if (iter != screens.begin())
                    --iter;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                if (iter != screens.end() - 1)
                    ++iter;
            }
        }

        iter->eventHandler(window, event);

        window.clear(sf::Color(0x202020FF));
        window.draw(*iter);
        window.display();
    }

    return 0;
}
