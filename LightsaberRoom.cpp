//
// Created by leverencek on 11/9/2024.
//

#include "LightsaberRoom.h"

#include <iostream>
using namespace std;

void LightsaberRoom::display() {
    cout << " | ";
}

void LightsaberRoom::onEnter(Player *player) {
    player->getBlastershots();
}

std::string LightsaberRoom::getClueText() {
    cout << "The force is strong here";
}