#include "Production.h"

Production::Production() {
    this->state = WAITING_FOR_START;
}

void Production::addPossibility(string text) {
    this->possibilities.push_back(trim(text));
}
string Production::getName() {
    return this->name;
}

bool Production::isWaitingToStart()             { return this->state == WAITING_FOR_START; }
void Production::start()                        { if(this->state == WAITING_FOR_START) { this->state = WAITING_FOR_NAME; } }
bool Production::isWaitingForName()             { return this->state == WAITING_FOR_NAME; }
void Production::setName(string name)           { if(this->state == WAITING_FOR_NAME) { this->name = name; this->state = WAITING_FOR_POSSIBILITY; } }
bool Production::isWaitingForPossibilities()    { return this->state == WAITING_FOR_POSSIBILITY; }
bool Production::isEnded()                      { return this->state == ENDED; }
void Production::end()                          { if(this->state == WAITING_FOR_POSSIBILITY) { this->state = ENDED; } }


string Production::getRandom() {
    int r = random(possibilities.size()-1);
    return possibilities[r];
}

ostream& operator << (ostream& str, Production& p) {
    str << "<" << p.name << ">" << endl;
    for(int i=0; i<p.possibilities.size(); i++) {
        str << "  [" << p.possibilities[i] << "]" << endl;
    }
    return str;
}