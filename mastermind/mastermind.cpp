// mastermind.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "codemaker.h"
#include "codebreaker.h"
#include "board.h"
#include "mastermind.h"




std::vector<char> player::getinput() {
	std::string mystr;
	std::vector<char> input;
	//std::cout << "\n made";
	//parse input code
	std::cin.clear();
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Input your code in the format XXXX, using the letters A, B, C, D, E or F \n";
	try {
		getline(std::cin, mystr);
		if (mystr.size() != this->gamesize) {
			throw mystr;
		}
		//check colors, can pick between A,B,C,D,E
		for (int i = 0; i < this->gamesize; i++) {
			if (mystr[i] == 'A') {
				input.push_back(mystr[i]);
				continue;
			}
			else if (mystr[i] == 'B') {
				input.push_back(mystr[i]);
				continue;
			}
			else if (mystr[i] == 'C') {
				input.push_back(mystr[i]);
				continue;
			}
			else if (mystr[i] == 'D') {
				input.push_back(mystr[i]);
				continue;
			}
			else if (mystr[i] == 'E') {
				input.push_back(mystr[i]);
				continue;
			}
			else if (mystr[i] == 'F') {
				input.push_back(mystr[i]);
				continue;
			}
			else {
				throw mystr;
			}
		}
		//std::cout << input[0];
		return input;
		
	}
	catch (std::string mystr) {
		// Block of code to handle errors
		std::cout << mystr + " is not a valid input. \n";
		std::vector<char> dummy = { 'z' };
		return dummy;
	}
}



int gamemanager::setup() {
	//add exception handling
	std::cout << "specify difficulty";
	int difficulty = this->getsettings();
	std::cout << "specify turn amount";
	turns = this->getsettings();
	std::cout << "specify game amount";
	games = this->getsettings();
	return difficulty;
}


int gamemanager::getsettings() {
	int num;
	bool valid = false;
	do {
		std::cin >> num;

		if (!(valid = std::cin.good())) {
			std::cout << "That input is invalid!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

	} while (!valid);
	return num;
}





void gamemanager::endround(int turns, bool AI) {
	//scoring of the game, only the codemaker earns points
	if (AI == false) {
		//player is the codemaker
		this->play1score += turns;
	}
	else {
		//AI is the codemaker
		this->play2score += turns;
	}

	std::cout << "Score is: \n Player 1: " + std::to_string(this->play1score) + "\n Player 2: " + std::to_string(this->play2score);


	/*
		//setup new game, determine which is the AI and so forth
		if (cob.AI == false) {
			cob.AI = true;
			com.AI = false;
		}
		else {
			cob.AI = false;
			com.AI = true;
		}*/
}



void gamemanager::endgame() {

}









int main()
{
	player playcont;
	gamemanager gaman;
	board bord;
	playcont.gamesize = gaman.setup();
	std::cout << playcont.gamesize;
	

	//initialize code maker and code breaker
	codemaker com;
	com.AI = true;
	codebreaker cob;
	com.initialize(playcont.gamesize);
	std::cout << "\n";
	/*std::vector<char> inputtest = playcont.getinput();
	std::vector<char> guess = { 'A','B','D','F' };
	std::vector<char> hint = com.evaluate(guess);
	bord.addrow(guess, hint);
	bord.displayboard();*/
	//amount of games to be played




	std::vector<char> playerinput;
	for (int i = 0; i < gaman.games; i++) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//setup the game, set the code
		if (com.AI == false) {
			//prompt a move from the player
			playerinput = playcont.getinput();
			if (playerinput[0] == 'z') {
				i--;
				std::wcout << "please enter a valid code";
				continue;
			}
			com.answer = playerinput;
		}
		else {
			//AI sets the code
			com.initialize(playcont.gamesize);
		}

		//amount of turns in a game
		int turns;
		for (int j = 0; j < gaman.turns; j++) {

			if (cob.AI == false) {
				//prompt a move from the player
				playerinput = playcont.getinput();
				if (playerinput[0] == 'z') {
					j--;
					std::wcout << "please enter a valid code";
					continue;
				}
				std::vector<char> hint = com.evaluate(playerinput);
				if (hint[0] == 'a') {
					//code broken
					turns = j + 1;
					std::cout << "Code broken in " + std::to_string(turns) + " turns";
					bord.addrow(playerinput, playerinput);
					bord.displayboard();
					break;
				}
				bord.addrow(playerinput, hint);
				bord.displayboard();
				std::cout << "\n X = correct, / = correct letter in wrong spot, O = wrong \n";
			}
			else {
				//AI makes the moves
			}
			//end turn do scoring
			
		}
		//end game, new round
		gaman.endround(turns, com.AI);
		bord.clearboard();
	}
	//end game
	gaman.endgame();
		

	//while loop that keeps the game going goes here


    std::cout << "Hello World!\n";
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
