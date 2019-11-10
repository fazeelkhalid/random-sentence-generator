#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <iostream>

#include <fstream>
#include <vector>
#include "Production.h"
#include "util.h"



using namespace std;


class Grammar {
private:
    // declare a private list of Production objects
    vector<Production> productions;
    
public:
    // the only constructor, expecting a file name to read
    Grammar(string);
    // destructor for freeing up memory allocated for the list
    ~Grammar();
    
    // the recursive function that will build the sentence
    string resolve(string text);
    
};


#endif //GRAMMAR_H