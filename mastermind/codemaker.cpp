// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include "codemaker.h"

std::vector<char> codemaker::evaluate(std::vector<char> guess) {
	//guess = { 'A','B','D','F' };
	//answer = { 'A','D','B','E' };
	std::vector<char> hint; //hints are X = correct, / = correct color, O = incorrect
	/*for (int i = 0; i < guess.size(); i++) {
		hint.push_back('O');
	}*/
	//ai player for mastermind
	for (int i = 0; i < guess.size(); i++) {
		//first check for exact matches
		if (guess[i] == this->answer[i]) {
			//hint[i] = 'X'; //X indicates true
			hint.push_back('X');
			continue;
		}
		//second check how many colors are correct 
		if (std::find(this->answer.begin(), this->answer.end(), guess[i]) != this->answer.end()) {
			//hint[i] = '/';
			hint.push_back('/');
			continue;
		}
		hint.push_back('O');

	}
	/*
	std::cout << hint[0];
	std::cout << hint[1];
	std::cout << hint[2];
	std::cout << hint[3];*/


	if (guess == this->answer) {
		std::cout << "guess was correct"; 
		return {'a'};
	}
	
	return hint;
}


void codemaker::initialize(int diff) {
	//for AI initialization
	int num;
	std::vector<char> code;
	//std::cout << "made";
	for (int i = 0; i < diff; i++) {
		num = rand() % 6;
		std::cout << num;
		if (num == 0) {
			code.push_back('A');
		}
		else if (num == 1) {
			code.push_back('B');
		}
		else if (num == 2) {
			code.push_back('C');
		}
		else if (num == 3) {
			code.push_back('D');
		}
		else if (num == 4) {
			code.push_back('E');
		}
		else {
			code.push_back('F');
		}
	}
	this->answer = code;
	std::cout << "code is: ";
	for (int i = 0; i < this->answer.size(); i++) {
		std::cout << this->answer[i];
	}
	
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
