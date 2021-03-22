//header
#ifndef media_h
#define media_h

#include <iostream>
#include <cstring>
using namespace std;

class media {
public:
	media();
	int* getYear();
	char* getTitle();
	virtual int getType();
private:
	int year;
	char title[50];

};

#endif
