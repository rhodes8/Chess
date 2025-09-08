#ifndef PIECE_H
#define PIECE_H


#include <vector>
#include <string>



enum class PieceColour { WHITE, BLACK};

enum class PieceType {
    None = 0,
    Pawn = 1,
    Knight = 2,
    Bishop = 4,
    Rook = 8,
    Queen = 16,
    King = 32

};







class Pieces{
public:
    

    Pieces(PieceColour colour);
    virtual ~Piece() = default;

    virtual std::vector<int> getPossibleMoves(int currentPosition, const Board& board) const = 0;


    PieceColour getColour() const;

    virtual PieceType getPieceType() const = 0;


    bool hasMoved();
    void setHasMoved();

protected:
    PieceColour colour;

    bool moved;
};



#endif