#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <regex>
#include <random>

using namespace std;

string ltrim(const string& s);
string rtrim(const string& s);
string trim(const string& s);
bool contains(const string hayStack, const string needle);
vector<string> split(const string& str, const char& ch) ;
int random(int max) ;
string cleanUp(string str);

#endif // UTIL_H