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
#include <stdlib.h>
#include <time.h>

computerPlayer::computerPlayer(int playerNum){
    player = playerNum;
    if(player == 1){
	opponant = 2;
    } else {
	opponant = 1;
    }
}


int computerPlayer::findMove(int &col, int &row, int M, int K, int **board){
    if(findPersonToBlock(col, row, M, ceil(K/2), board) == 1){
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
    int horx = 0, hory = 0;
    bool hor = false;
    int vertx = 0, verty = 0;
    bool vert = false;
    int diagleftx = 0, diaglefty = 0;
    bool diagleft = false;
    int diagrightx = 0, diagrighty = 0;
    bool diagright = false;

    if(findVertical(vertx, verty, M, K, boardState) == 1){
	vert = true;
	if(verty+1 < M){
	    if(boardState[vertx][verty+1] == opponant){
		x = horx;
		y = hory;
	
		return 1;
	    }
	}
    }
    if(findHorizontal(horx, hory, M, K, boardState) == 1){
	hor = true;
	if(horx+1 < M){
	    if(boardState[horx+1][hory] == opponant){
		x = horx;
		y = hory;
		return 1;
	    }
	}
    }
    if(findDiagonalLeft(diagleftx, diaglefty, M, K, boardState)  == 1){
	diagleft = true;
	if(diagleftx-1 > -1){
	    if(boardState[diagleftx-1][diaglefty+1] == opponant){
		x = diagleftx;
		y = diaglefty;
		return 1;
	    }
	}
    }
    if(findDiagonalRight(diagrightx, diagrighty, M, K, boardState) == 1){
	diagright = true;
	if(diagrightx+1 < M){
	    if(boardState[diagrightx+1][diagrighty+1] == opponant){
		x = diagrightx;
		y = diagrighty;
		return 1;
	    }
	}
    }

    int randNum;

    srand(time(NULL));

    if(vert && hor && diagleft && diagright){
	randNum = rand() % 3;
	if(randNum == 0){
	    x = vertx;
	    y = verty;
	} else if (randNum == 1){
	    x = horx;
	    y = hory;
	} else if (randNum == 2){
	    x = diagleftx;
	    y = diaglefty;
	} else {
	    x = diagrightx;
	    y = diagrighty;
	}
	return 1;
    }
    if(vert && hor && diagleft){
	randNum = rand() % 2;
	if(randNum == 0){
	    x = vertx;
	    y = verty;
	} else if(randNum == 1){
	    x = horx;
	    y = hory;
	} else {
	    x = diagleftx;
	    y = diaglefty;
	}
	return 1;
    }
    if(vert && hor && diagright){
	randNum = rand() % 2;
	if(randNum == 0){
	    x = vertx;
	    y = verty;
	} else if(randNum == 1){
	    x = horx;
	    y = hory;
	} else {
	    x = diagrightx;
	    y = diagrighty;
	}
	return 1;
    }
    if(hor && diagleft && diagright){
	randNum = rand() % 2;
	if(randNum == 0){
	    x = horx;
	    y = hory;
	} else if(randNum == 1){
	    x = diagleftx;
	    y = diaglefty;
	} else {
	    x = diagrightx;
	    y = diagrighty;
	}
	return 1;
    }
    if(vert && hor){
	randNum = rand() % 1;
	if(randNum == 0){
	    x = vertx;
	    y = verty;
	} else {
	    x = horx;
	    y = hory;
	}
	return 1;
    }
    if(vert && diagleft){
	randNum = rand() % 1;
	if(randNum == 0){
	    x = vertx;
	    y = verty;
	} else{
	    x = diagleftx;
	    y = diaglefty;
	}
	return 1;
    }
    if(vert && diagright){
	randNum = rand() % 1;
	if(randNum == 0){
	    x = vertx;
	    y = verty;
	} else {
	    x = diagrightx;
	    y = diagrighty;
	}
	return 1;
    }
    if(hor && diagleft){
	randNum = rand() % 1;
	if(randNum == 0){
	    x = horx;
	    y = hory;
	} else {
	    x = diagleftx;
	    y = diaglefty;
	}
	return 1;
    }
    if(hor && diagright){
	randNum = rand() % 1;
	if(randNum == 0){
	    x = horx;
	    y = hory;
	} else {
	    x = diagrightx;
	    y = diagrighty;
	}
	return 1;
    }
    if(diagleft && diagright){
	randNum = rand() % 1;
	if(randNum == 0){
	    x = diagleftx;
	    y = diaglefty;
	} else {
	    x = diagrightx;
	    y = diagrighty;
	}
	return 1;
    }
    if(vert){
	x = vertx;
	y = verty;
	return 1;
    }
    if(hor){
	x = horx;
	y = hory;
	return 1;
    }
    if(diagleft){
	x = diagleftx;
	y = diaglefty;
	return 1;
    }
    if(diagright){
	x = diagrightx;
	y = diagrighty;
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
		if(row+1 < M){
		if(boardState[col][row+1] == 0){
		    x = col;
		    y = row+1;
		    return 1;
		}
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
		if(col+1 < M){
		if(boardState[col+1][row] == 0){
		    x = col + 1;
		    y = row;
		    return 1;
		}
		}
	    }
	}
    }
    return 0;
}

int computerPlayer::findDiagonalLeft(int &x, int &y, int M, int K, int **boardState){
    int numInLine = 0;
    //check if game won diagonally
    //we need to do this in the fowards and back direction
    for(int row = 0; row < M; row++){

	for(int col = 0; col < M; col++){
	    for(int i = 0, j = 0; j < K; i++, j++){
		if(col-i > -1){
		    if(boardState[col-i][row+j] == opponant){
			numInLine++;
		    } else{
			numInLine = 0;
		    }
		    if(numInLine == K){
			if(col-i-1 > -1){
			    if(boardState[col-i-1][row+j+1] == 0){
				x = col - i - 1;
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

int computerPlayer::findDiagonalRight(int &x, int &y, int M, int K, int **boardState){
    int numInLine = 0;
    //check if game won diagonally
    //we need to do this in the fowards and back direction
    for(int row = 0; row < M; row++){

	for(int col = 0; col < M; col++){

	    for(int i = 0, j = 0; j < K; i++, j++){
		    
		   
		if(col+i < M){
		    if(boardState[col+i][row+j] == opponant){
			numInLine++;

		    } else {
			numInLine = 0;
		    }
		}
		if(numInLine == K){
		    if(col+i+1 < M){
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
    return 0;
}

void computerPlayer::input(Board &playerBoard){
    int col;
    int row;
    findMove(col, row, playerBoard.getM(), playerBoard.getK(), playerBoard.getBoard());
    playerBoard.playerInput(col, row, player);
}
 
 

