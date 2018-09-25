#pragma once
#ifndef prob1_h
#define prob1_h
#include <iostream>
short Nocounter, Yescounter, testing, counter = 0;
char c;

void prompt() { std::cout << "Type in your sentence: "; }
void getsentence() {
	std::cin.get(c);
}

void YesDisplay() {
	std::cout << "there are Yes " << Yescounter << " in the above line: ";
}
void NoDisplay() {
	std::cout << std::endl << "there are No " << Nocounter << " in the above line: ";
}
void YesStarDisplay() {
	std::cout << "*";
}
void NoStarDisplay() {
	std::cout << "*";
}


void assemblyprob1() {
	_asm {
		call prompt;
		call getsentence;
	whileLoop:
		cmp c, '\n';
		Je Yesdone;
		cmp c, 'y';
		Je YesreadAgain;
		cmp c, 'n';
		Je NoreadAgain;
	NoreadAgain:
		inc Nocounter;
		call getsentence;
		Jmp whileLoop;
	YesreadAgain:
		inc Yescounter;
		call getsentence;
		Jmp whileLoop;
	Yesdone:
		call YesDisplay;
		mov bx, Yescounter;
	yesDisplayLabel:
		cmp counter, bx;
		Jge NoDone;
		call YesStarDisplay;
		inc counter;
		Jmp yesDisplayLabel;
	NoDone:
		call NoDisplay;
		mov bx, Nocounter;
		mov counter, 0;
		
	NoDisplayLabel:
		cmp counter, bx;
		Jge FinalDone;
		call NoStarDisplay;
		inc counter;
		Jmp NoDisplayLabel;
	FinalDone:
		mov testing, dx;
	}
	std::cout << std::endl << testing;
	
	
}
#endif // !prob1_h

/*
currently working through the problem and why this works rather than using Jne for all of the above.....
	while in the whileLoop function:
			| we compare the variable character type c to a end line. If this is equal to a end line character, then we jump to Done.         |
			| if not, we continue through the rest... this leads us to compare the variable character type c to a empty space character.      |
			| if c is equal to a empty space character then we call readAgain and not increasing the counter. if c is not equal to a empty    |
			| space character,we countinue down the assembly language thus incrementing the counter and go to the readAgain label which has   |
			| us call getsentence and jump back to whileLoop again to repeat the process again until we reach a end line character.           |
*/


/*
so to make sure that we have the assembly language to work correctly the way the professor wants, we want to call some sort of label that
will take care of displaying the stars for 
		ex: YesStarDisplay: //stuff here [...] 
and the same thing with NoStarDisplay. A possible idea is that the  YesStarDisplay will simply display a single star, since the assembly 
language code we created holds the amount of stars that will be needed to display, we keep calling that function that displays the single
star several times until it reaches the amount of stars needed to display


[ CURRENT PROBLEMS ]
		correctly reading the amount of 'y' and 'n' within the sentence but we have a possible infinite loop when comparing and displaying
		the stars wtihin each line. bad values for YesCounter and NoCounter but when displayed within the function it's right...something
		going wrong within the member variables; YesCounter and NoCounter after function is called --->[SOLVED]<---

		the number of stars is correctly showing except for yes, the number of times it is called is only once before moving onto the no
		display of stars, possibly something wrong with incrementing? The register [ax] is not correctly equaling the value of yesCounter.
		so what's going on that's not allowing the register to correctly equal the value of yesCounter? --->[SOLVED]<---



*/