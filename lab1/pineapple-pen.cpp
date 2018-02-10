#include "pineapple-pen.h"
#include <iostream>

Pen PineapplePen::sing() {
    cout << "I have a " << pen.toString() << ", "
	 << "I have a " << pineapple.toString() << endl
	 << "Uh!" << endl;
    cout << pen.add(pineapple.toString()) << endl;
    return pen;
}

