//
// Created by waltzc on 10/30/2024.
//

#ifndef Room_H
#define Room_H
#include <string>

#include "Player.h"


class Room {
    Room *north;
    Room *south;
    Room *east;
    Room *west;

public:
    Room();
    virtual ~Room();
    virtual void display();
    virtual std::string getClueText();
    Room* getNorth();
    Room* getSouth();
    Room* getEast();
    Room* getWest();
    virtual void onEnter(Player *player);

};



#endif Room_H