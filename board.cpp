#include <iostream>
#include "board.h"


Board::Board(){

    board.fill(0);
}


void Board::printBoard(){
    for (int i = 0; i < 64; ++i){
        std::cout << board[i] << " ";
        if ((i + 1) % 8 == 0){
            std::cout << std::endl;
        }
    }

}


















