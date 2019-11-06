#ifndef PRODUCTION_H
#define PRODUCTION_H
#include <iostream>
#include <vector>
#include "util.h"

using namespace std;


enum State {
    WAITING_FOR_START,
    WAITING_FOR_NAME,
    WAITING_FOR_POSSIBILITY,
    ENDED
};


class Production {
private:
    State state;
    string name;
    vector<string> possibilities;
    
public:
    Production();
    string getName();
    string getRandomPossibility();
    
    bool isWaitingToStart();
    void start();
    bool isWaitingForName();
    void setName(string name);
    bool isWaitingForPossibilities();
    void addPossibility(string text);
    bool isEnded();
    void end();

   

    friend ostream& operator<<(ostream& str, Production& l);
};

ostream& operator<<(ostream& str, Production& l);

#endif // PRODUCTION_H