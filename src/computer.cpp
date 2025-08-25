#include "computer.h"

Computer::Computer(char _symbol) : symbol(_symbol) {}

char Computer::get_symbol() { return symbol; }

int Computer::get_move(Board board) {
  int pos = 0;
  for (int i = 0; i < board.board_size(); i++) {
    if (board.is_cell_empty(i))
      return i;
  }

  return pos;
}
