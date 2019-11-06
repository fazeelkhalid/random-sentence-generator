#include "Text.h"



bool Text::isProduction(string& text) {
    return contains(text, "<") && contains(text, ">") && !contains(text, ";");
    //return true;
}

bool Text::isPossibility(string& text) {
    return contains(text, ";") ;
}
bool Text::isOpening(string& text) {
    return contains(text, "{") ;
}
bool Text::isClosing(string& text) {
    return contains(text, "}") ;
}


bool Text::containsProduction(string& text) {
    
    return contains(text, "<") && contains(text,">");

}