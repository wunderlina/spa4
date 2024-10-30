//
// Created by wunderlina on 10/30/2024.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h"
#include "Room.h"


class Player {
private:
    int blastershots;
    Game &game;
    bool hasLightSaber;
    int heat;
    Room &location;
public:
    Player(Game game, Room location);
    void attack(char c);
    void capture();
    void death();
    void loseHeat(int i);
    void move(Room room);
    void pickupAmmo();
    void pickupLightsaber();
    void walk(char c);
    bool getHasLightSaber();
    int getBlastershots();
};



#endif //PLAYER_H
