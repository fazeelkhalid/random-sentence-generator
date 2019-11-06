#ifndef TEXT_H
#define TEXT_H
#include <iostream>
#include "util.h"

using namespace std;

class Text {

public:
    static bool containsProduction(string& text);
    static bool isProduction(string& text);
    static bool isPossibility(string& text);
    static bool isOpening(string& text);
    static bool isClosing(string& text);
};

#endif // TEXT_H