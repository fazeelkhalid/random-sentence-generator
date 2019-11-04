#ifndef PRODUCTION_H
#define PRODUCTION_H
#include <iostream>
#include <vector>

using namespace std;
class Production {
private:
    int state;
    string name;
    vector<string> possibilities;
    
public:
    Production();
    //Production(int n, string text);
    
    bool isWaitingToStart();
    void start();
    bool isWaitingForName();
    void setName(string name);
    bool isWaitingForPossibilities();
    void addPossibility(string text);
    bool isEnded();
    void end();

    static bool isProduction(string& text);
    static bool isPossibility(string& text);
    static bool isOpening(string& text);
    static bool isClosing(string& text);

    friend ostream& operator<<(ostream& str, Production& l);
};

ostream& operator<<(ostream& str, Production& l);

#endif // PRODUCTION_H