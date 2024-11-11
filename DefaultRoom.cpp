//
// Created by leverencek on 11/10/2024.
//

#include "DefaultRoom.h"
#include <iostream>
using namespace std;

void DefaultRoom::display() {
    cout << " * ";
}

void DefaultRoom::onEnter(Player *player) {
    std::cout << "You enter a barren cavern, nothing but snow and ice here" << std::endl;
    player->loseHeat(2);
}

std::string DefaultRoom::getClueText() {
    return "";
    return "The cold nips at you";
}