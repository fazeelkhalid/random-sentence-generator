#include <fstream>
#include <iostream>
#include "Grammar.h"
#include "util.h"


using namespace std;

Grammar::Grammar(string filename) {
    ifstream file(filename);
    cout << "Trying to open " << filename << "..."  << endl;
    if(file.is_open()) {
        string line;
        Production currentProduction;
        
        //cout << currentProduction << "<-- check this" << endl;

        while (getline(file, line)) {
            //cout << line << endl;
            if(currentProduction.isWaitingToStart() && Production::isOpening(line)) {
                //cout << "[start]" << endl;
                currentProduction.start();
            }

            if(currentProduction.isWaitingForName() && Production::isProduction(line)) {
                //cout << "[name] = " << line << endl;
                currentProduction.setName(line);
            }

            if(currentProduction.isWaitingForPossibilities() && Production::isPossibility(line)) {
                //cout << "[poss]" << line << endl;
                vector<string> arr = explode(line, ';');
                if(arr.size()>0) {
                    for(int i=0; i<arr.size(); i++) {
                        currentProduction.addPossibility(arr[i]);
                    }
                }
                
            }

            if(currentProduction.isWaitingForPossibilities() && Production::isClosing(line)) {
                //cout << "[end]" << endl;
                currentProduction.end();
                productions.push_back(currentProduction);
                currentProduction = Production();

            }
            
        }
        file.close();
        //cout << "=== finished =====" << endl;

    } else {
        cout << "\nUnable to open input file." << endl;
    }
}
Grammar::~Grammar() {
    for(int i=this->productions.size() -1; i>=0; i--) {
        productions.erase(productions.begin() + i);
    }
    
}


ostream& operator<<(ostream& stream, Grammar& grm) {
    for(int i=0; i<grm.productions.size(); i++) {
        stream << grm.productions[i];
    }
    return stream;
}


