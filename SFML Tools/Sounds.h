//
// Created by Matthew Tapia on 12/7/22.
//

#ifndef PORTFOLIO_SOUNDS_H
#define PORTFOLIO_SOUNDS_H

#include <map>
#include <SFML/Audio.hpp>
#include "SoundsEnum.h"

class Sounds {
public:
    static sf::SoundBuffer& getSound(SoundsEnum sound);

private:
    static std::map<SoundsEnum, sf::SoundBuffer> map;
    static void load(SoundsEnum sound);
    static std::string getPath(SoundsEnum sound);
};


#endif //PORTFOLIO_SOUNDS_H
