//
// Created by leverencek on 11/9/2024.
//

#ifndef WAMPAROOM_H
#define WAMPAROOM_H
#include "Room.h"


class WampaRoom: public Room{
public:
    void display() override;
    std::string getClueText() override;
    void onEnter(Player *player) override;
};



#endif //WAMPAROOM_H
