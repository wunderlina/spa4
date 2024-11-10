//
// Created by leverencek on 11/9/2024.
//

#include "WampaRoom.h"
#include <iostream>
using namespace std;

void WampaRoom::display() {
    cout << " @ ";
}

void WampaRoom::onEnter(Player *player) {
    player->death();
}

std::string WampaRoom::getClueText() {
    return "you smell a wampa nearby";
}
