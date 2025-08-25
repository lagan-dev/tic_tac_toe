#ifndef INCLUDE_BOARD_H_
#define INCLUDE_BOARD_H_

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
  int board_size();

private:
  void print_line();
  std::vector<char> board;
};

#endif // INCLUDE_BOARD_H_
