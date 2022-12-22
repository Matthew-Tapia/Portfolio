//
// Created by Matthew Tapia on 12/6/22.
//

#include "Fonts.h"

std::map<FontsEnum, sf::Font> Fonts::map;

sf::Font &Fonts::getFont(FontsEnum font) {
    load(font);
    return map.at(font);
}

void Fonts::load(FontsEnum font) {
    if(!map[font].loadFromFile(getPath(font))){
        exit(65);
    }
}

std::string Fonts::getPath(FontsEnum font) {
    switch (font) {
        case OPEN_SANS:
            return "Fonts/OpenSans-Bold.ttf";
        case ROBOTO:
            return "Fonts/Roboto-Regular.ttf";
        case GAMEPLAY:
            return "Fonts/Gameplay.ttf";
        case LAST_FONT:
            return "";
    }
}
