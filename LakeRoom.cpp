//
// Created by leverencek on 11/9/2024.
//

#include "LakeRoom.h"

#include <iostream>
using namespace std;

void LakeRoom::display() {
    cout << " O ";
}

void LakeRoom::onEnter(Player *player) {
    player->loseHeat(10);
}

std::string LakeRoom::getClueText() {
    return "Is that ice or snow?";
}