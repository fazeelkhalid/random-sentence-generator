#include "RandomSentenceGenerator.h"

RandomSentenceGenerator::RandomSentenceGenerator(string filename) : grammar(filename) {}


ostream& operator<<(ostream& stream, RandomSentenceGenerator& rsg) {
    stream << rsg.grammar;
    return stream;
}