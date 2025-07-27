#ifndef PLAYER_H
#define PLAYER_H

// #include "board.h"

class Player {
public:
  Player(char symbol);
  char get_symbol();
  int get_move();

private:
  char symbol;
};

#endif