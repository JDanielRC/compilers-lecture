#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/***
Example:
Grammar:
E --> T | T + E
T --> int | int * T | ( E )
***/

char symbol;
bool E();
bool T();

bool charComparation(char t) {
	//printf("comparing char received %c with char l = %c \n", t, l);
    if (symbol == t) {
        symbol = getchar();
		return true;
    }
    else
		return false;
}

bool isInteger(){
	if(isdigit(symbol)){
		symbol = getchar();
		while (isInteger());
		return true;
	}else{
		return false;
	}
}

bool T(){
	if (isInteger()){
		if (charComparation('*')){
			if (T()){
				return true;
			}
			return false;
		}
		return true;
	} else if (charComparation('(')){
		if (E()){
			if (charComparation(')')){
				return true;
			}
			return false;
		}
		return false;
	}
	return false;
}

bool E(){
	if (T()){
		if (charComparation('+')){
			if (E()){
				return true;
			}
			return false;
		}
		return true;
	} else{
		return false;
	}
}

int main(int argc, char** argv) {
	symbol = getchar();
	bool wasSuccesful;
    do {
	    wasSuccesful = E();
    } while (symbol != '\n' && symbol != EOF && wasSuccesful);
	
	if (wasSuccesful){
		printf("Parsing was finished successfully\n");
	} else{
		printf("Error, cannot parse\n");
	}
        
}