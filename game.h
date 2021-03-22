//header
#ifndef game_h
#define game_h

#include <iostream>
#include <cstring>
#include "media.h"
using namespace std;

class game : public media {
public:
	game();
	virtual int getType(); 
	char* getPublisher(); 
	float* getRating(); 
private:
	char publisher[100]; 
	float rating; 
};

#endif
