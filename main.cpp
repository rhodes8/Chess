#include <iostream>
#include "board.h"
#include "pieces.h"







int main(){

Board chessBoard;


chessBoard.setupInitialPosition();
std::cout << "Initial chess board setup" << "\n";
std::cout << "------------------------------------" << std::endl;






std::cout << "Printing chess board" << "\n";
std::cout << "------------------------------------" << std::endl;
chessBoard.printBoard();



return 0;

}
