#include <vector>
#include <iostream>
//export module board;

enum class Slot {empty, player1, player2};

class Board {
public:
        Board(int x=7, int y=6);
        int x();
        int y();
        void print_board();
private:
        const int X_DIM;
        const int Y_DIM;
        std::vector<std::vector<Slot>> board;
};

Board::Board(int x, int y) 
        : X_DIM(x), Y_DIM(y), board(x, std::vector<Slot>(y, Slot::empty)) {
}

int Board::x() {
        return X_DIM;
}

int Board::y() {
        return Y_DIM;
}

void Board::print_board() {
        for (int i = 0; i < X_DIM; ++i) {
                for (int j = 0; j < Y_DIM; ++j) {
                        char out;
                        switch (board[i][j]) {
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

int main() {
        Board b{};
        b.print_board();
        return 0;
}
