#ifndef BOARD_H
#define BOARD_H

#include <array>


class Board{
public:
    Board();

    void printBoard();


private:
    std::array<int, 64> board;
};

#endif // BOARD_H