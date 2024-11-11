//
// Created by leverencek on 11/9/2024.
//

#include "LakeRoom.h"

#include <iostream>
using namespace std;

void LakeRoom::display() {
    cout << " P ";
}

void LakeRoom::onEnter(Player *player) {
    cout << "You fall through a thin layer of ice and into the freezing water!" << endl;
    player->loseHeat(10);
}

std::string LakeRoom::getClueText() {
    return "Is that ice or snow?";
}