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

#include <cmath>
#include <iostream>

computerPlayer::computerPlayer(int playerNum){
    player = playerNum;
    if(player == 1){
	opponant = 2;
    } else {
	opponant = 1;
    }
}


int computerPlayer::findMove(int &col, int &row, int M, int K, int **board){
    if(findPersonToBlock(col, row, M, floor(K/2), board) == 1){
	return 1;
    } else {
	for(int i = 0; i < M; i++){
	    for(int j = 0; j < M; j++){
		if(board[i][j] == 0){
		    col = i;
		    row = j;
		    std::cout <<"find next value: " << col << " " << row << std::endl;
		    //return from function now otherwise we go to the end of the board
		    return 1;
		}
	    }
	}
    }

    return 1;

}

int computerPlayer::findPersonToBlock(int &x, int &y, int M, int K, int **boardState){
    if(findVertical(x, y, M, K, boardState) == 1){
	std::cout <<" Vertical: " << x << " " << y << std::endl;	
return 1;
    }
    if(findHorizontal(x, y, M, K, boardState) == 1){
	std::cout << "horizontal" << x << " " << y << std::endl;	
return 1;
    }
    if(findDiagonal(x, y, M, K, boardState) == 1){
	std::cout << "diagonal" << x << " " << y << std::endl;
	return 1;
    }
    return 0;
}

int computerPlayer::findVertical(int &x, int &y, int M, int K, int **boardState){
    int numInLine = 0;
    //Check if a person has won the game vertically
    for(int col = 0; col < M; col++){
	for(int row = 0; row < M; row++){
	    if(boardState[col][row] == opponant){
		numInLine++;
	    } else {
		numInLine = 0;
	    }
	    if(numInLine == K){
		if(boardState[col][row+1] == 0){
		x = col;
		y = row+1;
		return 1;
		}
	    }
	}
    }
    return 0;

}

int computerPlayer::findHorizontal(int &x, int &y, int M, int K, int **boardState){
    int numInLine = 0;
    //check to see if a person has won the game horizontally
    for(int row = 0; row < M; row++){
	y = row;
	for(int col = 0; col < M; col++){
	    x = col;
	    if(boardState[col][row] == opponant){
		numInLine++;
	    } else {
		numInLine = 0;
	    }
	    if(numInLine == K){
		if(boardState[col+1][row] == 0){
		x = col + 1;
		y = row;
		return 1;
		}
	    }
	}
    }
}

int computerPlayer::findDiagonal(int &x, int &y, int M, int K, int **boardState){
    int numInLine = 0;
    //check if game won diagonally
    //we need to do this in the fowards and back direction
    for(int row = 0; row < M; row++){

	for(int col = 0; col < M; col++){
	    //Only check this once as it applies to both directions
	    if(boardState[col][row] == opponant){
		for(int i = 1, j = 1; j < K; i++, j++){
		    
		   
		    if(col-i > -1){
			if(boardState[col-i][row+j] == opponant){
			    numInLine++;

			} else {
			    numInLine = 0;
			}
		    }
		    if(numInLine == K){
			if(boardState[col-i-1][row+j+1] == 0){
			x = col - i - 1;
			y = row + j + 1;
			return 1;
			}
		    }
		}
		for(int i = 1, j = 1; j < K; i++, j++){
		    if(col+i < M){
			if(boardState[col+i][row+j] == opponant){
			    numInLine++;
			} else{
			    numInLine = 0;
			}
			if(numInLine == K){
			    if(boardState[col+i+1][row+j+1] == 0){
			    x = col + i + 1;
			    y = row + j + 1;
			    return 1;
				}
			}
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
 
 

