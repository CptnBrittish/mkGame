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

#include "main.h"
#include "board.h"
#include "player.h"
#include "computerPlayer.h"
#include "humanPlayer.h"
#include "parseInput.h"

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
    int boardSize = -1, winLengh = -1;
    string input;
    while(boardSize < 0){
	cout << "Please enter M: ";
	getline(cin, input);
	boardSize = parseInput(input);
	if(boardSize == -1 || boardSize == 0){
	    cout << "Invalid Input please try again\n";
	}
    }  
    while(winLengh < 0){
	cout << "Please enter K: ";
	getline(cin, input);
	winLengh = parseInput(input);
	if(winLengh == -1){
	    cout << "Invalid Input please try again\n";
	}
    }
    while (winLengh > boardSize){
	cout << "K needs to be as big or smaller then M" << endl
	     << "Please enter K: ";
	cin >> winLengh;
    }


    cout << endl;

    Board board(boardSize, winLengh);

    int opponantChoice = -1;
    bool correctChoiceRange = false;
    Player *player[2];
    while(correctChoiceRange == false){
	cout << "Game types avaliable:\n 1) Human vs Human\n 2) Human vs Computer\n 3) Computer vs Computer\nPlease choose a game type: ";
    
	while(opponantChoice < 0){
	    getline(cin, input);
	    opponantChoice = parseInput(input);
	    if(opponantChoice == -1){
		cout << "Invalid Input please try again\n";
	    }
	}
	
	cout << endl;
	if(opponantChoice == 1){
	    player[0]  = new humanPlayer(1, &board);
	    player[1] = new humanPlayer(2, &board); 
	    correctChoiceRange = true;
	} else if(opponantChoice == 2){
	    player[0] = new humanPlayer(1, &board);
	    player[1] = new computerPlayer(2, &board); 
	    correctChoiceRange = true;
	} else if(opponantChoice == 3){
	    player[0] = new computerPlayer(1, &board);
	    player[1] = new computerPlayer(2, &board); 
	    correctChoiceRange = true;
	} else {
	    cout << "Input out of range please enter new value" << endl;
	}
    }




    //Let players veiw board before starting game
    board.printBoard();
 
    //we want an infinate loop and we check the result after every play
    while(1){
	cout << "Player 1's turn" << endl;
	player[0]->input();
	board.printBoard();
	checkResult = board.checkIfGameWon(1);
	if(checkResult == 1){
	    cout << "Player 1 won the game!" << endl;
	    exit(0);
	} else if(checkResult == 2) {
	    cout << "The game was a tie" << endl;
	    exit(0);
	}
	cout << "Player 2's turn" << endl;
	player[1]->input();
	board.printBoard();
	checkResult = board.checkIfGameWon(2);
	if(checkResult == 1){
	    cout << "Player 2 won the game!" << endl;
	    exit(0);
	} else if(checkResult == 2) {
	    cout << "The game was a tie" << endl;
	    exit(0);
	}	
    }
    //If we somehow managed to end up here the world is imploding and chaos theory had its last laugh
    //Like seriously we should not be here
    return -1000;
   
}
