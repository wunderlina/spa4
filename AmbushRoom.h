//
// Created by leverencek on 11/9/2024.
//

#ifndef AMBUSHROOM_H
#define AMBUSHROOM_H
#include "Room.h"


class AmbushRoom : public Room{
public:
    void display() override;
    std::string getClueText() override;
    void onEnter(Player *player) override;
};



#endif AMBUSHROOM_H
