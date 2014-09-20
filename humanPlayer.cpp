#include "humanPlayer.h"
#include "board.h"

humanPlayer::humanPlayer(int playerNum){
    player = playerNum;
}
humanPlayer::~humanPlayer(){
    delete &player;
}

void humanPlayer::input(Board &playerBoard){
    int col = 0; //posx
    int row = 0; //posy
    //if no errors it is a zero otherwise one
    int error = 1;

    while(error == 1){
	
	std::cout << "Enter position X: ";
	std::cin >> col;
	std::cout << "Enter position Y: ";
	std::cin >> row;
	//decrement row and col for the following function calls
	col--;
	row--;
		
	int inputReturn = playerBoard.playerInput(col, row, player);
	if(inputReturn == -1){
	    std::cout << "Input was out of range" << std::endl << "Please enter a diffrent position" << std::endl;
	    error = 1;    
	} else if(inputReturn == -2){
	    std::cout << "Position already taken" << std::endl << "Please enter a diffrent position" << std::endl;
	    error = 1;    
	} else if(inputReturn == 1){
	    error = 0;    
	}
    }

}
