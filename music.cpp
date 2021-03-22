#include <iostream>
#include <cstring>
#include "media.h"
#include "music.h"
using namespace std;

music::music() {
}
int music::getType() {// type of media
	return 1;
}
int* music::getDuration() {//send duration
	return &duration;
}
char* music::getArtist() {//send artist
	return artist;
}
char* music::getPublisher() {//send publisher
	return publisher;
}


