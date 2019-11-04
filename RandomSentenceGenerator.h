#ifndef RSG_H
#define RSG_H

#include <iostream>
#include "Grammar.h"

using namespace std;


class RandomSentenceGenerator {
private:
    Grammar grammar;
public:
    
    RandomSentenceGenerator(string filename);
    friend ostream& operator<<(ostream& stream, RandomSentenceGenerator& rsg);
};

ostream& operator<<(ostream& stream, RandomSentenceGenerator& rsg);

#endif //RSG_H