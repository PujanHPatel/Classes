#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include "media.h"
using namespace std;

media::media() {
}
int* media::getYear() {
	return &year;
}
char* media::getTitle() {
	return title;
}
int media::getType() {
	return 0;
}
