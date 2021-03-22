#include <iostream>
#include <cstring>
#include "game.h"
#include "media.h"
using namespace std;

game::game() {
}
int game::getType() {//type of media
	return 3;
}
char* game::getPublisher() {//send publisher
	return publisher;
}
float* game::getRating() {//send rating
	return &rating;
}
