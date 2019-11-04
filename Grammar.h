#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <iostream>
#include <vector>
#include "Production.h"

using namespace std;

class Grammar {
private:
    int size;
    vector<Production> productions;
    
public:
    ~Grammar();
    Grammar(string);
    Production getStart();
    friend ostream& operator<<(ostream& stream, Grammar& grm);
};

ostream& operator<<(ostream& stream, Grammar& grm);

#endif //GRAMMAR_H