//
// Created by leverencek on 11/10/2024.
//

#include "DefaultRoom.h"
#include <iostream>
using namespace std;

void DefaultRoom::display() {
    cout << " r ";
}

void DefaultRoom::onEnter(Player *player) {
    player->loseHeat(2);
}

std::string DefaultRoom::getClueText() {
    return "The cold nips at you";
}