#include "pen.h"
#include <iostream>
string Pen::add(string a) {
    if (a.length() > 0)
        words = a + "-" + words;
    return words;
}


//reverse Pineapple-Pen to Pen-Pineapple
string Pen::reverse() {
    size_t dashpos = words.find('-');
    if (dashpos == string::npos) //no dash to reverse
	return words; 
    size_t seconddash = words.find('-', dashpos + 1);
    if (seconddash != string::npos) //there are more than one dash
	return words;
    string front = words.substr(0, dashpos);
    string back = words.substr(dashpos + 1, words.length());
    words = back + "-" + front;
    return words;
}

string Pen::toString() const {
    return words;
}

Pen::Pen() {
    words = "Pen";
}	
