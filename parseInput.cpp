#include "parseInput.h"

#include <cstdlib>
#include <string>

using namespace std;

int parseInput(string &input){
    if(validateIsANumber(input) == -1){
	return -1;
    }
    int number = atoi(input.c_str());
    return number;
}

int validateIsANumber(string &input){
    char num[10] = {'0','1','2','3','4','5','6','7','8','9'};
    bool isNumber = false;

    for(int i = input.length(); i > 0; i--){
	isNumber = false;
	for(int j = 9; j >= 0; j--){
	    if(input.at(i-1) == num[j]){
		isNumber = true;
	    }
	}
	if(isNumber == false){
	    return -1;
	}
    }
    return 1;
}
