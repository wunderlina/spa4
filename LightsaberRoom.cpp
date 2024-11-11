//
// Created by leverencek on 11/9/2024.
//

#include "LightsaberRoom.h"

#include <iostream>
using namespace std;

LightsaberRoom::LightsaberRoom() {
    empty = false;
}

void LightsaberRoom::display() {
    cout << " L ";
}

void LightsaberRoom::onEnter(Player *player) {
    if (!empty) {
        if(!player->getHasLightSaber()) {
            cout << "You found a lightsaber!" << endl;
            player->pickupLightsaber();
            empty = true;
        }
    }
}

std::string LightsaberRoom::getClueText() {
    return "The force is strong here";
}