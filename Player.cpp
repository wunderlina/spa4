//
// Created by wunderlina on 10/30/2024.
//

#include "Player.h"
#include <iostream>


Player::Player(Game *game, Room *location): game(game), location(location) {
    this->hasLightSaber = false;
    this->blastershots = 3;
    this->heat = 30;
}
void Player::attack(char c) {
    char direction = 'i';
    while (!(direction == 'n' || direction == 'e' || direction == 's' || direction == 'w')) {
        std::cout << "Choose a direction: ";
        if(location->getNorth() != nullptr) {
            std::cout << "(n)orth ";
        }
        if(location->getEast() != nullptr) {
            std::cout << "(e)ast ";
        }
        if(location->getSouth() != nullptr) {
            std::cout << "(s)outh ";
        }
        if(location->getWest() != nullptr) {
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
        target = location->getNorth();
    }else if(direction == 'e') {
        target = location->getEast();
    }else if(direction == 's') {
        target = location->getSouth();
    }else if(direction == 'w') {
        target = location->getWest();
    }
    if(target == nullptr) {
        std::cout << "Invalid command" << std::endl;
        if(c == 'l') {
            hasLightSaber = true;
        }else if(c == 'b') {
            blastershots += 1;
        }
    }else {
        if(target->getClueText() == "you smell a wampa nearby") {
            std::cout << "You have killed the wampa, congratulations!" << std::endl;
            game->endGame(true);
        } else {
            std::cout << "You have missed your target" << std::endl;
            if (c == 'l') {
                std::cout << "You have lost your lightsaber" << std::endl;
            }
        }
    }
}
void Player::move(Room *room) {
    this->location = room;
    room->onEnter(this);
}
void Player::walk(char c) {
    this->loseHeat(1);
    if(heat > 10) {
        std::cout << "You get a little colder, but you're relatively safe for now" << std::endl;
    } else {
        std::cout << "You get a little colder, you will soon freeze!" << std::endl;
    }
    Room *destination = location;
    if(c == 'n') {
        destination = location->getNorth();
    }else if(c == 'e') {
        destination = location->getEast();
    }else if(c == 'w') {
        destination = location->getWest();
    }else if(c == 's') {
        destination = location->getSouth();
    }
    this->move(destination);
}
void Player::capture() {
    this->move(game->getRandomRoom());
    if (hasLightSaber) {
        std::cout << "You have been captured by the wampa, but you are able to free yourself with your lightsaber" << std::endl;
        std::cout << "However, you have lost your lightsaber in the process" << std::endl;
        std::cout << std::endl;
        hasLightSaber = false;
    }else {
        std::cout << "You have been captured by the wampa, with no way to free yourself" << std::endl;
        std::cout << "You freeze to death hanging from the ceiling" << std::endl;
        std::cout << std::endl;
        game->endGame(true);
    }
}
void Player::death() {
    game->endGame(true);
}
void Player::loseHeat(int i) {
    this->heat -= i;
    if(heat <= 0) {
        std::cout << "You feel your blood turn to ice, you freeze to death" << std::endl;
        death();
    }
    if(heat > 30) {
        this->heat = 30;
    }
}
void Player::pickupAmmo() {
    this->blastershots += 1;
}
void Player::pickupLightsaber() {
    this->hasLightSaber = true;
}
void Player::loseLightsaber() {
    this->hasLightSaber = false;
}
bool Player::getHasLightSaber() {
    return hasLightSaber;
}
int Player::getBlastershots() {
    return blastershots;
}
Room* Player::getLocation() {
    return location;
}
