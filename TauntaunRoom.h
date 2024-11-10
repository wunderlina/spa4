//
// Created by leverencek on 11/10/2024.
//

#ifndef TAUNTAUNROOM_H
#define TAUNTAUNROOM_H



#include "Player.h"


class TauntaunRoom: public Room{
public:
    void display() override;
    std::string getClueText() override;
    void onEnter(Player *player) override;
};



#endif //TAUNTAUNROOM_H
