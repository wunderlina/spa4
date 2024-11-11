//
// Created by leverencek on 11/9/2024.
//

#include "WampaRoom.h"
#include <iostream>
using namespace std;

void WampaRoom::display() {
    cout << " W ";
}

void WampaRoom::onEnter(Player *player) {
    cout << "You've entered the Wampa's lair!" << endl;
    cout << "The Wampa makes you its next meal." << endl;
    player->death();
}

std::string WampaRoom::getClueText() {
    return "you smell a wampa nearby";
}
