//
// Created by Matthew Tapia on 12/7/22.
//

#ifndef PORTFOLIO_PONG_H
#define PORTFOLIO_PONG_H

#include "Paddle.h"
#include "Ball.h"
#include "Score.h"
#include "../SFML Tools/Component.h"

class Pong : public Component{
private:
    Paddle leftPaddle, rightPaddle;
    Ball ball;
    Score gameScore;

public:
    Pong();

    //Setters+getter for paddles
    void setLeftPaddlePosition(const sf::Vector2f& position);
    void setLeftPaddlePosition(float x, float y);
    void setLeftPaddleSize(const sf::Vector2f& position);
    void setLeftPaddleSize(float x, float y);
    void setLeftPaddleSpeed(float speed);

    sf::Vector2f getLeftPaddleSize() const;

    void setRightPaddlePosition(const sf::Vector2f& position);
    void setRightPaddlePosition(float x, float y);
    void setRightPaddleSize(const sf::Vector2f& position);
    void setRightPaddleSize(float x, float y);
    void setRightPaddleSpeed(float speed);

    sf::Vector2f getRightPaddleSize() const;



    //setters+getters for score
    void setScorePosition(const sf::Vector2f& position);
    void setScorePosition(float x, float y);

    //setters+getters for ball
    void setBallPosition(const sf::Vector2f& position);
    void setBallPosition(float x, float y);
    void setBallRadius(int radius);
    void setBallVelocity(const sf::Vector2f& velocity);
    void setBallFillColor(const sf::Color& color);



    void eventHandler(sf::RenderWindow &window, sf::Event &event) override;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};


#endif //PORTFOLIO_PONG_H
