#ifndef GAME_H
#define GAME_H

// #include <iostream>

class Game {
public:
    void start();

private:
    int choose_mode();
    char choose_symbol();
    void start_PvP();
    void start_PvComputer();
};

#endif