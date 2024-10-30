//
// Created by waltzc on 10/30/2024.
//

#ifndef Room_H
#define Room_H
#include <string>


class Room {
    Room();
    Room *north;
    Room *south;
    Room *east;
    Room *west;

public:
    void display();
    std::string getClueText();
    Room getNorth();
    Room getSouth();
    Room getEast();
    Room getWest();
    void onEnter();

};



#endif //Room_H