#ifndef prob2_h
#define prob2_h
#include <iostream>
char d;
void prompts() {
	std::cout << "Enter a sentence: ";
}

void getSentence() {
	std::cin.get(d);
}
void somefunction() {
	_asm {
		call prompts;
		call getSentence;
	phaseone:
		cmp d, '\n';
		Je done;
		cmp d, 'a';
		Je vowelA;
		cmp d, 'e';
		Je vowelE;
		cmp d, 'i';
		Je vowelI;
		cmp d, 'o';
		Je vowelO;
		cmp d, 'u';
		Je vowelU;
	vowelA:
		  



	done:
		
	}

}

#endif // !prob2_h
/*what we want to do:
		maybe we just use a bunch of if else statements and a lot of go to labels. Remember that to make a toupper function we have
		to subtract 32 from a lowercase to make an uppercase letter
		to change the lowecase letter to an uppercase letter, we have get the decimal value of the letter and then subtract 32.
	*/