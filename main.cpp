/*Media management tool, can ADD movies, music, & videogames, SEARCH through them, DELETE them, & QUIT. 
 * Help from Max Cravetchi
 * Author: Pujan Patel
 * DATE: 3/20/21
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include "media.h"
#include "music.h"
#include "movie.h"
#include "game.h"
using namespace std;

void add(vector<media*>* storeMedia, int type);
void search(vector<media*>* storeMedia);
void deleteStuff(vector<media*>* storeMedia);

int main() {
    vector<media*> storeMedia; //vector that stores all the media
    bool running = true;
    
    while (running) {
        char action[80];
        char type[80];
        cout << "ADD, SEARCH, DELETE, or QUIT" << endl; 
        cin.get(action, 80);
        cin.ignore(100,'\n');
        if (strcmp(action, "ADD") == 0) {//add
            cout << "MUSIC, MOVIE, VIDEOGAME" << endl;
            cin >> type;
            if (strcmp(type, "MUSIC") == 0) {        
                add(&storeMedia, 1); 
            }
            else if (strcmp(type, "MOVIE") == 0) {
                add(&storeMedia, 2);
            }
            else if (strcmp(type, "VIDEOGAME") == 0) {
                add(&storeMedia, 3);
            }
        }
        else if (strcmp(action, "SEARCH") == 0) {
            search(&storeMedia); //search 
        }
        else if (strcmp(action, "DELETE") == 0) {
            deleteStuff(&storeMedia); //delete
        }
        else if (strcmp(action, "QUIT") == 0) {
            running = false;
        }
        else {
            cout << "PLEASE TYPE A VALID NUMBER" << endl;
        }
    }
    return 0;
}

void add(vector<media*>* storeMedia, int type) {
    if (type == 1) {
        music* createMusic = new music; //add music
        cout << "YEAR OF RELEASE?" << endl;
        cin >> *createMusic->getYear();
        cin.ignore(100, '\n');
        cout << "ARTIST?" << endl;
        cin.get(createMusic->getArtist(), 50);
        cin.ignore(100, '\n');
        cout << "TITLE?" << endl;
        cin.get(createMusic->getTitle(), 50);
        cin.ignore(100, '\n');
        cout << "PUBLISHSER?" << endl;
        cin.get(createMusic->getPublisher(), 50);
        cin.ignore(100, '\n');
        cout << "DURATION?" << endl;
        cin >> fixed >> setprecision(2) >> *createMusic->getDuration();
        cin.ignore(100, '\n');
        storeMedia->push_back(createMusic);
    }
    else if (type == 2) {
        movie* createMovie = new movie; //add movie
        cout << "YEAR OF RELEASE?" << endl;
        cin >> *createMovie->getYear();
        cin.ignore(100, '\n');
        cout << "DIRECTOR?" << endl;
        cin.get(createMovie->getDirector(), 50);
        cin.ignore(100, '\n');
        cout << "TITLE?" << endl;
        cin.get(createMovie->getTitle(), 50);
        cin.ignore(100, '\n');
        cout << "DURATION?" << endl;
        cin >> *createMovie->getDuration();
        cin.ignore(100, '\n');
        cout << "RATING?" << endl;
        cin >> fixed >> setprecision(2) >> *createMovie->getRating();
        cin.ignore(100, '\n');
        storeMedia->push_back(createMovie);
    }
    else if (type == 3) {
        cin.ignore(100, '\n');
        game* createGame = new game; //add videogame
        cout << "YEAR OF RELEASE?" << endl;
        cin >> *createGame->getYear();
        cin.ignore(100, '\n');
        cout << "TITLE?" << endl;
        cin.get(createGame->getTitle(), 50);
        cin.ignore(100, '\n');
        cout << "PUBLISHER?" << endl;
        cin.get(createGame->getPublisher(), 50);
        cin.ignore(100, '\n');
        cout << "RATING?" << endl;
        cin >> fixed >> setprecision(2) >> *createGame->getRating();
        cin.ignore(100, '\n');
        storeMedia->push_back(createGame);
    }
}
void search(vector<media*>* storeMedia) {
    char searchTitle[50]; 
    int searchYear; 
    char searchType[80]; 
    vector<media*>::iterator searchThru; //iterator
    cout << "search by TITLE or YEAR" << endl;
    cin >> searchType;
    cin.ignore(100, '\n');
    if (strcmp(searchType, "TITLE") == 0) {
        cout << "TITLE TO SEARCH?" << endl;
        cin.get(searchTitle, 50);
        cin.ignore(100, '\n');
        for (searchThru = storeMedia->begin(); searchThru != storeMedia->end(); searchThru++) {
            if (strcmp((*searchThru)->getTitle(), searchTitle) == 0) {
                if ((*searchThru)->getType() == 1) { //if music
                    cout << "MUSIC:" << endl;
                    cout << "YEAR RELEASED: " << *(*searchThru)->getYear() << endl;
                    cout << "ARTIST: " << dynamic_cast<music*>(*searchThru)->getArtist() << endl;
                    cout << "TITLE: " << (*searchThru)->getTitle() << endl;
                    cout << "PUBLISHED BY: " << dynamic_cast<music*>(*searchThru)->getPublisher() << endl;
                    cout << "DURATION: " << *dynamic_cast<music*>(*searchThru)->getDuration() << endl;
                }
                else if ((*searchThru)->getType() == 2) {//if movies
                    cout << "MOVIE:" << endl;
                    cout << "YEAR RELEASED: " << *(*searchThru)->getYear() << endl;
                    cout << "DIRECTED BY: " << dynamic_cast<movie*>(*searchThru)->getDirector() << endl;
                    cout << "TITLE: " << (*searchThru)->getTitle() << endl;
                    cout << "RATING: " << *dynamic_cast<movie*>(*searchThru)->getRating() << endl;
                    cout << "DURATION: " << *dynamic_cast<movie*>(*searchThru)->getDuration() << endl;
                }
                else if ((*searchThru)->getType() == 3) { //if games
                    cout << "VIDEO GAME:" << endl;
                    cout << "YEAR RELEASED: " << *(*searchThru)->getYear() << endl;
                    cout << "PUBLISHED BY: " << dynamic_cast<game*>(*searchThru)->getPublisher() << endl;
                    cout << "TITLE: " << (*searchThru)->getTitle() << endl;
                    cout << "RATING: " << *dynamic_cast<game*>(*searchThru)->getRating() << endl;
                }
            }
        }
    }
    else if (strcmp(searchType, "YEAR") == 0) {
        cout << "YEAR TO SEARCH?" << endl;
        cin >> searchYear;
        cin.ignore(100, '\n');

        for (searchThru = storeMedia->begin(); searchThru != storeMedia->end(); searchThru++) {
            if (*(*searchThru) ->getYear()==searchYear) {
                if ((*searchThru)->getType() == 1) {
                    cout << "MUSIC:" << endl;
                    cout << "YEAR RELEASED: " << *(*searchThru)->getYear() << endl;
                    cout << "ARTIST: " << dynamic_cast<music*>(*searchThru)->getArtist() << endl;
                    cout << "TITLE: " << *(*searchThru)->getTitle() << endl;
                    cout << "PUBLISHED BY: " << dynamic_cast<music*>(*searchThru)->getPublisher() << endl;
                    cout << "DURATION: " << *dynamic_cast<music*>(*searchThru)->getDuration() << endl;
                }
                else if ((*searchThru)->getType() == 2) {
                    cout << "MOVIE:" << endl;
                    cout << "YEAR RELEASED: " << *(*searchThru)->getYear() << endl;
                    cout << "DIRECTED BY: " << dynamic_cast<movie*>(*searchThru)->getDirector() << endl;
                    cout << "TITLE: " << *(*searchThru)->getTitle() << endl;
                    cout << "RATING: " << *dynamic_cast<movie*>(*searchThru)->getRating() << endl;
                    cout << "DURATION: " << *dynamic_cast<movie*>(*searchThru)->getDuration() << endl;
                }
                else if ((*searchThru)->getType() == 3) {
                    cout << "VIDEO GAME:" << endl;
                    cout << "YEAR RELEASED: " << *(*searchThru)->getYear() << endl;
                    cout << "PUBLISHED BY: " << dynamic_cast<game*>(*searchThru)->getPublisher() << endl;
                    cout << "TITLE: " << *(*searchThru)->getTitle() << endl;
                    cout << "RATING: " << *dynamic_cast<game*>(*searchThru)->getRating() << endl; 
                }
            }
        }
    }
}
void deleteStuff(vector<media*>* storeMedia) {//delete by year or title
    char deleteTitle[50];
    int deleteYear; 
    char deleteType[80]; 
    int yesorno;
    vector<media*>::iterator deleteskis;
    cout << "Delete by TITLE or YEAR" << endl;
    cin >> deleteType;
    cin.ignore(100, '\n');
    if (strcmp(deleteType, "TITLE") == 0) {//delete by title
        cout << "TITLE TO DELETE?" << endl;
        cin.get(deleteTitle, 50);
        cin.ignore(100, '\n');
        for (deleteskis = storeMedia->begin(); deleteskis != storeMedia->end(); deleteskis++) {
            if (strcmp((*deleteskis)->getTitle(), deleteTitle) == 0) {
                if ((*deleteskis)->getType() == 1) { //for music
                    cout << "MUSIC TITLE FOUND: " << (*deleteskis)->getTitle() << endl;
                    cout << "DELETE? 1 = YES, 2 = NO" << endl;
                    cin >> yesorno;
                    cin.ignore(100, '\n');
                    if (yesorno == 1) {
                        delete* deleteskis;
                        deleteskis = storeMedia->erase(deleteskis);
                        cout << "MUSIC DELETED" << endl;
                        yesorno = 0;
                        return;
                    }
                    else if (yesorno == 2) {
                        cout << "MUSIC WAS NOT DELETED." << endl;
                        yesorno = 0;
                    }
                }
                else if ((*deleteskis)->getType() == 2) {
                    //for movie
                    cout << "MOVIE TITLE FOUND: " << (*deleteskis)->getTitle() << endl;
                    cout << "DELETE? 1 = YES, 2 = NO" << endl;
                    cin >> yesorno;
                    cin.ignore(100, '\n');
                    if (yesorno == 1) {
                        delete* deleteskis;
                        deleteskis = storeMedia->erase(deleteskis);
                        cout << "MOVIE DELETED" << endl;
                        yesorno = 0;
                        return;
                    }
                    else if (yesorno == 2) {
                        cout << "MOVIE WAS NOT DELETED." << endl;
                        yesorno = 0;
                    }
                }
                else if ((*deleteskis)->getType() == 3) {
                    //for games
                    cout << "VIDEO GAME TITLE FOUND: " << (*deleteskis)->getTitle() << endl;
                    cout << "DELETE? 1 = YES, 2 = NO " << endl;
                    cin >> yesorno;
                    cin.ignore(100, '\n');
                    
                    if (yesorno == 1) {
                        delete* deleteskis;
                        deleteskis = storeMedia->erase(deleteskis);
                        cout << "VIDEO GAME DELETED" << endl;
                        yesorno = 0;
                        return;
                    }
                    else if (yesorno == 2) {
                        cout << "VIDEO GAME WAS NOT DELETED." << endl;
                        yesorno;
                    }
                }
            }
        }
    }
    else if (strcmp(deleteType, "YEAR") == 0) { //delete by year
        cout << "YEAR TO DELETE?" << endl;
        cin >> deleteYear;
        cin.ignore(100, '\n');
        for (deleteskis = storeMedia->begin(); deleteskis != storeMedia->end(); deleteskis++) {
            if (*(*deleteskis)->getYear() == deleteYear) {
                if ((*deleteskis)->getType() == 1) {
                    cout << "MUSIC YEAR(S) FOUND: " << *(*deleteskis)->getTitle() << endl;
                    cout << "DELETE? 1 = YES, 2 = NO" << endl;
                    cin >> yesorno;
                    cin.ignore(100, '\n');
                    if (yesorno == 1) {
                        delete* deleteskis;
                        deleteskis = storeMedia->erase(deleteskis);
                        cout << "MUSIC DELETED" << endl;
                        yesorno = 0;
                        return;
                    }
                    else if (yesorno == 2) {
                        cout << "MUSIC WAS NOT DELETED." << endl;
                        yesorno = 0;
                    }
                }
                else if ((*deleteskis)->getType() == 2) {
                    cout << "MOVIE YEAR(S) FOUND: " << *(*deleteskis)->getTitle() << endl;
                    cout << "DELETE? 1 = YES, 2 = NO" << endl;
                    cin >> yesorno;
                    cin.ignore(100, '\n');
                    if (yesorno == 1) {
                        delete* deleteskis;
                        deleteskis = storeMedia->erase(deleteskis);
                        cout << "MOVIE(S) DELETED" << endl;
                        yesorno = 0;
                        return;
                    }
                    else if (yesorno == 2) {
                        cout << "MOVIE(S) WAS NOT DELETED." << endl;
                        yesorno;
                    }
                }
                else if ((*deleteskis)->getType() == 3) {
                    cout << "VIDEO GAME YEAR(S) FOUND: " << *(*deleteskis)->getTitle() << endl;
                    cout << "DELETE? 1 = YES, 2 = NO" << endl;
                    cin >> yesorno;
                    cin.ignore(100, '\n');
                    if (yesorno == 1) {
                        delete* deleteskis;
                        deleteskis = storeMedia->erase(deleteskis);
                        return;
                        cout << "VIDEO GAME DELETED" << endl;
                        yesorno = 0;
                    }
                    else if (yesorno == 2) {
                        cout << "VIDEO GAME WAS NOT DELETED." << endl;
                        yesorno = 0;
                    }
                }
            }
        }
    }
}
