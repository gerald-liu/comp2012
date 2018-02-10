#include "apple-pen.h"
#include <iostream>

Pen ApplePen::sing() {
    cout << "I have a " << pen.toString() << ", "
	 << "I have a " << apple.toString() << endl
	 << "Uh!" << endl;
    cout << pen.add(apple.toString()) << endl;
    return pen;
}

