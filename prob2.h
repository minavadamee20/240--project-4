#pragma once
#ifndef prob2_h
#define prob2_h
#include <iostream>
char c;

void prompt() {
	std::cout << "Enter a sentence: ";
}
void getSentence() {
	std::cin.get(c);
}

_asm {
	call prompt;
	call getSentence;
}

#endif // !prob2_h


/*
what we want to do: 
		for every vowel that is found within the sentence, we want to make that vowel a upperase letter. following some logic from the last problem, we should be compare each character from the sentence
		and call the appropiate labels. I feel the base case scenario would to be to do a switch case scenario to handle the multiple vowels instead of doing multiple if/else/if else statements. I think 
		in lecture or the past assignments we dealt with a switch case scenario, either that or im confusing 223 switch case scenario. 
*/