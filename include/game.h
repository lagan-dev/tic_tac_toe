#ifndef INCLUDE_GAME_H
#define INCLUDE_GAME_H

class Game {
public:
  void start();

private:
  int choose_mode();
  char choose_symbol();
  void start_PvP();
  void start_PvComputer();
};

#endif // INCLUDE_GAME_H
