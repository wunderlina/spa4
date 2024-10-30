//
// Created by waltzc on 10/30/2024.
//

#ifndef GAME_H
#define GAME_H

#include "Room.h"

class Game {
    Room rooms[];
    void displayHelp();
    Player requestInput(char c);

public:
    void startGame();
    void endGame();
    Room getRandomRoom();

};



#endif //GAME_H
