#include "Production.h"
#include "util.h"

const int WAITING_FOR_START         = 0 ;
const int WAITING_FOR_NAME          = 1 ;
const int WAITING_FOR_POSSIBILITY   = 2 ;
const int ENDED                     = 3 ;


Production::Production() {
    this->state = WAITING_FOR_START;
}

void Production::addPossibility(string text) {
    this->possibilities.push_back(trim(text));
}


bool Production::isWaitingToStart() {  return this->state == WAITING_FOR_START; }
void Production::start() { if(this->state == WAITING_FOR_START) { this->state = WAITING_FOR_NAME; } }
bool Production::isWaitingForName() { return this->state == WAITING_FOR_NAME; }
void Production::setName(string name) { if(this->state == WAITING_FOR_NAME) { this->name = name; this->state = WAITING_FOR_POSSIBILITY; } }
bool Production::isWaitingForPossibilities() { return this->state == WAITING_FOR_POSSIBILITY; }
bool Production::isEnded() { return this->state == ENDED; }
void Production::end() { if(this->state == WAITING_FOR_POSSIBILITY) { this->state = ENDED; } }

bool Production::isProduction(string& text) {
    return contains(text, "<") && contains(text, ">") && !contains(text, ";");
    //return true;
}

bool Production::isPossibility(string& text) {
    return contains(text, ";") ;
}
bool Production::isOpening(string& text) {
    return contains(text, "{") ;
}
bool Production::isClosing(string& text) {
    return contains(text, "}") ;
}

ostream& operator << (ostream& str, Production& p) {
    str << "<" << p.name << ">" << endl;
    for(int i=0; i<p.possibilities.size(); i++) {
        str << "  [" << p.possibilities[i] << "]" << endl;
    }
    return str;
}