#include "RandomSentenceGenerator.h"


RandomSentenceGenerator::RandomSentenceGenerator(string filename) : grammar(filename) {}

string RandomSentenceGenerator::getSentence(string& production) {
    return grammar.resolve(production);
    
}

ostream& operator<<(ostream& stream, RandomSentenceGenerator& rsg) {
    stream << rsg.grammar;
    return stream;
}