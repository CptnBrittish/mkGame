#include "main.h"
#include "board.h"
#include "humanPlayer.h"

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    Board board;

    humanPlayer player[2] = {humanPlayer(1) , humanPlayer(2)};

    //Let players veiw board before starting game
    board.printBoard();
 
    //we want an infinate loop and we check the result after every play
    while(1){
	player[0].input(board);
	board.printBoard();
	checkResult = board.checkIfGameWon();
	if(checkResult == 1){
	    cout << "Player 1 won the game!" << endl;
	    exit(0);
	} else if(checkResult == 2) {
	    cout << "The game was a tie" << endl;
	    exit(0);
	}
	player[1].input(board);
	board.printBoard();
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
    //wonder what number that becomes?
}
