//
// Created by waltzc on 10/30/2024.
//

#include "Game.h"
#include "BlasterRoom.h"
#include <iostream>
using namespace std;

const int NUM_ROOMS = 36;

void Game::initializeRooms() {
    for (int i = 0; i < NUM_ROOMS; i++) {
        rooms[i] = new BlasterRoom();
    }
    for (int i = 0; i < NUM_ROOMS; i++) {
        Room* n = nullptr;
        if(i-6 >= 0) {
            n = rooms[i-6];
        }
        Room* e = nullptr;
        if((i+1)%6 != 0) {
            e = rooms[i+1];
        }
        Room* s = nullptr;
        if(i+6 < NUM_ROOMS) {
            s = rooms[i+6];
        }
        Room* w = nullptr;
        if(i%6 != 0) {
            w = rooms[i-1];
        }
        rooms[i]->setNeighbors(n,e,s, w);
    }
}

void Game::displayMap() {
    for (int i = 0; i < NUM_ROOMS; i++) {
        if (i % 6 == 0) {
            cout << endl;
        }
        cout << ". ";
    }
    cout << endl;
}

void Game::processInput(char c) {
    c = tolower(c);
    if(c == 'n' && player->getLocation()->getNorth() != nullptr) {
        player->walk(c);
    } else if(c == 'e' && player->getLocation()->getEast() != nullptr) {
        player->walk(c);
    } else if(c == 's' && player->getLocation()->getSouth() != nullptr) {
        player->walk(c);
    } else if(c == 'w' && player->getLocation()->getWest() != nullptr) {
        player->walk(c);
    } else if(c == 'b' && player->getBlastershots() > 0) {
        player->attack(c);
    } else if(c == 'l' && player->getHasLightSaber()) {
        player->attack(c);
    } else if(c == 'h') {
        displayHelp();
    } else if(c == 'q') {
        endGame(false);
    } else {
        cout << "Invalid command" << endl;
    }
}

Game::Game() {
    initializeRooms();
    player = new Player(this, rooms[0]);
    isActive = true;
}

Game::~Game() {
    delete player;
    for (int i = 0; i < NUM_ROOMS; i++) {
        delete rooms[i];
    }
}

void Game::startGame() {
    cout << "Welcome to the game!" << endl;
    while (isActive) {
        char input = requestInput();
        processInput(input);
    }
}

void Game::endGame(bool end) {
    isActive = !end;
}

void Game::displayHelp() {

}

char Game::requestInput() {
    string c;
    cout << "Action: ";
    if(player->getLocation()->getNorth() != nullptr) {
        std::cout << "(n)orth, ";
    }
    if(player->getLocation()->getEast() != nullptr) {
        std::cout << "(e)ast, ";
    }
    if(player->getLocation()->getSouth() != nullptr) {
        std::cout << "(s)outh, ";
    }
    if(player->getLocation()->getWest() != nullptr) {
        std::cout << "(w)est, ";
    }
    if(player->getBlastershots() > 0) {
        std::cout << "(b)laster [" << player->getBlastershots() << "], ";
    }
    if(player->getHasLightSaber()) {
        std::cout << "(l)ightsaber, ";
    }
    cout << "(h)elp, (q)uit" << endl << "-> ";
    std::cin >> c;
    if(c.size() == 1) {
        return c.at(0);
    } else {
        return '1';
    }
}

Room* Game::getRandomRoom() {
    return rooms[rand() % NUM_ROOMS];
}


