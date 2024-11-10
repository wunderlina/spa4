//
// Created by leverencek on 11/9/2024.
//

#include "AmbushRoom.h"

#include <iostream>
using namespace std;

void AmbushRoom::display() {
    cout << " * ";
}

void AmbushRoom::onEnter(Player *player) {
    player->capture();
}

string AmbushRoom::getClueText() {
    cout << "Something doesn't sound quite right...";
}


