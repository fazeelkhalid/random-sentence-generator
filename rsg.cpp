
#include <fstream>
#include <iostream>

using namespace std;

//#include "RandomSentenceGenerator.h"


class RandomSentenceGenerator {
public:
    int x, y, z;
    RandomSentenceGenerator();
    void typeSomething();
};

RandomSentenceGenerator::RandomSentenceGenerator() {
    cout << "\n creating " << endl;
    this->x = 20;
    this->y = 30;
    this->z = 40;
};

 
void RandomSentenceGenerator::typeSomething() {
    cout << " \n what shall i type? \n ";
}



int main(int argc, char* argv[]) {
    // validate command line arguments
    if(argc==2) {
        // validate file availability
        
        ifstream file(argv[1]);
        cout << "Trying to open " << argv[1] << "..."  << endl;
        if(file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
            RandomSentenceGenerator gen;
            gen.typeSomething();
        } else {
            cout << "\nUnable to open input file." << endl;
        }

        

    } else {
        cout << "Usage: rsg <grammar_file>" << endl;
    }
    return 0;
}