#ifndef INCLUDE_PLAYER_H
#define INCLUDE_PLAYER_H

class Player {
public:
  Player(char symbol);
  char get_symbol();
  int get_move();

private:
  char symbol;
};

#endif // INCLUDE_PLAYER_H
