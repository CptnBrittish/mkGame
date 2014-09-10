#include "board.h"
//i = col
//j = row

//We need to zero all the array as gcc wont do it for us easyiest to do it in the constructor
Board::Board(){
    M = 5;
    K = 3;
    boardState = new int*[M];
    for(int i = 0; i < M; i++){
	boardState[i] = new int[M];
    }
    for(int col = 0; col<M; col++){
	for(int row = 0; row<M; row++){
	    boardState[col][row] = 0;
	}
    }
}

Board::Board(int boardSize, int winningLength){
    M = boardSize;
    K = winningLength;
    boardState = new int*[M];
    for(int i = 0; i < M; i++){
	boardState[i] = new int[M];
    }
    for(int col = 0; col<M; col++){
	for(int row = 0; row<M; row++){
	    boardState[col][row] = 0;
	}
    }
}

void Board::printBoard(){
    //Add numbers to top of board
    std::cout << "  ";
    for (int col = 0; col<M; col++){
	std::cout << col+1 << "   ";
    }
    std::cout << std::endl;

    //Fill in rest of the board
    //Add a number to the end of the board then add a space
    for(int row = 0; row<M; row++){
	std::cout << row+1 << " ";

	for(int col = 0; col<M; col++){

	    if(boardState[col][row] == 0){
		std::cout << ' ';
	    } else if(boardState[col][row] == 1){
		std::cout << 'X';
	    } else if(boardState[col][row] == 2){
		std::cout << 'O';
	    } //no need to test for other values we should not be haviing errors in this array

            //if we arnt passed the end of the board add spacers for prettyfullness	    
	    if(col < (M-1)){
		std::cout << "---";
	    }
	}
	std::cout << std::endl << "  ";

	// If we are before the last line add "|" delimiters between the numbers
	if(row<(M-1)){
	    for(int col = 0; col < M; col++){
		std::cout << "|   ";
	    }
	}
	std::cout << std::endl;
    }
}

//Returns -1 if value is out of range
//Returns -2 if position already taken
//Returns 1 on succes
//We are assuming the inputs allign to our array not the users perception so we dont randomly break if we forget to decremnt the value
int Board::playerInput(int col, int row, int player){

    if((col > M-1) || (row > M-1)){
	return -1;
    }

    //We need to know if position is already taken if it is throw an error
    if(boardState[col][row] != 0){
	return -2;
    }
    //as player 1 is one and player 2 is -1 we can just check as player 1 auto evaluates to true and player 2 false
    //the player is entering positions from one not zero account for the offset    
    if(player == 1){
	boardState[col][row] = 1;
	
    } else {
	boardState[col][row] = 2;
    }

    return 1;
}

//return 1 if game won
//return 2 if a tie
//return -1 if not won (somewhere is a method to the madness which is my seemingly arbitrary return values)
int Board::checkIfGameWon(int playerNum){
    int numInRow = 0;

    //Check if a person has won the game vertically
    for(int col = 0; col < M; col++){
	for(int row = 0; row < M; row++){
	    if(boardState[col][row] == playerNum){
		numInRow++;
	    } else {
		numInRow = 0;
	    }
	    if(numInRow == K){
		return 1;
	    }
	}
    }
    numInRow = 0;
    	
    //check to see if a person has won the game horizontally
    for(int row = 0; row < M; row++){
	for(int col = 0; col < M; col++){
	    if(boardState[col][row] == playerNum){
		numInRow++;
	    } else {
		numInRow = 0;
	    }
	    if(numInRow == K){
		return 1;
	    }
	}
    }

    //check if game won diagonally
    //we need to do this in the fowards and back direction
    for(int row = 0; row < M; row++){
	for(int col = 0; col < M; col++){
	    //Only check this once as it applies to both directions
	    if(boardState[col][row] == playerNum){
		for(int i = 1, j = 1; j < K; i++, j++){
		    if(col-i > -1){
			if(boardState[col-i][row+j] == playerNum){
			    numInRow++;

			} else {
			    numInRow = 0;
			}
		    }
		    if(numInRow == K){
			return 1;
		    }
		}
			    

		numInRow++;
		for(int i = 1, j = 1; i < K; i++, j++){
		    if((col+i) < M && (row+j) < M){
			if(boardState[col+i][row+j] == playerNum){
			    numInRow++;
			} else {
			    numInRow = 0;
			}
		    }
		    if(numInRow == K){
			return 1;
		    }
		}
		for(int i = -1, j = 1; (i > -1) && (j < K); i--, j++){
		    if(boardState[col-i][row+j] == playerNum){
			numInRow++;
		    } else {
			numInRow = 0;
		    }
		    if(numInRow == K){
			return 1;
		    }
		}
	    }
	}
    }
    
    numInRow = 0;

    //Is the game a tie? 
    int numCounted = 0;
    int boardSize = M*M;
    for(int col = 0; col < M; col++){

	for(int row = 0; row < M; row++){
	    if(boardState[col][row] != 0){
		numCounted++;
	    }
	}
    }
    if(numCounted == boardSize){
	return 2;
    }
	 
    return -1; 
}
