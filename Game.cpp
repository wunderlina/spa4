//
// Created by waltzc on 10/30/2024.
//

#include "Game.h"
#include "BlasterRoom.h"
#include <iostream>
#include <vector>
#include <algorithm>

#include "AmbushRoom.h"
#include "LakeRoom.h"
#include "LightsaberRoom.h"
#include "WampaRoom.h"
#include "TauntaunRoom.h"
#include "DefaultRoom.h"

using namespace std;

const int NUM_ROOMS = 36;

void Game::initializeRooms() {
    for (int i = 0; i < NUM_ROOMS; i++) {
        rooms[i] = new DefaultRoom();
    }

    vector<int> specialRooms;
    while (specialRooms.size() < 6) {
        int index = rand() % NUM_ROOMS;
        if (find(specialRooms.begin(), specialRooms.end(), index) == specialRooms.end()) {
            specialRooms.push_back(index);
        }
    }

    rooms[specialRooms[0]] = new BlasterRoom();
    rooms[specialRooms[1]] = new LightsaberRoom();
    rooms[specialRooms[2]] = new WampaRoom();
    rooms[specialRooms[3]] = new TauntaunRoom();
    rooms[specialRooms[4]] = new LakeRoom();
    rooms[specialRooms[5]] = new AmbushRoom();

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
        if (rooms[i] == player->getLocation()) {
            cout << " @ ";
        } else {
            rooms[i]->display();
        }
    }
    cout << endl;
    cout << "Key:" << endl;
    cout << " @ - You" << endl;
    cout << " * - Room" << endl;
    cout << " B - Blaster" << endl;
    cout << " L - Lightsaber" << endl;
    cout << " W - Wampa" << endl;
    cout << " T - Tauntaun" << endl;
    cout << " P - Pond" << endl;
    cout << " A - Ambush" << endl;
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
    } else if(c == 'm') {
        displayMap();
    } else if(c == 'q') {
        endGame(false);
    } else {
        cout << "Invalid command" << endl;
    }
}

Game::Game() {
    initializeRooms();
    int start = rand() % NUM_ROOMS;
    // while (rooms[start]->getClueText() != "The cold nips at you") {
    //     start = rand() % NUM_ROOMS;
    // }
    while (rooms[start]->getClueText() != "") {
        start = rand() % NUM_ROOMS;
    }
    player = new Player(this, rooms[start]);
    isActive = true;
}

Game::~Game() {
    delete player;
    for (int i = 0; i < NUM_ROOMS; i++) {
        delete rooms[i];
    }
}

void Game::startGame() {
    cout << "Welcome to Hunt the Wampa!" << endl;
    while (isActive) {
        char input = requestInput();
        processInput(input);
    }
}

void Game::endGame(bool end) {
    isActive = false;
    cout << "Exiting game" << endl;
}

void Game::displayHelp() {
    cout << "Rules for 'Hunt the Wampa'\n\n";

    cout << "The Wampa lives in a cave of 36 rooms, laid out in a square pattern -\n";
    cout << "most rooms connect to four other adjacent rooms, but not all of them do.\n";
    cout << "The edges connect to three other rooms and the corners connect to two other rooms.\n\n";

    cout << "Hazards:\n";
    cout << "Frigid Pond - One room has a frigid pond. If you fall in, your temperature\n";
    cout << "will start to fall at a dangerous rate. Find and kill the Wampa quickly, or\n";
    cout << "find a lightsaber and a tauntaun, and use its insides for warmth.\n\n";

    cout << "Wampa:\n";
    cout << "The Wampa resides in its home cavern and stores its food in another.\n";
    cout << "If you walk into its home, you are killed, and the game is over.\n";
    cout << "If you walk into its storage, it will take you to another room, and you\n";
    cout << "will end up stuck in the ceiling. If you have a lightsaber, you can cut\n";
    cout << "yourself down, but if not, you will die of low temperature.\n\n";

    cout << "Weapons/Tools:\n";
    cout << "Blaster - You start with a blaster with 5 shots, and you can find one more\n";
    cout << "in the cave system. The blaster will kill the Wampa if you shoot it.\n";
    cout << "Lightsaber - You can find a fragile lightsaber in the cave system.\n";
    cout << "You can use it to free yourself from ice, cut open a tauntaun, or swing\n";
    cout << "at the Wampa. Be careful, however, as after one use it will break.\n\n";

    cout << "Map: A 6x6 square with randomly generating hazard rooms, item rooms,\n";
    cout << "and Wampa rooms.\n";
    cout << endl;
}

char Game::requestInput() {
    Room* location = player->getLocation();
    std::vector<int> directions = {1, 2, 3, 4};
    for(int i = 0; i < directions.size();) {
        int g = std::rand() % directions.size();
        switch(directions.at(g)) {
            case 1:
                if(location->getNorth() != nullptr) {
                    std::cout << location->getNorth()->getClueText() << std::endl;
                }
            break;
            case 2:
                if(location->getEast() != nullptr) {
                    std::cout << location->getEast()->getClueText() << std::endl;
                }
            break;
            case 3:
                if(location->getSouth() != nullptr) {
                    std::cout << location->getSouth()->getClueText() << std::endl;
                }
            break;
            case 4:
                if(location->getWest() != nullptr) {
                    std::cout << location->getWest()->getClueText() << std::endl;
                }
            break;
        }
        directions.erase(directions.begin() + g);
    }
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
    cout << "(h)elp, (m)ap, (q)uit" << endl << "-> ";
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


