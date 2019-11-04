#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <regex>

using namespace std;

inline string ltrim(const string& s) {
	return regex_replace(s, regex("^[\\s;]+"), string(""));
}

inline string rtrim(const string& s) {
	return regex_replace(s, regex("[\\s;]+$"), string(""));
}

inline string trim(const string& s) {
	return ltrim(rtrim(s));
}

inline bool contains(const string& hayStack, const string& needle) {
     return (hayStack.find(needle) != string::npos);        
}


inline vector<string> explode(const string& str, const char& ch) {
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

#endif // UTIL_H