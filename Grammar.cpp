#include "Grammar.h"

using namespace std;

Grammar::Grammar(string filename) {
    // let the user know what is going on
    cout << "Trying to open " << filename << "..."  << endl;

    // declare an InputFileStream object named 'file'
    ifstream file(filename);

    // check if the file could not be opened
    if(!file.is_open()) {
        // for some reason, the file could not be open,
        // either due to none existing file, or the file
        // could be locked by another process,

        throw 0;    // throw an exception that will be
                    // caught in main() to exit the program
    } else {
        // declare a placeholder for each line we read from the file
        string line;

        // declare a placeholder Production object that will be built
        // from each block of curly brackets in the grammar file
        Production currentProduction;
        
        // keep reading until we reach the end of file
        while (getline(file, line)) {
            // check if the line we just read, is an the beginning of a production block "i.e: {"
            // and at the same time, our placeholder Porudction object should be waiting to be started
            // isWaitingToStart is defined in Production.cpp
            // isOpening() is defined in util.cpp
            if(currentProduction.isWaitingToStart() && util::isOpening(line)) {
                // modify the state of currentProduction so that it can 
                // start to expect a block name
                currentProduction.start();
            }

            // check if current production object is expecting a block name, 
            // and at the same time, the line we just read happens to be
            // a block name
            // isWaitingForName() is defined in Production.cpp
            // isName() is defined in util.cpp
            if(currentProduction.isWaitingForName() && util::isName(line)) {
                // in this case, lets set the name of the block in the currentProduction object
                currentProduction.setName(line);
            }

            // check if current Production object is expecting possibilities,
            // and at the same time, the line we just read is a possibility
            // isWaitingForPossibilities() is defined in Production.cpp
            // isPossibility() is defined in util.cpp
            if(currentProduction.isWaitingForPossibilities() && util::isPossibility(line)) {
                // we need to make sure that the line is split using the character ;
                // since the grammar file can have multiple possibilities in a single line
                // as a rule, each possibility is separated by a semi-colon

                // declare an array of strings that will be the result of 
                // spliting the line using the specinfied the delimiter
                // Note: this will work for multiple possibilities in a single line,
                //       as well as a single possibility in a single line.

                // split() is defined in util.cpp
                vector<string> arr = util::split(util::trim(line), ';');

                // loop through each possibility in the line
                // and add it separately in the currentProduction object
                for(int i=0; i<arr.size(); i++) {
                    // addPossibility() is defined in Proudction.cpp
                    currentProduction.addPossibility(arr[i]);
                }
            }
            // since we can't tell if a Production is waiting to be ended, unless it is
            // currently expecting a possibility and we encounter a closing curly brace "}", 
            // so we check for both of these conditions

            // isClosing() is defined in util.cpp
            if(currentProduction.isWaitingForPossibilities() && util::isClosing(line)) {
                // modify the state of currentProduction object
                currentProduction.end();

                // add the entire object (with its name, and possibilities) 
                // into our object property array of productions
                productions.push_back(currentProduction);

                // clear currentProduction so that it can start over
                // since there might be other blocks of productions in the file
                currentProduction = Production();
                // PS: calling the constructor, will ensure we get a new object
                //      with its own state set to isWaitingToStart

            }
            
        }
        // we reached the end of the file,
        // close it.
        file.close();
    }
}

// The grammar destructor
Grammar::~Grammar() {
    // loop through each object in our array of productions and erase them
    for(int i=this->productions.size() -1; i>=0; i--) {
        productions.erase(productions.begin() + i);
    }
    
}

// the recursive function resolve
string Grammar::resolve(string text) {
    // make sure we have a valid string
    if(text.length()==0) {
        // no recursion..
        return "";
    }

    // check if the current text contains NO sub-productions
    if(!util::containsProduction(text)) {
        // it does not. So we trim it and return it as is.
        return util::trim(text);

    } else {
        // it contains a sub-production.

        // find the location of the first opening angle bracket
        int s = text.find("<");
        // find the location of the first closing angle bracket
        int e = text.find(">");

        // everything before the opening angle bracket needs no further resolving
        // we will call it firstPart
        string firstPart = util::trim(text.substr(0, s));

        // the part between s and e is a production that requires resolving
        // we will call it toResolve
        string toResolve = text.substr(s, e - s + 1);
        
        // declare a string that contains the default message
        // could not resolve <production name here>
        // just in case the provided grammar file doesn't contain
        // possibilities for the requested text to be resolved
        string resolved = " [Could not resolve " + toResolve + "]";

        // loop through grammar's list of productions and find one
        // with a matching name
        for(int i=0; i<productions.size(); i++) {
            if(productions[i].getName() == toResolve) {
                // FOUND!!, 
                // get any random possibility from that production's list
                // of possibilities.  
                resolved = util::trim(productions[i].getRandomPossibility());
                
                // exit for loop. No need to continue searching
                break;
            }
        }
        // at this point, resolved will either be filled with a random possibility, 
        // or it will contain the default [Could not resolved <>] message if it is not found

        // the part of the text after the closing angle bracket, we will call it
        // lastPart. It might contain a production, because we did not check it yet.
        string lastPart = util::trim(text.substr(e+1));

        // to wrap up:
        //      firstPart --> contains no sub-productions. return it as it.
        //      resolved  --> contains the resolved production. But it might also contain a sub-sub-prudction
        //                    so, we call the recursive function on it
        //      lastPart  --> contains the rest of the text, but it, too might contain a sub-production,
        //                    so, we will call the recursive function for it, too

        // cleanUp() will remove un-necessary white space.
        // it is defined in util.cpp
        return util::cleanUp( firstPart 
                        + " " 
                        +  Grammar::resolve(resolved)  
                        + Grammar::resolve(lastPart));

    }
}