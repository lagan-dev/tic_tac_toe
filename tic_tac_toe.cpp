#include <iostream>
#include <utility>
#include <vector>

void initialize_grid(std::vector<char> &grid) {
    int n = 9;
    char ch = ' ';
    while (n--) {
        grid.push_back(ch);
    }
}

bool update_grid(std::vector<char> &grid, int pos, char ch) {
    if (grid[pos - 1] == ' ' && (pos >= 1 && pos <= 9)) {
        grid[pos - 1] = ch;
        return true;
    }

    return false;
}

void print_grid(std::vector<char> &grid) {
    std::cout << "\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "+-----";
            if ((j + 1) % 3 == 0) std::cout << "+\n";
        }
        for (int j = 0; j < 3; j++) {
            std::cout << "|  " << grid[i * 3 + j] << "  ";
            if ((j + 1) % 3 == 0) std::cout << "|\n";
        }
    }
    for (int j = 0; j < 3; j++) {
        std::cout << "+-----";
        if ((j + 1) % 3 == 0) std::cout << "+\n";
    }
}

bool check_row(std::vector<char> &grid, char ch, int row) {
    for (int i = 0; i < 3; i++) {
        if (grid[row * 3 + i] != ch) return false;
    }

    return true;
}

bool check_col(std::vector<char> &grid, char ch, int col) {
    for (int i = 0; i < 3; i++) {
        if (grid[i * 3 + col] != ch) return false;
    }

    return true;
}

bool check_left_diag(std::vector<char> &grid, char ch) {
    for (int i = 0; i < 9; i += 4) {
        if (grid[i] != ch) return false;
    }

    return true;
}

bool check_right_diag(std::vector<char> &grid, char ch) {
    for (int i = 6; i >= 2; i -= 2) {
        if (grid[i] != ch) return false;
    }

    return true;
}

bool check_status(std::vector<char> &grid, char ch) {
    for (int i = 0; i < 3; i++) {
        // check each row
        if (check_row(grid, ch, i)) return true;

        // check each col
        if (check_col(grid, ch, i)) return true;
    }

    if (check_left_diag(grid, ch)) return true;

    if (check_right_diag(grid, ch)) return true;

    return false;
}

int main() {
    std::vector<char> grid;
    int iterations = 0;

    // initialize empty grid
    initialize_grid(grid);
    bool p1_turn = true;

    char p1_char = 'X';
    char p2_char = 'O';

    int pos;
    std::cout << "Player 1: " << p1_char << '\n';
    std::cout << "Player 2: " << p2_char << '\n';

    while (iterations < 9) {
        // print the grid/board
        print_grid(grid);

        if (check_status(grid, 'X')) {
            std::cout << "\nPlayer 1 wins!!\n";
            break;
        }

        if (check_status(grid, 'O')) {
            std::cout << "\nPlayer 2 wins!!\n";
            break;
        }

        // get input from user
        std::cout << "Please enter position for ";

        if (p1_turn) {
            std::cout << "Player 1: ";
            std::cin >> pos;

            while (!update_grid(grid, pos, 'X')) {
                std::cout << "Please enter a different position: ";
                std::cin >> pos;
            }
        } else {
            std::cout << "Player 2: ";
            std::cin >> pos;

            while (!update_grid(grid, pos, 'O')) {
                std::cout << "Please enter a different position: ";
                std::cin >> pos;
            }
        }

        p1_turn = !p1_turn;
        iterations++;
    }

    if (iterations == 9) {
        print_grid(grid);

        if (check_status(grid, 'X')) {
            std::cout << "\nPlayer 1 wins!!\n";
        } else if (check_status(grid, 'O')) {
            std::cout << "\nPlayer 2 wins!!\n";
        } else {
            std::cout << "\nMatch ends in a DRAW!!\n";
        }
    }
}