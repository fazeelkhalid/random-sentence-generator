
#include <fstream>
#include <iostream>

using namespace std;

//#include "RandomSentenceGenerator.h"



class Grammar {
public:
    //Grammar();
    Grammar(string);
    void typer();
};
// Grammar::Grammar() {
//     cout << "\nEmpty Grammar not allowed" << endl;
// }
Grammar::Grammar(string filename) {
    ifstream file(filename);
    cout << "Trying to open " << filename << "..."  << endl;
    if(file.is_open()) {
        string line;
        while (getline(file, line)) {
            //cout << line << endl;
        }
        file.close();
    } else {
        cout << "\nUnable to open input file." << endl;
    }
};

void Grammar::typer() {
    cout << "\nG is typing" << endl;
};

class RandomSentenceGenerator {
private:
    Grammar grammar;
public:
    
    RandomSentenceGenerator(string);
    void typeSomething();
};

RandomSentenceGenerator::RandomSentenceGenerator(string filename) : grammar(filename) {
    cout << "\n creating " << endl;
    grammar = Grammar(filename);
};


void RandomSentenceGenerator::typeSomething() {
    grammar.typer();
    
};



int main(int argc, char* argv[]) {
    // validate command line arguments
    if(argc==2) {
        // validate file availability
            RandomSentenceGenerator gen = RandomSentenceGenerator(argv[1]);
            gen.typeSomething();
        
    } else {
        cout << "Usage: rsg <grammar_file>" << endl;
    }
    return 0;
}