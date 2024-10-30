//
// Created by waltzc on 10/30/2024.
//

#ifndef GAME_H
#define GAME_H

#include "room.h"

class game {
    room rooms[];
    void displayHelp();
    player requestInput(char c);

public:
    void startGame();
    void endGame();
    room getRandomRoom();

};



#endif //GAME_H
