#include <iostream>
#include "Player.h"
#include "Room.h"
#include "Game.h"

int main() {
    srand(time(0));
    Game game;
    game.startGame();
    return 0;
}
