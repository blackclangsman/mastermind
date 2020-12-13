#pragma once
#ifndef board_h    
#define board_h

class row {
public:
	std::vector<char> guessrow;
	std::vector<char> hintrow;

	/*void createRow(std::vector<char> &guess, std::vector<char> &hint) {
		guessrow = guess;
		hintrow = hint;
	}

	std::vector<char> getGuess() {
		return guessrow;
	}


	std::vector<char> getHint() {
		return hintrow;
	}*/
};


class board {
public:
	std::vector<row> boardrows;
	void addrow(std::vector<char>& guess, std::vector<char>& hint);
	void clearboard();
	void displayboard();

};


#endif