#include <iostream>
#include <memory>
#include "board.h"


Board::Board() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            squares[i][j] = nullptr; // Initialize all squares to empty
        }
    }
}
   


Board::~Board() {
    clearBoard();
}

void Board::clearBoard() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            delete squares[i][j]; // Free memory if piece exists
            squares[i][j] = nullptr; // Set square to empty
        }
    }
}




void Board::printBoard() const {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (squares[i][j] != nullptr) {
                std::cout << squares[i][j]->getSymbol() << " ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

bool Board::isSquareOccupied(int x, int y) const {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return false; // Out of bounds
    }
    return squares[x][y] != nullptr;
}


bool Board::placePiece(Piece* piece, int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        std::cerr << "Invalid position!" << std::endl;
        return false;
    }
    if (squares[x][y] != nullptr) {
        std::cerr << "Square already occupied!" << std::endl;
        return false;
    }
    squares[x][y] = piece;
    return true;

}

void Board::setupInitialPosition() {
    // Place pawns
    clearBoard(); // Clear the board before setting up
    for (int i = 0; i < 8; ++i) {
        placePiece(new Pawn(Piece::Colour::white, Piece::Type::pawn), 1, i);
        placePiece(new Pawn(Piece::Colour::black, Piece::Type::pawn), 6, i);
    }
    
    placePiece(new Rook(Piece::Colour::white, Piece::Type::rook), 0, 0);
    placePiece(new Rook(Piece::Colour::white, Piece::Type::rook), 0, 7);
    placePiece(new Rook(Piece::Colour::black, Piece::Type::rook), 7, 0);
    placePiece(new Rook(Piece::Colour::black, Piece::Type::rook), 7, 7);
    placePiece(new Knight(Piece::Colour::white, Piece::Type::knight), 0, 1);
    placePiece(new Knight(Piece::Colour::white, Piece::Type::knight), 0, 6);
    placePiece(new Knight(Piece::Colour::black, Piece::Type::knight), 7, 1);
    placePiece(new Knight(Piece::Colour::black, Piece::Type::knight), 7, 6);
    placePiece(new Bishop(Piece::Colour::white, Piece::Type::bishop), 0, 2);
    placePiece(new Bishop(Piece::Colour::white, Piece::Type::bishop), 0, 5);
    placePiece(new Bishop(Piece::Colour::black, Piece::Type::bishop), 7, 2);
    placePiece(new Bishop(Piece::Colour::black, Piece::Type::bishop), 7, 5);
    placePiece(new Queen(Piece::Colour::white, Piece::Type::queen), 0, 3);
    placePiece(new Queen(Piece::Colour::black, Piece::Type::queen), 7, 3);
    placePiece(new King(Piece::Colour::white, Piece::Type::king), 0, 4);
    placePiece(new King(Piece::Colour::black, Piece::Type::king), 7, 4); 
    
}



