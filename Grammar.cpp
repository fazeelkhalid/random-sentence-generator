#include "Grammar.h"


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
            if(currentProduction.isWaitingToStart() && Text::isOpening(line)) {
                //cout << "[start]" << endl;
                currentProduction.start();
            }

            if(currentProduction.isWaitingForName() && Text::isProduction(line)) {
                //cout << "[name] = " << line << endl;
                currentProduction.setName(line);
            }

            if(currentProduction.isWaitingForPossibilities() && Text::isPossibility(line)) {
                //cout << "[poss]" << line << endl;
                vector<string> arr = split(trim(line), ';');
                if(arr.size()>0) {
                    for(int i=0; i<arr.size(); i++) {
                        currentProduction.addPossibility(arr[i]);
                    }
                }
                
            }

            if(currentProduction.isWaitingForPossibilities() && Text::isClosing(line)) {
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

string Grammar::resolve(string text) {
    if(text.length()==0) {
        return "";
    }
    if(!Text::containsProduction(text)) {
        return trim(text);
    } else {
        int s = text.find("<");
        int e = text.find(">");
        string firstPart = trim(text.substr(0, s));
        string toResolve = text.substr(s, e - s + 1);
        
        string resolved = " Could not resolve " + toResolve;

        for(int i=0; i<productions.size(); i++) {
            if(productions[i].getName() == toResolve) {
                resolved = trim(productions[i].getRandomPossibility());
                break;
            }
        }
        string lastPart = trim(text.substr(e+1));

        return cleanUp( firstPart + " " +  Grammar::resolve(resolved)  + Grammar::resolve(lastPart));

    }
}

ostream& operator<<(ostream& stream, Grammar& grm) {
    for(int i=0; i<grm.productions.size(); i++) {
        stream << grm.productions[i];
    }
    return stream;
}


