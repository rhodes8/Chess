#ifndef BOARD_H
#define BOARD_H

#include "pieces.h"

#include <array>
#include <iostream>

class Piece; // Forward declaration



class Board {
public:
    static constexpr int BOARD_SIZE = 8;
 

    Board();
    ~Board();

    bool isSquareOccupied(int x, int y) const;
    bool placePiece(Piece* piece, int x, int y);
    Piece* getPiece(int x, int y);
    void setupInitialPosition();
    void printBoard() const;


    

protected:
 // 8x8 board represented as a 2D array

    void clearBoard();

    std::array<std::array<Piece* , BOARD_SIZE>, BOARD_SIZE> squares;

};

#endif // BOARD_H





