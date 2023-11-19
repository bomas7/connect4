#include <vector>
#include <iostream>
//export module board;

enum class Slot {empty, player1, player2};

std::ostream& operator<<(std::ostream& out, const Slot& slot) {
        out << static_cast<int>(slot);
        return out;
}

constexpr int DEFAULT_ROWS = 6;
constexpr int DEFAULT_COLS = 7;

class Board {
public:
        Board(int rows=DEFAULT_ROWS, int cols=DEFAULT_COLS);

        bool full_col(int col);
        void place_slot(int col, Slot s);
        int x() const;
        int y() const;
        void print_board() const;

private:
        const int X_DIM;
        const int Y_DIM;
        std::vector<std::vector<Slot>> board;
        std::vector<int> column_peak;
};

Board::Board(int rows, int cols) 
        : X_DIM(cols)
        , Y_DIM(rows) 
        , board(rows, std::vector<Slot>(cols, Slot::empty))
        , column_peak(cols) {
}

int Board::x() const {
        return X_DIM;
}

int Board::y() const {
        return Y_DIM;
}

bool Board::full_col(int col) {
        return column_peak.at(col) == Y_DIM;
}

void Board::place_slot(int col, Slot s) {
        int placement = column_peak[col]++;
        board[placement][col] = s;
}

void Board::print_board() const {
        for (const auto& row: board) {
                for (const auto& slot: row) {
                        char out;
                        switch (slot) {
                                case Slot::player1:
                                        out = 'Y';
                                        break;
                                case Slot::player2:
                                        out = 'X';
                                        break;
                                default:
                                        out = 'O';
                        }
                        std::cout << out << " ";
                }
                std::cout << "\n";
        }
}

std::ostream& operator<<(std::ostream& out, const Board& board) {
        board.print_board();
        return out;
}

int main() {
        Board b{};
        for (int i = 0; i < DEFAULT_ROWS; ++i) {
                b.place_slot(3, Slot::player1);
        }
        b.print_board();
        return 0;
}
