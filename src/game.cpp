#include "game.h"
#include "board.h"
#include "computer.h"
#include "player.h"
#include <cctype>
#include <iostream>
#include <limits>

int Game::choose_mode() {
  int mode;
  std::cout << "Choose a mode for playing:\n";
  std::cout << "0 for PvP and 1 for PvComputer: ";
  while (true) {
    std::cin >> mode;
    if (!std::cin.fail() && (mode == 0 || mode == 1)) {
      break;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Enter 0 or 1: ";
  }

  return mode;
}

char Game::choose_symbol() {
  char symbol;
  std::cout << "\nPlease select symbol for Player 1 (X or O): ";

  while (true) {
    std::cin >> symbol;
    if (!std::cin.fail() &&
        (symbol == 'X' || symbol == 'O' || symbol == 'x' || symbol == 'o')) {
      symbol = std::toupper(symbol);
      break;
    }

    std::cout << "\nInvalid input!!";
    std::cout << "\nPlease select symbol for Player 1 (X or O): ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  return symbol;
}

Player *switch_player(Player *current, Player &p1, Player &p2) {
  return (current->get_symbol() == p1.get_symbol()) ? &p2 : &p1;
}

void Game::start_PvP() {
  char symbol_1, symbol_2;

  symbol_1 = choose_symbol();
  symbol_2 = (symbol_1 == 'X') ? 'O' : 'X';

  Player p1(symbol_1);
  Player p2(symbol_2);
  Board board;
  board.initialise();

  std::cout << "\nSymbol for Player 1: " << p1.get_symbol() << std::endl;
  std::cout << "\nSymbol for Player 2: " << p2.get_symbol() << std::endl;

  Player *current_player = &p1;

  // Display the position guide
  board.display_guide();

  while (!board.is_full()) {
    bool valid_move = false;
    do {
      int pos = current_player->get_move();
      valid_move = board.make_move(pos, current_player->get_symbol());
      if (!valid_move) {
        std::cout << "Invalid move. Please try again." << std::endl;
      }
    } while (!valid_move);

    // Display the current state of the board
    board.display();

    // Check if the move ends the game
    char winner = board.check_winner();
    if (winner != ' ') {
      std::cout << "Player " << winner << " won the game!!" << std::endl;
      break;
    }

    // Switch player
    current_player = (switch_player(current_player, p1, p2));
  }

  if (board.is_full()) {
    char winner = board.check_winner();
    if (winner == ' ') {
      std::cout << "Match ends in a draw!!" << std::endl;
    }
  }
}

void Game::start_PvComputer() {
  char symbol_1, symbol_2;

  symbol_1 = choose_symbol();
  symbol_2 = (symbol_1 == 'X') ? 'O' : 'X';

  Player player(symbol_1);
  Computer comp(symbol_2);

  std::cout << "\nSymbol for Player 1: " << player.get_symbol() << std::endl;
  std::cout << "\nSymbol for Player 2: " << comp.get_symbol() << std::endl;

  Board board;
  board.initialise();

  // Display the position guide
  board.display_guide();

  while (!board.is_full()) {
    bool valid_move = false;
    do {
      int pos = player.get_move();
      valid_move = board.make_move(pos, player.get_symbol());
      if (!valid_move) {
        std::cout << "Invalid move. Please try again." << std::endl;
      }
    } while (!valid_move);

    // Display the current state of the board
    board.display();

    // Check if the move ends the game
    char winner = board.check_winner();
    if (winner != ' ') {
      std::cout << "Player " << winner << " won the game!!" << std::endl;
      break;
    }

    // Computer's turn
    std::cout << "\nComputer's turn:\n";
    board.make_move(comp.get_move(board), comp.get_symbol());

    // Display the current state of the board
    board.display();

    // Check if the move ends the game
    winner = board.check_winner();
    if (winner != ' ') {
      std::cout << "Player " << winner << " won the game!!" << std::endl;
      break;
    }
  }

  if (board.is_full()) {
    char winner = board.check_winner();
    if (winner == ' ') {
      std::cout << "Match ends in a draw!!" << std::endl;
    }
  }
}

void Game::start() {
  int mode = choose_mode();

  switch (mode) {
  case 0:
    start_PvP();
    break;

  case 1:
    start_PvComputer();
    break;
  }
}
