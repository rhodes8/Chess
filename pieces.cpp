#include "pieces.h"
#include "board.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <array>




Piece::Piece(Colour colour, Type type, bool moved):  colour(colour), type(type), moved{false} {}

Piece::~Piece() = default;

Piece::Colour Piece::getColour() const {
    return colour;
}
   
Piece::Type Piece::getType() const {
    return type;
}

std::string Piece::getstringType()  {
    Piece::Type type = this->getType();
    switch (type) {
        case Piece::Type::pawn: return "Pawn";
        case Piece::Type::bishop: return "Bishop";
        case Piece::Type::knight: return "Knight";
        case Piece::Type::rook: return "Rook";
        case Piece::Type::queen: return "Queen";
        case Piece::Type::king: return "King";
        default: return "None";
    }
}   


bool Piece::hasMoved() {
    return moved;
}

 bool Piece::setMoved() {
    moved = true;
    return moved;
}




std::string Piece::getSymbol() const {
    switch (type) {
        case Piece::Type::pawn: return colour  == Piece::Colour::white ? "P" : "p";
        case Piece::Type::bishop: return colour == Piece::Colour::white ? "B" : "b";
        case Piece::Type::knight: return colour == Piece::Colour::white ? "N" : "n";
        case Piece::Type::rook: return colour == Piece::Colour::white ? "R" : "r";
        case Piece::Type::queen: return colour == Piece::Colour::white ? "Q" : "q";
        case Piece::Type::king: return  colour == Piece::Colour::white ? "K" : "k";
        default: return ".";
    }
}



std::vector<std::pair<int, int>> Piece::getLegalMoves(Board &board, int xs, int ys) {
    return {};
}





Pawn::Pawn(Colour colour, Type type, bool moved) : Piece(colour, Type::pawn, moved) {}
Pawn::~Pawn() = default;
bool Pawn::hasEnPassant() {}






Rook::Rook(Colour colour, Type type, bool moved) : Piece(colour, Type::rook, moved) {}
Rook::~Rook() = default;
std::vector<std::pair<int,int>> Rook::getLegalMoves(Board &board, int xs, int ys){
    std::vector<std::pair<int,int>> legalMoves{};
    const int directions[4][2] = {
        {-1, 0},
        {1, 0},
        {0, 1},
        {0, -1}
    };
    for (const auto& dir : directions){
        int x = xs + dir[0];
        int y = ys + dir[1];
        while (x >= 0 && x < Board::BOARD_SIZE && y >= 0 && y < Board::BOARD_SIZE) {
            if (board.isSquareOccupied(x, y)) {
                if (board.getPiece(x, y)->getColour() != this->getColour()) {
                    legalMoves.emplace_back(x, y);
                }
                break;
            }
            legalMoves.emplace_back(x, y);
            x += dir[0];
            y += dir[1];
        }
        
    }
    return legalMoves;


}





Bishop::Bishop(Colour colour, Type type, bool moved) : Piece(colour, Type::bishop, moved) {}
Bishop::~Bishop() = default;
std::vector<std::pair<int,int>> Bishop::getLegalMoves(Board &board, int xs, int ys){
    std::vector<std::pair<int,int>> legalMoves{};
    const int directions[4][2] = {
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1}

    };
    for (const auto& dir : directions){
        int x = xs + dir[0];
        int y = ys + dir[1];
        while(x >= 0 && x < Board::BOARD_SIZE && y >= 0 && y < Board::BOARD_SIZE){
            if (board.isSquareOccupied(x,y)){
                if(board.getPiece(x, y)->getColour() != this->getColour()){
                    legalMoves.emplace_back(x,y);
                }
                break;
            }
            legalMoves.emplace_back(x,y);
            x += dir[0];
            y += dir[1];
        }

    }
    return legalMoves;


}











Knight::Knight(Colour colour, Type type, bool moved) : Piece(colour, Type::knight, moved) {}
Knight::~Knight() = default;

std::vector<std::pair<int,int>> Knight::getLegalMoves(Board &board, int xs, int ys){
    std::vector<std::pair<int,int>> legalMoves{};
    const int moves[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
    for (const auto& move : moves){
        int x = xs + move[0];
        int y = ys + move[1];
        while(x >= 0 && x < Board::BOARD_SIZE && y >= 0 && y < Board::BOARD_SIZE){
            if (board.isSquareOccupied(x,y)){
                if(board.getPiece(x, y)->getColour() != this->getColour()){
                    legalMoves.emplace_back(x,y);
                }
                break;
            }
            legalMoves.emplace_back(x,y);
            x += dir[0];
            y += dir[1];
        }

    }
    return legalMoves;
}







Queen::Queen(Colour colour, Type type, bool moved) : Piece(colour, Type::queen, moved) {}
Queen::~Queen() = default;
std::vector<std::pair<int,int>> Queen::getLegalMoves(Board &board, int xs, int ys){
    std::vector<std::pair<int,int>> legalMoves{};
    const int moves[8][2] = {
        {0, 1}, {1, 1}, {1, 0}, {1, -1}, 
        {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}
        
    };
    for (const auto& move : moves){
        int x = xs + move[0];
        int y = ys + move[1];

        if (x >= 0 && x < Board::BOARD_SIZE && y >= 0 && y < Board::BOARD_SIZE) {
            if (!board.isSquareOccupied(x, y) || board.getPiece(x, y)->getColour() != this->getColour()) {
                legalMoves.emplace_back(x, y);
            }
        }

    }
    return legalMoves;
    

}

King::King(Colour colour, Type type, bool moved) : Piece(colour, Type::king, moved) {}
King::~King() = default;