#include <cctype>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

class Grid {
   public:
    void initialize() { grid.assign(9, ' '); }

    void set_player_char() {
        char ch;

        // validate input from user
        do {
            std::cout << "\nPlease choose character ('X' or 'O') "
                      << "for Player 1: ";
            std::cin >> ch;
            ch = std::toupper(ch);
        } while (ch != 'X' && ch != 'O');

        if (ch == 'O') {
            p1 = 'O';
            p2 = 'X';
        } else {
            p1 = 'X';
            p2 = 'O';
        }
    }

    void print_player_chars() {
        std::cout << "\n\nPlayer characters are" << std::endl;
        std::cout << "Player 1: " << p1 << std::endl;
        std::cout << "Player 2: " << p2 << std::endl;
    }

    void print() {
        std::cout << std::endl;
        for (int i = 0; i < 3; i++) {
            print_line();
            for (int j = 0; j < 3; j++) {
                std::cout << "|  " << grid[i * 3 + j] << "  ";
                if ((j + 1) % 3 == 0) std::cout << "|\n";
            }
        }
        print_line();
    }

    void print_guide() {
        std::cout << "\nPosition guide:" << std::endl;
        for (int i = 0; i < 3; i++) {
            print_line();
            for (int j = 0; j < 3; j++) {
                std::cout << "|  " << (i * 3 + j + 1) << "  ";
                if ((j + 1) % 3 == 0) std::cout << "|\n";
            }
        }
        print_line();
    }

    void update() {
        std::string player;
        int pos;
        char ch;
        if (turn) {
            player = "Player 1";
            ch = p1;
        } else {
            player = "Player 2";
            ch = p2;
        }

        std::cout << "\nPlease enter position (1 - 9) for " << player << ": ";
        std::cin >> pos;

        while (true) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Enter a number between 1 and 9: ";
                std::cin >> pos;
            } else if (pos < 1 || pos > 9) {
                std::cout << "\nInvalid position, please enter a value between "
                             "1 and 9: ";
                std::cin >> pos;
            } else if (grid[pos - 1] != ' ') {
                std::cout << "\nPosition already occupied, please enter a "
                             "different position: ";
                std::cin >> pos;
            } else {
                grid[pos - 1] = ch;
                break;
            }
        }

        // Update internal state after a valid move
        iterations += 1;
        turn = !turn;
    }

    bool determine_winner() {
        if (has_won(p1)) {
            std::cout << "\nPlayer 1 wins!! Congrats!!\n";
            return true;
        } else if (has_won(p2)) {
            std::cout << "\nPlayer 2 wins!! Congrats!!\n";
            return true;
        } else {
            if (is_complete()) std::cout << "\nMatch ends in a DRAW!!\n";
        }

        return false;
    }

    bool is_complete() { return (iterations == 9); }

   private:
    void print_line() { std::cout << "+-----+-----+-----+" << std::endl; }

    bool check_row(char ch, int row) {
        for (int i = 0; i < 3; i++) {
            if (grid[row * 3 + i] != ch) return false;
        }

        return true;
    }

    bool check_col(char ch, int col) {
        for (int i = 0; i < 3; i++) {
            if (grid[i * 3 + col] != ch) return false;
        }

        return true;
    }

    bool check_left_diag(char ch) {
        for (int i = 0; i < 9; i += 4) {
            if (grid[i] != ch) return false;
        }

        return true;
    }

    bool check_right_diag(char ch) {
        for (int i = 2; i <= 6; i += 2) {
            if (grid[i] != ch) return false;
        }

        return true;
    }

    bool has_won(char ch) {
        for (int i = 0; i < 3; i++) {
            // check each row
            if (check_row(ch, i)) return true;

            // check each col
            if (check_col(ch, i)) return true;
        }

        if (check_left_diag(ch)) return true;

        if (check_right_diag(ch)) return true;

        return false;
    }

    std::vector<char> grid;
    int iterations = 0;
    char p1, p2;
    bool turn = true;
};

int main() {
    Grid grid;

    grid.initialize();
    grid.set_player_char();

    grid.print_guide();
    grid.print_player_chars();

    while (!grid.is_complete()) {
        grid.print();

        grid.update();

        if (grid.determine_winner()) {
            grid.print();
            break;
        }
    }

    if (grid.is_complete()) {
        grid.print();
        grid.determine_winner();
    }
}