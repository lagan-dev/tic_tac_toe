#include "board.h"
#include <iostream>

void Board::initialise() { board.assign(9, ' '); }

void Board::display() {
  for (int i = 0; i < 3; i++) {
    print_line();
    for (int j = 0; j < 3; j++) {
      std::cout << "|  " << board[i * 3 + j] << "  ";
      if ((j + 1) % 3 == 0)
        std::cout << "|\n";
    }
  }
  print_line();
}

void Board::display_guide() {
  for (int i = 0; i < 3; i++) {
    print_line();
    for (int j = 0; j < 3; j++) {
      std::cout << "|  " << (i * 3 + j + 1) << "  ";
      if ((j + 1) % 3 == 0)
        std::cout << "|\n";
    }
  }
  print_line();
}

bool Board::make_move(int pos, char symbol) {
  if ((pos > 0 && pos <= board.size()) && board[pos - 1] == ' ') {
    board[pos - 1] = symbol;
    return true;
  }
  return false;
}

bool Board::is_cell_empty(int pos) { return (board[pos - 1] == ' '); }

char Board::check_winner() {
  const int win_patterns[8][3] = {
      {0, 1, 2}, // row 1
      {3, 4, 5}, // row 2
      {6, 7, 8}, // row 3
      {0, 3, 6}, // col 1
      {1, 4, 7}, // col 2
      {2, 5, 8}, // col 3
      {0, 4, 8}, // diagonal 1
      {2, 4, 6}, // diagonal 2
  };

  for (const auto &pattern : win_patterns) {
    auto first = board[pattern[0]];
    if (first != ' ' && first == board[pattern[1]] &&
        first == board[pattern[2]]) {
      return first; // 'X' or 'O'
    }
  }

  return ' ';
}

bool Board::is_full() {
  for (auto val : board) {
    if (val == ' ')
      return false;
  }

  return true;
}

int Board::board_size() { return board.size(); }
void Board::print_line() { std::cout << "+-----+-----+-----+" << std::endl; }
