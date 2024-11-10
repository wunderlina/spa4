//
// Created by leverencek on 11/9/2024.
//

#include "BlasterRoom.h"

#include <iostream>
using namespace std;

BlasterRoom::BlasterRoom() {
    empty == false;
}

void BlasterRoom::display() {
    cout << " > ";
}

void BlasterRoom::onEnter(Player *player) {
    if (!empty) {
        player->pickupAmmo();
        empty = true;
    }
}

std::string BlasterRoom::getClueText() {
    return "A glimmer in the white snow";
}