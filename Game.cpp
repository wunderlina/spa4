//
// Created by waltzc on 10/30/2024.
//

#include "Game.h"
#include <iostream>
using namespace std;

const int NUM_ROOMS = 36;

void Game::initializeRooms() {
    for (int i = 0; i < NUM_ROOMS; i++) {
        rooms[i] = new Room();
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
        case 's':
        case 'e':
        case 'w':
            player->walk(c);
            break;
        case 'a':
            player->attack(c);
            break;
        case 'h':
            displayHelp();
            break;
        default:
            cout << "Invalid command" << endl;
            break;
    }
}

Game::Game() {
    initializeRooms();
    player = new Player(*this, *rooms[0]);
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
    cout << "Enter a command: ";
    cin >> c;
    return c;
}

Room Game::getRandomRoom() {
    return *rooms[rand() % NUM_ROOMS];
}


