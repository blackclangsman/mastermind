#pragma once
#ifndef codemaker_h    
#define codemaker_h

class codemaker {
public:
	std::vector<char> answer;
	//std::vector<char> guess;
	std::vector<char> hint;
	bool AI = false;
	std::vector<char> evaluate(std::vector<char> guess);
	void initialize(int diff);
};



#endif

