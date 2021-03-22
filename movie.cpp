#include <iostream>
#include <cstring>
#include "media.h"
#include "movie.h"
using namespace std;

movie::movie() {
}

int movie::getType() {//type of media
	return 2;
}

char* movie::getDirector() {//send director
	return director;
}

int* movie::getDuration() {//send duration
	return &duration;
}

float* movie::getRating() {//send rating
	return &rating;
}
