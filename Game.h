//
// Created by waltzc on 10/30/2024.
//

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Room.h"

class Room;
class Player;

class Game {
    Room* rooms[36];
    Player* player;
    bool isActive;

    void initializeRooms();
    void displayMap();
    void processInput(char c);

public:
    Game();
    ~Game();
    void startGame();
    void endGame(bool end);
    void displayHelp();
    char requestInput();
    Room* getRandomRoom();

};



#endif //GAME_H
