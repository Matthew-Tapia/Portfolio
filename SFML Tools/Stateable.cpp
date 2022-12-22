//
// Created by Matthew Tapia on 12/7/22.
//

#include "Stateable.h"

Stateable::Stateable() {
    load();
}

bool Stateable::checkState(StatesEnum state) const{
    return map.at(state);
}

void Stateable::enableState(StatesEnum state) {
    setState(state, true);
}

void Stateable::disableState(StatesEnum state) {
    setState(state, false);
}

void Stateable::toggleState(StatesEnum state) {
    setState(state, !checkState(state));
}

void Stateable::setState(StatesEnum state, bool value) {
    map.at(state) = value;
}

void Stateable::load() {
    for(int i = 0; i < LAST_STATE; i++){
        map[(StatesEnum)(i)] = false;
    }
}