//
// Created by wunderlina on 10/30/2024.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h"
#include "Room.h"

class Game;

class Player {
private:
    int blastershots;
    Game *game;
    bool hasLightSaber;
    int heat;
    Room *location;
public:
    Player(Game *game, Room *location);
    void attack(char c);
    void capture();
    void death();
    void loseHeat(int i);
    void move(Room *room);
    void pickupAmmo();
    void pickupLightsaber();
    void loseLightsaber();
    void walk(char c);
    bool getHasLightSaber();
    int getBlastershots();
    Room* getLocation();
};



#endif //PLAYER_H
