/*
 * testmain.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#include "NumberCard.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {

/**
 * Sample Output

R5
R7
G7
R7 play after R5? true
G7 play after R7? true
G7 play after R5? false

 */


        NumberCard r5(5, Color::red);
        NumberCard r7(7, Color::red);
        NumberCard g7(7, Color::green);

        cout << r5 << endl;
        cout << r7 << endl;
        cout << g7 << endl;

        cout << "R7 play after R5? " << boolalpha << (r5 ^ r7) << endl;
        cout << "G7 play after R7? " << boolalpha << (r7 ^ g7) << endl;
        cout << "G7 play after R5? " << boolalpha << (r5 ^ g7) << endl;

        stringstream s;
        s << r5;
        string result = s.str();
        if (result != "R5")
            cout << "Failed" << endl;

}
