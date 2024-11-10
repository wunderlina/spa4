//
// Created by leverencek on 11/10/2024.
//

#include "TauntaunRoom.h"
#include <iostream>
using namespace std;

void TauntaunRoom::display() {
    cout << " & ";
}

void TauntaunRoom::onEnter(Player *player) {
    player->loseHeat(-10);
}

std::string TauntaunRoom::getClueText() {
    return "Jeez I guess I could get warm in that beast";
}