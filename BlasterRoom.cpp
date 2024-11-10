//
// Created by leverencek on 11/9/2024.
//

#include "BlasterRoom.h"

#include <iostream>
using namespace std;

void BlasterRoom::display() {
    cout << " > ";
}

void BlasterRoom::onEnter(Player *player) {
    player->getBlastershots();
}

std::string BlasterRoom::getClueText() {
    return "A glimmer in the white snow";
}