#pragma once
#ifndef codebreaker_h    
#define codebreaker_h

class codebreaker {
public:
	int guesses = 0;
	bool AI = false;
	void AIplayer();
	void humanplayer();
};



#endif