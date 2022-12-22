//
// Created by Matthew Tapia on 12/11/22.
//

#ifndef PORTFOLIO_IMAGES_H
#define PORTFOLIO_IMAGES_H

#include <SFML/Graphics.hpp>
#include <map>
#include "ImagesEnum.h"

class Images {
public:
    static sf::Texture& getImage(ImagesEnum image);

private:
    static std::map<ImagesEnum, sf::Texture> map;
    static void load(ImagesEnum image);
    static std::string getPath(ImagesEnum image);
};


#endif //PORTFOLIO_IMAGES_H
