#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
public:
  void initialise();
  void display();
  void display_guide();
  bool make_move(int pos, char symbol);
  bool is_cell_empty(int pos);
  char check_winner();
  bool is_full();

private:
  void print_line();
  std::vector<char> board;
};

#endif // BOARD_H
