#include "pieces.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "pieces.h"




Piece::Piece(Colour colour, Type type, bool moved):  colour(colour), type(type), moved{false} {}

Piece::~Piece() = default;

Piece::Colour Piece::getColour() const {
    return colour;
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

std::vector<std::pair<int, int>> Piece::getPossibleMoves(int xs, int ys) {
    return {};
}

std::vector<std::pair<int, int>> Piece::getLegalMoves(int xs, int ys) {
    return {};
}





Pawn::Pawn(Colour colour, Type type, bool moved) : Piece(colour, Type::pawn, moved) {}
Pawn::~Pawn() = default;






Rook::Rook(Colour colour, Type type, bool moved) : Piece(colour, Type::rook, moved) {}
Rook::~Rook() = default;
std::vector<std::pair<int,int>> Rook::getPossibleMoves(int xs, int ys) {
    std::vector<std::pair<int, int>> moves;
    for (int i = 0; i < 8; ++i) {
        if (i != xs) moves.emplace_back(i, ys); // Vertical moves
        if (i != ys) moves.emplace_back(xs, i); // Horizontal moves
    }
    return moves;
}





Bishop::Bishop(Colour colour, Type type, bool moved) : Piece(colour, Type::bishop, moved) {}
Bishop::~Bishop() = default;

Knight::Knight(Colour colour, Type type, bool moved) : Piece(colour, Type::knight, moved) {}
Knight::~Knight() = default;

Queen::Queen(Colour colour, Type type, bool moved) : Piece(colour, Type::queen, moved) {}
Queen::~Queen() = default;

King::King(Colour colour, Type type, bool moved) : Piece(colour, Type::king, moved) {}
King::~King() = default;