//
// Created by leverencek on 11/10/2024.
//

#ifndef DEFAULTROOM_H
#define DEFAULTROOM_H



#include "Player.h"


class DefaultRoom: public Room{
public:
    void display() override;
    std::string getClueText() override;
    void onEnter(Player *player) override;
};



#endif //DEFAULTROOM_H
