#ifndef RSG_H
#define RSG_H

#include <iostream>
#include "Grammar.h"

using namespace std;


class RandomSentenceGenerator {
private:
    // declare a private property Grammar object
    // that will handle generation of sentences
    Grammar grammar;
public:
    // declare the only constructor that expects a string as filename
    RandomSentenceGenerator(string filename);
    
    // the one method that can be called upon this object to 
    // return a string (sentance) to main function
    string getSentence(string& production);
};

#endif //RSG_H