
#include "apple-pen.h"
#include "pineapple-pen.h"
#include <iostream>

using namespace std;

int main() {
    ApplePen *ap = new ApplePen;
    Pen applePen = ap->sing();
    cout << endl;

    PineapplePen *pp = new PineapplePen;
    Pen pineapplePen = pp->sing();
    cout << endl;
    
    cout << applePen.toString() << ", " << pineapplePen.toString() << endl
	 << "Uh" << endl;

    //reverse the pineapplePen
    pineapplePen.reverse();

    applePen.add(pineapplePen.toString());
    cout << applePen.toString() << endl;
    cout << applePen.toString() << endl;

    delete ap;
    delete pp;
}
