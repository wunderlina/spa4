//
// Created by leverencek on 10/23/2024.
//

#include "Room.h"

Room::Room() {
    north = nullptr;
    east = nullptr;
    south = nullptr;
    west = nullptr;
}
void Room::setNeighbors(Room *n,Room *e,Room *s,Room *w) {
    north = n;
    east = e;
    south = s;
    west = w;
}

Room::~Room() {
    delete north;
    delete south;
    delete east;
    delete west;
}



Room *Room::getNorth() {
    return north;
}

Room *Room::getEast() {
    return east;
}

Room *Room::getSouth() {
    return south;
}

Room *Room::getWest() {
    return west;
}
