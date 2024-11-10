//
// Created by leverencek on 10/23/2024.
//

#include "Room.h"

Room::Room() {
    north = this - 6;
    south = this + 6;
    east = this + 1;
    west = this - 1;
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
