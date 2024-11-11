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
    cout << " B ";
}

void BlasterRoom::onEnter(Player *player) {
    if (!empty) {
        cout << "You found a shot for your blaster!" << endl;
        player->pickupAmmo();
        empty = true;
    }
}

std::string BlasterRoom::getClueText() {
    return "A glimmer in the white snow";
}