#include "board.h"
//i = col
//j = row

//We need to zero all the array as gcc wont do it for us easyiest to do it in the constructor
Board::Board(){
    for(int col = 0; col<M; col++){
	for(int row = 0; row<K; row++){
	    Board::boardState[col][row] = 0;
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
    for(int row = 0; row<K; row++){
	std::cout << row+1 << " ";

	for(int col = 0; col<M; col++){

	    if(Board::boardState[col][row] == 0){
		std::cout << ' ';
	    } else if(Board::boardState[col][row] == 1){
		std::cout << 'X';
	    } else if(Board::boardState[col][row] == 2){
		std::cout << 'O';
	    } //no need to test for other values we should not be haviing errors in this array

            //if we arnt passed the end of the board add spacers for prettyfullness	    
	    if(col < (M-1)){
		std::cout << "---";
	    }
	}
	std::cout << std::endl << "  ";

	// If we are before the last line add "|" delimiters between the numbers
	if(row<(K-1)){
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
    if(col > M || row > K){
	return -1;
    }

    //We need to know if position is already taken if it is throw an error
    if((Board::boardState[col][row] == 1) || (Board::boardState[col][row] == 2)){
	return -2;
    }
    //as player 1 is one and player 2 is -1 we can just check as player 1 auto evaluates to true and player 2 false
    //the player is entering positions from one not zero account for the offset    
    if(player == 1){
	Board::boardState[col][row] = 1;
	
    } else {
	Board::boardState[col][row] = 2;
    }

    return 1;
}

//return 1 if game won
//return 2 if a tie
//return -1 if not won (somewhere is a method to the madness which is my seemingly arbitrary return values)
int Board::checkIfGameWon(){
    int numInRow = 0;

    //Check if a person has won the game vertically
    for(int col = 0; col < M; col++){
	for(int row = 0; row < K; row++){
	    if(boardState[col][row] == 1){
		numInRow++;
	    } else {
		numInRow = 0;
	    }
	    if(numInRow == 3){
		return 1;
	    }
	}
    }
    numInRow = 0;
    for(int col = 0; col < M; col++){
	for(int row = 0; row < K; row++){
	    if(boardState[col][row] == 2){
		numInRow++;
	    } else {
		numInRow = 0;
	    }
	    if(numInRow == 3){
		return 1;
	    }
	}
    }
    numInRow = 0;
	
    //check to see if a person has won the game horizontally
    for(int row = 0; row < K; row++){
	for(int col = 0; col < M; col++){
	    if(boardState[col][row] == 1){
		numInRow++;
	    } else {
		numInRow = 0;
	    }
	    if(numInRow == 3){
		return 1;
	    }
	}
    }

    
    numInRow = 0;

    for(int row = 0; row < K; row++){
	for(int col = 0; col < M; col++){
	    if(boardState[col][row] == 2){
		numInRow++;
	    } else {
		numInRow = 0;
	    }
	    if(numInRow == 3){
		return 1;
	    }
	}
    }
    numInRow = 0;	      

    //Is the game a tie? 
    //Yes we are doing anougher for loop mess yes its inefficant if i have time ill work out how to clean this up
    int numCounted = 0;
    int boardSize = M*K;
    for(int col = 0; col < M; col++){

	for(int row = 0; row < K; row++){
	    if((boardState[col][row] == 1) || (boardState[col][row] == 2)){
		numCounted++;
	    }
	}
    }
    if(numCounted == boardSize){
	return 2;
    }
	 
    return -1;
}
