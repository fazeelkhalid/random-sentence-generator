#ifndef RSG_H
#define RSG_H

#include <iostream>
#include "Grammar.h"
#include "Text.h"

using namespace std;


class RandomSentenceGenerator {
private:
    Grammar grammar;
public:
    
    RandomSentenceGenerator(string filename);
    string getRandomPossibility();
    friend ostream& operator<<(ostream& stream, RandomSentenceGenerator& rsg);
};

ostream& operator<<(ostream& stream, RandomSentenceGenerator& rsg);

#endif //RSG_H