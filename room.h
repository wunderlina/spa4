//
// Created by leverencek on 10/23/2024.
//

#ifndef ROOM_H
#define ROOM_H
#include <string>


class room {
    room();
    room *north;
    room *south;
    room *east;
    room *west;

public:
    void display();
    std::string getClueText();
    room getNorth();
    room getSouth();
    room getEast();
    room getWest();
    void onEnter();

};



#endif //ROOM_H
