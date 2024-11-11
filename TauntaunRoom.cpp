//
// Created by leverencek on 11/10/2024.
//

#include "TauntaunRoom.h"
#include <iostream>
using namespace std;

void TauntaunRoom::display() {
    cout << " T ";
}

void TauntaunRoom::onEnter(Player *player) {
    if (player->getHasLightSaber()) {
        cout << "You use your lightsaber to slice open the tauntaun and climb inside to get warm" << endl;
        cout << "You feel your body temperature rise, but your lightsaber has broken" << endl;
        player->loseHeat(-10);
        player->loseLightsaber();
    } else {
        cout << "You find a tauntaun, but you have nothing to cut it open with" << endl;
    }
}

std::string TauntaunRoom::getClueText() {
    return "Jeez I guess I could get warm in that beast";
}