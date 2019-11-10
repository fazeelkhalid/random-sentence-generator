
#include <fstream>
#include <iostream>
#include "RandomSentenceGenerator.h"

using namespace std;

int main(int argc, char* argv[]) {

    // validate command line arguments
    if(argc!=2) {
        // the user did not provide a valid command syntax.
        // so we display a message to indicate proper usage
        cout << "Usage: rsg <grammar_file>" << endl;
    
    } else {
        // since opening a file can fail, we try to open first
        try {
            // instantiate a RandomSentenceGenerator object
            RandomSentenceGenerator rsg = RandomSentenceGenerator(argv[1]);
            
            // we indicate what we need to resolve. 
            string start = "<start>";

            // obtain a sentence from the starting production above.
            // this function is defined in RandomSentenceGenerator.cpp
            string sentence = rsg.getSentence(start);

            // display it to the user
            cout << sentence << endl;
        } catch(int error) {
            // there must have been an error accessing the provided file
            // display a friendly message
            cout << "Could not open " << argv[1] << endl;
        }
    }
    return 0;
}