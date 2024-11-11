//
// Created by leverencek on 11/9/2024.
//

#ifndef LIGHTSABERROOM_H
#define LIGHTSABERROOM_H
#include "Room.h"


class LightsaberRoom: public Room{
    bool empty;
public:
    LightsaberRoom();
    void display() override;
    std::string getClueText() override;
    void onEnter(Player *player) override;
};




#endif //LIGHTSABERROOM_H
