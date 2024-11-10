//
// Created by waltzc on 10/30/2024.
//

#include "Game.h"
#include "WampaRoom.h"
#include <iostream>
using namespace std;

const int NUM_ROOMS = 36;

void Game::initializeRooms() {
    for (int i = 0; i < NUM_ROOMS; i++) {
        rooms[i] = new WampaRoom();
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
    switch (tolower(c)) {
        case 'n':
            player->walk(c);
            break;
        case 's':
            player->walk(c);
            break;
        case 'e':
            player->walk(c);
            break;
        case 'w':
            player->walk(c);
            break;
        case 'b':
            player->attack(c);
            break;
        case 'l':
            player->attack(c);
            break;
        case 'h':
            displayHelp();
            break;
        case 'q':
            //TODO
        default:
            cout << "Invalid command" << endl;
            break;
    }
}

Game::Game() {
    initializeRooms();
    player = new Player(*this, rooms[0]);
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
    char c;
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
        std::cout << "(b)laster, ";
    }
    if(player->getHasLightSaber()) {
        std::cout << "(l)ightsaber, ";
    }
    cout << "(h)elp, (q)uit: ";
    cin >> c;
    return c;
}

Room* Game::getRandomRoom() {
    return rooms[rand() % NUM_ROOMS];
}


