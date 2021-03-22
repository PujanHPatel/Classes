//header
#ifndef music_h
#define music_h

#include <iostream>
#include <cstring>
#include "media.h"
using namespace std;

class music : public media {
public:
	music();
	int* getDuration();
	char* getArtist();
	char* getPublisher();
	virtual int getType();
private:
	int duration;
	char artist[50];
	char publisher[50];
};

#endif
