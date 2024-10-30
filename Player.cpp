//
// Created by wunderlina on 10/30/2024.
//

#include "Player.h"
#include <iostream>

Player::Player(Game game, Room location): game(), location() {
    this->location = location;
    this->game = game;
    this->hasLightSaber = false;
    this->blastershots = 5;
    this->heat = 50;
}
void Player::attack(char c) {
    char direction = 'i';
    while (!(direction == 'n' || direction == 'e' || direction == 's' || direction == 'w')) {
        std::cout << "Choose a direction: ";
        if(location.getNorth() != nullptr) {
            std::cout << "(n)orth ";
        }
        if(location.getEast() != nullptr) {
            std::cout << "(e)ast ";
        }
        if(location.getSouth() != nullptr) {
            std::cout << "(s)outh ";
        }
        if(location.getWest() != nullptr) {
            std::cout << "(w)est ";
        }
        std::cout << std::endl << "-> ";
        std::cin >> direction;
        direction = tolower(direction);
    }
    if(c == 'l') {
        hasLightSaber = false;
    }else if(c == 'b') {
        blastershots -= 1;
    }
    Room* target = nullptr;
    if(direction == 'n') {
        target = location.getNorth();
    }else if(direction == 'e') {
        target = location.getEast();
    }else if(direction == 's') {
        target = location.getSouth();
    }else if(direction == 'w') {
        target = location.getWest();
    }
    if(target->getClueText() == "you smell a wampa nearby") {
        game.endGame(true);
    }
}
void Player::move(Room room) {
    this->location = room;
    room.onEnter(this);
}
void Player::walk(char c) {
    Room *destination = nullptr;
    if(c == 'n') {
        destination = location.getNorth();
    }else if(c == 'e') {
        destination = location.getEast();
    }else if(c == 'w') {
        destination = location.getWest();
    }else if(c == 's') {
        destination = location.getSouth();
    }
    this->move(*destination);
}
void Player::capture() {
    this->move(game.getRandomRoom());
}
void Player::death() {
    game.endGame();
}
void Player::loseHeat(int i) {
    this->heat -= i;
}
void Player::pickupAmmo() {
    this->blastershots += 1;
}
void Player::pickupLightsaber() {
    this->hasLightSaber = true;
}
bool Player::getHasLightSaber() {
    return this->hasLightSaber;
}
int Player::getBlastershots() {
    return this->blastershots;
}
