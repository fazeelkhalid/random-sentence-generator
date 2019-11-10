#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <regex>
#include <random>

using namespace std;
namespace util {
    string ltrim(const string& s);
    string rtrim(const string& s);
    string trim(const string& s);
    vector<string> split(const string& str, const char& ch) ;
    int random(int max) ;
    string cleanUp(string str);

    bool containsProduction(string& text);
    bool isName(string& text);
    bool isPossibility(string& text);
    bool isOpening(string& text);
    bool isClosing(string& text);

    bool contains(const string hayStack, const string needle);
}


#endif // UTIL_H