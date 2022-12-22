//
// Created by Matthew Tapia on 12/7/22.
//

#include "Sounds.h"

std::map<SoundsEnum, sf::SoundBuffer> Sounds::map;


sf::SoundBuffer &Sounds::getSound(SoundsEnum sound) {
    load(sound);
    return map.at(sound);
}

void Sounds::load(SoundsEnum sound) {
    if(!map[sound].loadFromFile(getPath(sound))){
        exit(63);
    }
}

std::string Sounds::getPath(SoundsEnum sound) {
    switch (sound) {
        case PIECE_SLIDING:
            return "Sounds/Connect_4_Sliding_Piece.wav";
        case LAST_SOUND:
            return "";
    }
}
