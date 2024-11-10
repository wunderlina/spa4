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
    player->getBlastershots();
}

std::string WampaRoom::getClueText() {
    cout << "you smell a wampa nearby";
}
