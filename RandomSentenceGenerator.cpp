#include "RandomSentenceGenerator.h"


RandomSentenceGenerator::RandomSentenceGenerator(string filename) : grammar(filename) {}

string RandomSentenceGenerator::getRandomPossibility() {
    Production start = grammar.getStart();
    string rnd = start.getRandom();
    if(Text::containsProduction(rnd)) {
        cout << "requires cleaning" << endl;
    } else {
        cout << "good to go" << endl;
    }
    return rnd;
}

ostream& operator<<(ostream& stream, RandomSentenceGenerator& rsg) {
    stream << rsg.grammar;
    return stream;
}