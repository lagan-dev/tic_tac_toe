#include "player.h"
#include <iostream>
#include <limits>

Player::Player(char symbol) : symbol(symbol) {}

char Player::get_symbol() { return symbol; }

int Player::get_move() {
  int pos;
  std::cout << "Player " << get_symbol()
            << ", please enter a position between 1 and 9: ";
  std::cin >> pos;

  while (true) {
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Enter a number between 1 and 9: ";
      std::cin >> pos;
    } else {
      break;
    }
  }

  return pos;
}
