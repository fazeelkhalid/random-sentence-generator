#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <iostream>

#include <fstream>
#include <vector>
#include "Production.h"
#include "util.h"
#include "Text.h"


using namespace std;


class Grammar {
private:
    int size;
    vector<Production> productions;
    
public:
    ~Grammar();
    Grammar(string);
    string resolve(string text);
    friend ostream& operator<<(ostream& stream, Grammar& grm);
};

ostream& operator<<(ostream& stream, Grammar& grm);

#endif //GRAMMAR_H