/*************************************************************************
Copyright 2014 Thomas Atkinson
This file is part of mkGame.
mkGame is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
mkGame is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with mkGame. If not, see <http://www.gnu.org/licenses/>.
*************************************************************************/

#include "humanPlayer.h"
#include "board.h"
#include "parseInput.h"

#include <string>

using namespace std;

humanPlayer::humanPlayer(int playerNum, Board *tempBoard){
    player = playerNum;
    playerBoard = tempBoard;
}
humanPlayer::~humanPlayer(){
    delete &player;
}

void humanPlayer::input(){
    int col = -1; //posx
    int row = -1; //posy

    string input;

    //if no errors it is a zero otherwise one
    int error = 1;

    while(error == 1){

	while(col < 0){
	    std::cout << "Enter position X: ";
	    getline(cin, input);
	    col = parseInput(input);
	    if(col == -1){
		cout << "Invalid Input please try again\n";
	    }
	}
	while(row < 0){
	    std::cout << "Enter position Y: ";
	    getline(cin, input);
	    row = parseInput(input);
	    if(row == -1){
		cout << "Invalid Input please try again\n";
	    }
	}

	//decrement row and col for the following function calls
	if(col > 0){
	col--;
	}
	if(row > 0){
	row--;
	}
		
	int inputReturn = playerBoard->playerInput(col, row, player);
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
