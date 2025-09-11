
#ifndef PIECES_H
#define PIECES_H

#include <memory>
#include <vector>
#include <array>
#include <string>
#include <iostream>
#include "board.h"

class Board; // Forward declaration





class Piece{
    public:
        enum Type{
        none = 0,
        pawn = 1,
        bishop = 2,
        knight = 3,
        rook = 4,
        queen = 5,
        king = 6
    };
        enum Colour{
        white = 8,
        black = 16
    };
   
        Piece(Colour colour, Type type, bool moved = false);
        virtual ~Piece();
        virtual Piece::Colour getColour() const;
        virtual std::string getSymbol() const;
        virtual bool hasMoved();
        virtual bool setMoved();
        virtual std::vector<std::pair<int, int>> getPossibleMoves(int xs, int ys);
        virtual std::vector<std::pair<int, int>> getLegalMoves(Board &board, int xs, int ys);
    
    protected:
        Colour colour;
        Type type;
        bool moved;
};







class Pawn : public Piece {
    public:
        Pawn(Colour colour, Type type, bool moved = false);
        ~Pawn() override;
        
};

class Rook : public Piece {
    public:
        Rook(Colour colour, Type type, bool moved = false);
        ~Rook() override;
        std::vector<std::pair<int, int>> getPossibleMoves(int xs, int ys) override;
        std::vector<std::pair<int,int>> getLegalMoves(Board &board, int xs, int ys) override;
        
        
};

class Bishop : public Piece {
    public:
        Bishop(Colour colour, Type type, bool moved = false);
        ~Bishop() override;
        
};

class Knight : public Piece {
    public:
        Knight(Colour colour, Type type, bool moved = false);
        ~Knight() override;
        
};

class Queen : public Piece {
    public:
        Queen(Colour colour, Type type, bool moved = false);
        ~Queen() override;
        
};

class King : public Piece {
    public:
        King(Colour colour, Type type, bool moved = false);
        ~King() override;
        
};

#endif // PIECES_H