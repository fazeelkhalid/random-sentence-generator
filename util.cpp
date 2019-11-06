#include "util.h"


string ltrim(const string& s) {
	return regex_replace(s, regex("^[\\s;]+"), string(""));
}

string rtrim(const string& s) {
	return regex_replace(s, regex("[\\s;]+$"), string(""));
}

string trim(const string& s) {
	return ltrim(rtrim(s));
}

bool contains(const string hayStack, const string needle) {
    int result = hayStack.find(needle);
    return (result != string::npos);        
}


vector<string> split(const string& str, const char& ch) {
    string next;
    vector<string> result;

    // For each character in the string
    for (string::const_iterator it = str.begin(); it != str.end(); it++) {
        // If we've hit the terminal character
        if (*it == ch) {
            // If we have some characters accumulated
            if (!next.empty()) {
                // Add them to the result vector
                result.push_back(next);
                next.clear();
            }
        } else {
            // Accumulate the next character into the sequence
            next += *it;
        }
    }
    if (!next.empty())
         result.push_back(next);
    return result;
}

int random(int max) {
    random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator
    uniform_int_distribution<> distr(0, max); // define the range

    //return (int)distr(eng);
    return distr(eng);
}
