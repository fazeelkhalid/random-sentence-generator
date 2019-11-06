
#include <fstream>
#include <iostream>
#include "RandomSentenceGenerator.h"
#include "util.h"


using namespace std;



int main(int argc, char* argv[]) {

    // validate command line arguments
    if(argc==2) {
        string start = "<start>";
            RandomSentenceGenerator gen = RandomSentenceGenerator(argv[1]);
            cout << gen.getSentence(start) << endl;
        
    } else {
        cout << "Usage: rsg <grammar_file>" << endl;
    }
    return 0;
}