//
// Created by waltzc on 10/30/2024.
//

#ifndef Room_H
#define Room_H
#include <string>

#include "Player.h"

class Player;

class Room {
    Room *north;
    Room *south;
    Room *east;
    Room *west;

public:
    Room();
    virtual void display() = 0;
    virtual std::string getClueText() = 0;
    Room* getNorth();
    Room* getSouth();
    Room* getEast();
    Room* getWest();
    virtual void onEnter(Player *player) = 0;

};



#endif //Room_H