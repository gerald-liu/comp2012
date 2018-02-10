#ifndef __PEN_H
#define __PEN_H

#include <string>
using namespace std;

class Pen {
public:
    string add(string); //or known as "Uh"
    string reverse(); // reverse Pineapple-Pen to Pen-Pineapple
    string toString() const;		
    Pen();
private:
    string words;
};


#endif
