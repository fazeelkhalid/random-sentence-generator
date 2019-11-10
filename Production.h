#ifndef PRODUCTION_H
#define PRODUCTION_H

#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

// declare an enum that will hold the possible states
// of a production object

enum State {
    WAITING_FOR_START,       /* i.e.: wiating for '{'           */
    WAITING_FOR_NAME,        /* i.e.: waiting for <name>        */
    WAITING_FOR_POSSIBILITY, /* waiting for lines under <name>  */
    ENDED                    /* all lines under <name> and we   
                                reached the closing '}'         */
};


class Production {
private:
    // the current state from the enum above
    State state;
    // the <name> part of the grammar file right after the 
    //  opening curly brace '{'
    string name;

    // a list of all possibilities (lines under <name>)
    vector<string> possibilities;
    
public:
    // constructor
    Production();

    // accessor methods
    string getName();
    string getRandomPossibility();
    
    // methods that read the current state 
    // and modify it
    bool isWaitingToStart();
    void start();
    bool isWaitingForName();
    void setName(string name);
    bool isWaitingForPossibilities();
    void addPossibility(string text);
    bool isEnded();
    void end();
};

#endif // PRODUCTION_H