//
// Created by leverencek on 11/9/2024.
//

#ifndef LAKEROOM_H
#define LAKEROOM_H
#include "Player.h"


class LakeRoom: public Room{
public:
    void display() override;
    std::string getClueText() override;
    void onEnter(Player *player) override;
};



#endif //LAKEROOM_H
