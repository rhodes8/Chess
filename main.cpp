#include <iostream>
#include "board.h"




int main(){


std::cout << "Initialising Chess board" << "\n";
std::cout << "------------------------------------" << std::endl;

Board chessBoard;

std::cout << "Printing chess board" << "\n";
std::cout << "------------------------------------" << std::endl;

chessBoard.printBoard();

return 0;

}
