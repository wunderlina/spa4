//
// Created by leverencek on 11/9/2024.
//

#ifndef BLASTERROOM_H
#define BLASTERROOM_H
#include "Room.h"


class BlasterRoom: public Room{
public:
    void display() override;
    std::string getClueText() override;
    void onEnter(Player *player) override;
};



#endif //BLASTERROOM_H
