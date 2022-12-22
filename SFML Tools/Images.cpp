//
// Created by Matthew Tapia on 12/11/22.
//

#include "Images.h"

std::map<ImagesEnum, sf::Texture> Images::map;

sf::Texture &Images::getImage(ImagesEnum image) {
    load(image);
    return map.at(image);
}

void Images::load(ImagesEnum image) {
    if(!map[image].loadFromFile(getPath(image))){
        exit(65);
    }
}

std::string Images::getPath(ImagesEnum image) {
    switch (image) {
        case CLUB:
            return "Images/Club.png";
        case DIAMOND:
            return "Images/Diamond.png";
        case HEART:
            return "Images/Heart.png";
        case SPADE:
            return "Images/Spade.png";
        case GREEN_BALL_THUMBNAIL:
            return "Images/Green_Ball.png";
        case BOUNCING_BALL_THUMBNAIL:
            return "Images/Bouncing_Ball.png";
        case PONG_THUMBNAIL:
            return "Images/Pong.png";
        case TOPHATGUY_THUMBNAIL:
            return "Images/Tophat_Guy.png";
        case CARD_THUMBNAIL:
            return "Images/Card.png";
        case POKER_THUMBNAIL:
            return "Images/Poker_Analysis.png";
        case C4_THUMBNAIL:
            return "Images/Connect_4.png";
        case LAST_IMAGE:
            return "";
    }
}
