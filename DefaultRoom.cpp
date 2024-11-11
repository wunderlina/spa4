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
    cout << "You get a little colder, but you're relatively safe for now" << endl;
    player->loseHeat(2);
}

std::string DefaultRoom::getClueText() {
    return "";
    return "The cold nips at you";
}