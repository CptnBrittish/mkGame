/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the code
has been written/produced for me by another person or copied from any
other source.
I hold a copy of this assignment that I can produce if the original is
lost or damaged.
**************************/


#include "computerPlayer.h"
#include "board.h"

computerPlayer::computerPlayer(int playerNum){
    player = playerNum;
    if(player == 1){
	opponant = 2;
    } else {
	opponant = 1;
    }
}


int computerPlayer::findMove(int &col, int &row, int M, int K, int **board){
    if(findPersonToBlock(col, row, M, K, opponant, board) == 1){
	return 1;
    } else {
	for(int i = 0; i < M; i++){
	    for(int j = 0; j < M; j++){
		if(board[i][j] == 0){
		    col = i;
		    row = j;

		    //return from function now otherwise we go to the end of theboard
		    return 1;
		}
	    }
	}
    }

    return 1;

}

int computerPlayer::findPersonToBlock(int &x, int &y, int M, int K, int playerNum, int **boardState){

    int numInRow = 0;
    x = 0;
    y = 0;
    //Check if a person has won the game vertically
    for(int col = 0; col < M; col++){
	x++;
	for(int row = 0; row < M; row++){
	    y++;
	    if(boardState[col][row] == playerNum){
		numInRow++;
	    } else {
		numInRow = 0;
	    }
	    if(numInRow == K){
		y = y+1;
		return 1;
	    }
	}
    }
    numInRow = 0;

    x = 0;
    y = 0;
    	
    //check to see if a person has won the game horizontally
    for(int row = 0; row < M; row++){
	y++;
	for(int col = 0; col < M; col++){
	    x++;
	    if(boardState[col][row] == playerNum){
		numInRow++;
	    } else {
		numInRow = 0;
	    }
	    if(numInRow == K){
		y = y + 1;
		return 1;
	    }
	}
    }
    x = 0;
    y = 0;
    //check if game won diagonally
    //we need to do this in the fowards and back direction
    for(int row = 0; row < M; row++){
	y = row;
	for(int col = 0; col < M; col++){
	    x = col;
	    //Only check this once as it applies to both directions
	    if(boardState[col][row] == playerNum){
		for(int i = 1, j = 1; j < K; i++, j++){
		    x++;
		    y--;
		    if(col-i > -1){
			if(boardState[col-i][row+j] == playerNum){
			    numInRow++;

			} else {
			    numInRow = 0;
			}
		    }
		    if(numInRow == K){
			x++;
			y--;
			return 1;
		    }
		}
			    
		x = col;
		y = row;

		numInRow++;
		for(int i = 1, j = 1; i < K; i++, j++){
		    x++;
		    y++;
		    if((col+i) < M && (row+j) < M){
			if(boardState[col+i][row+j] == playerNum){
			    numInRow++;
			} else {
			    numInRow = 0;
			}
		    }
		    if(numInRow == K){
			x++;
			y++;
			return 1;
		    }
		}
		x = col;
		y = row;
		for(int i = -1, j = 1; (i > -1) && (j < K-1); i--, j++){
		    y--;
		    x++;
		    if(boardState[col-i][row+j] == playerNum){
			numInRow++;

		    } else {
			numInRow = 0;
		    }
		    if(numInRow == K-1){
			x++;
			y--;
			return 1;
		    }
		}
	    }
	}
    }
    return 0;
}
void computerPlayer::input(Board &playerBoard){
    int col;
    int row;
    findMove(col, row, playerBoard.getM(), playerBoard.getK(), playerBoard.getBoard());
    playerBoard.playerInput(col, row, player);
}
 
 

