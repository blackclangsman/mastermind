// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include "board.h"


void board::addrow(std::vector<char>& guess, std::vector<char>& hint) {
	row newrow;
	newrow.guessrow = guess;
	newrow.hintrow = hint;
	this->boardrows.push_back(newrow);
}

void board::clearboard() {
	this->boardrows.clear();
}

void board::displayboard() {
	std::vector<row> boar = this->boardrows;
	//std::cout << '\n';
	int num;
	for (int i = 0; i < boar.size(); i++) {
		num = i + 1;
		std::cout << "\n Plays on turn " + std::to_string(num) + " " << std::endl;
		for (int j = 0; j < boar[i].guessrow.size(); j++) {
			std::cout << boar[i].guessrow[j];
		}
		std::cout << "    ";
		for (int j = 0; j < boar[i].hintrow.size(); j++) {
			std::cout << boar[i].hintrow[j];
		}
		std::cout << "\n";
	}
}


