#include "main.h"
#include "board.h"
#include "player.h"
#include "computerPlayer.h"
#include "humanPlayer.h"

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int boardSize, winLengh;
    cout << "Please enter M: ";
    cin >> boardSize;
    
    cout << "Please enter K: ";
    cin >> winLengh;
    while (winLengh > boardSize){
	cout << "K needs to be as big or smaller then M" << endl
	     << "Please enter K: ";
	cin >> winLengh;
    }

    Board board(boardSize, winLengh);

    int i = 1;
    Player *player[2];
    while(i != 56){
	cout << "Please enter game type:\n 1) Human vs Human\n 2) Human vs Computer\n 3) Computer vs Computer";
	cin >> i;
	if(i == 1){
	    player[0]  = new humanPlayer(1);
	    player[1] = new humanPlayer(2); 
	    i = 56;
	} else if(i == 2){
	    player[0] = new humanPlayer(1);
	    player[1] = new computerPlayer(2); 
	    i = 56;
	} else if(i == 3){
	    player[0] = new computerPlayer(1);
	    player[1] = new computerPlayer(2); 
	    i =56;
	} else {
	    cout << "Input out of range please enter new value";
	}
    }

    //Let players veiw board before starting game
    board.printBoard();
 
    //we want an infinate loop and we check the result after every play
    while(1){
	player[0]->input(board);
	board.printBoard();
	checkResult = board.checkIfGameWon(1);
	if(checkResult == 1){
	    cout << "Player 1 won the game!" << endl;
	    exit(0);
	} else if(checkResult == 2) {
	    cout << "The game was a tie" << endl;
	    exit(0);
	}
	player[1]->input(board);
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
