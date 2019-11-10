#include "util.h"

namespace util {
        
    // left-trim a string by removing leading white spaces
    string ltrim(const string& s) {
        return regex_replace(s, regex("^[\\s;]+"), string(""));
    }

    // right-trim a string by removing trailing white spaces
    string rtrim(const string& s) {
        return regex_replace(s, regex("[\\s;]+$"), string(""));
    }

    // cleanUp replaces and occurence of 2 (or more) consecutive white spaces with 1 space
    string cleanUp(string str) {
        return regex_replace(str, regex("[\\s]{2,}"), string(" "));
    }

    // trim will call left-trim and right-trim consecutively
    string trim(const string& s) {
        return ltrim(rtrim(s));
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



    // checks if a string contains a <name>
    bool isName(string& text) {
        // a name is different from a production by the absence of a semi-colon
        return contains(text, "<") && contains(text, ">") && !contains(text, ";");
        //return true;
    }

    // check if a string contains a possibility
    // we can't just check the end of the string for semi-colon
    // since some lines contain more than one possibility
    bool isPossibility(string& text) {
        return contains(text, ";") ;
    }

    // check if the text is an opening brace
    bool isOpening(string& text) {
        return contains(text, "{") ;
    }

    // check if the text is a closing brace
    bool isClosing(string& text) {
        return contains(text, "}") ;
    }


    // check if text contains a production <tag>
    bool containsProduction(string& text) {
        
        return contains(text, "<") && contains(text,">");

    }

    // check if a string contains a sub-string
    bool contains(const string hayStack, const string needle) {
        int result = hayStack.find(needle);
        return (result != string::npos);        
    }
}