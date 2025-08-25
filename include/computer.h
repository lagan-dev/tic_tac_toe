#ifndef INCLUDE_COMPUTER_H
#define INCLUDE_COMPUTER_H
#include "board.h"

class Computer {
public:
  Computer(char symbol);
  char get_symbol();
  int get_move(Board board);

private:
  char symbol;
};

#endif // INCLUDE_COMPUTER_H
