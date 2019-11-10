#include "Production.h"

// the default constructor
Production::Production() {
    // always start with a state that is waiting for curly brace
    this->state = WAITING_FOR_START;
}

// accept a string as a possibility and add it to the list
void Production::addPossibility(string text) {
    this->possibilities.push_back(util::trim(text));
}

// accessor method for name property
string Production::getName() {
    return this->name;
}


string Production::getRandomPossibility() {
    // get a random index between 0 and the current number of possibilities
    // random() is defined in util.cpp
    int randomIndex = util::random(possibilities.size()-1);

    // return the possibility at that random index
    return possibilities[randomIndex];
}


// definitions of methods that read and modify the state
bool Production::isWaitingToStart() { 
    return this->state == WAITING_FOR_START; 
}
void Production::start() { 
    // only change the state after validating the previous state
    if(this->state == WAITING_FOR_START) { 
        this->state = WAITING_FOR_NAME; 
    } 
}

bool Production::isWaitingForName() { 
    return this->state == WAITING_FOR_NAME; 
}

void Production::setName(string name) { 
    // validate previoud state before chaning
    if(this->state == WAITING_FOR_NAME) { 
        this->name = name; this->state = WAITING_FOR_POSSIBILITY; 
    } 
}

bool Production::isWaitingForPossibilities() { 
    return this->state == WAITING_FOR_POSSIBILITY; 
}

bool Production::isEnded() { 
    return this->state == ENDED; 
}

void Production::end() { 
    // always validate previoud state
    if(this->state == WAITING_FOR_POSSIBILITY) { 
        this->state = ENDED; 
    } 
}
