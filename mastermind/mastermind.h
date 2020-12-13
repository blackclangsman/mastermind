#pragma once
#ifndef mastermind_h    
#define mastermind_h

class player {
public:
	int gamesize;
	std::vector<char> getinput();
};


class gamemanager {
public:
	//status in game
	int play1score = 0;
	int play2score = 0;
	int play1wins = 0;
	int play2wins = 0;
	bool codemaker; //is the code maker a cpu player or human?
	//game settings
	int turns;
	int games;
	//functions
	int setup();
	int getsettings();
	void endround(int turns, bool AI);
	void endgame();
};



#endif