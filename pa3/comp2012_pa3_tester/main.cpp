//do NOT submit this file
//while you may modify the main function to design your own test cases to test your program
//you should make sure your submitted code (i.e. those submitted files) can be compiled with this main.cpp in its unmodified state

#include <iostream>
#include <sstream>
using namespace std;

#include "bst.h"
#include "smartArray.h"
#include "hashingVault.h"
#include "insertionOperators.h"

int PairCounter::counter = 0;
int BSTNodeCounter::counter = 0;
int ContainerCounter::counter = 0;
int HashingVaultCounter::counter = 0;

int main()
{   
    {
    cout << "==========" << "Test case 1" << "==========" << endl;
    BST<int, string>* bst = new BST<int, string>;
    cout << "add result: " << boolalpha << bst->add(2, "b") << endl;
    cout << "add result: " << boolalpha << bst->add(1, "a") << endl;
    cout << "add result: " << boolalpha << bst->add(3, "c") << endl;
    cout << "add result: " << boolalpha << bst->add(44, "d") << endl;
    cout << "add result: " << boolalpha << bst->add(55, "e") << endl;
    cout << "add result: " << boolalpha << bst->add(66, "f") << endl;
    cout << "add result: " << boolalpha << bst->add(33, "gg") << endl;
    cout << "add result: " << boolalpha << bst->add(45, "ee") << endl;
    cout << "add result: " << boolalpha << bst->add(35, "gu") << endl;
    cout << "add result: " << boolalpha << bst->add(32, "gd") << endl;
    cout << "add result: " << boolalpha << bst->add(-1, "k") << endl;
    cout << "add result: " << boolalpha << bst->add(-11, "kk") << endl;
    cout << "add result: " << boolalpha << bst->add(-11, "kkk") << endl;
    cout << "add result: " << boolalpha << bst->add(2, "ggg") << endl;
    bst->printTree();
    cout << endl;
    ostringstream sout;
    //note: ostringstream can be used like a "cout", but the output does not go to the console/screen
    //the output goes to a undlying string, which can be retrieved with the "str()" member function of it
    //ostringstream is used here to verify/compare your operator<< output with the model answer
    sout << *bst; //this invokes operator<< ( sout, (*bst) )
    string studentAnswer = sout.str();
    string modelAnswer = "(-11,kk)(-1,k)(1,a)(2,b)(3,c)(32,gd)(33,gg)(35,gu)(44,d)(45,ee)(55,e)(66,f)";
    if( studentAnswer != modelAnswer )
    {
        cout << "incorrect print!" << endl;
        cout << "[" << modelAnswer << "]\nvs\n[" << studentAnswer << "]" << endl;
    }
    else
    {
        cout << "correct print!" << endl;
        cout << "[" << sout.str() << "]" << endl;
    }
    cout << endl << "bst[0] = (" << (*bst)[0]->key << "," << (*bst)[0]->value << ")" << endl;
    cout << endl << "bst[3] = (" << (*bst)[3]->key << "," << (*bst)[3]->value << ")" << endl;

    cout << endl << endl << "==========" << "Test case 2" << "==========" << endl;
    cout << "remove result: " << boolalpha << bst->remove(-11) << endl;
    bst->printTree();
    cout << "remove result: " << boolalpha << bst->remove(44) << endl;
    bst->printTree();
    cout << "remove result: " << boolalpha << bst->remove(55) << endl;
    bst->printTree();
    cout << "remove result: " << boolalpha << bst->remove(-999) << endl;
    bst->printTree();
    cout << "remove result: " << boolalpha << bst->remove(2) << endl;
    bst->printTree();
    cout << "bst->findMin()->printTree(): " << endl;
    bst->findMin()->printTree(); //in this case, the printTree is printing a tree that has only one node

    cout << endl << endl << "==========" << "Test case 3" << "==========" << endl;
    cout << "getValue result: " << bst->get(1) << endl;
    cout << "getValue result: " << bst->get(2) << endl;
    cout << "getValue result: " << bst->get(3) << endl;
    cout << "getValue result: " << bst->get(999) << endl;

    cout << endl << endl << "==========" << "Test case 4" << "==========" << endl;
    cout << "bst->height(): " << bst->height() << endl;
    cout << "bst->count(): " << bst->count() << endl;
    cout << "bst->isEmpty(): " << boolalpha << bst->isEmpty() << endl;

    delete bst;

    cout << endl << endl << "==========" << "Test case 5" << "==========" << endl;
    SmartArray<string, string>* sa = new SmartArray<string, string>;
    cout << endl << "add result: " << boolalpha << sa->add("animal", "dog") << endl;
    cout << "[" << *sa << "]" << endl;
    cout << endl << "add result: " << boolalpha << sa->add("animal", "cat") << endl;
    cout << "[" << *sa << "]" << endl;
    cout << endl << "add result: " << boolalpha << sa->add("food", "sushi") << endl;
    cout << "[" << *sa << "]" << endl;
    cout << endl << "add result: " << boolalpha << sa->add("car","honda") << endl;
    cout << "[" << *sa << "]" << endl;
    cout << endl << "remove result: " << boolalpha << sa->remove("food") << endl;
    cout << "[" << *sa << "]" << endl;

    ostringstream sout2;
    sout2 << *sa; //this invokes operator<< ( sout2, (*sa) )
    string studentAnswer2 = sout2.str();
    string modelAnswer2 = "(animal,dog)(car,honda)";
    if( studentAnswer2 != modelAnswer2 )
    {
        cout << "incorrect print!" << endl;
        cout << "[" << modelAnswer2 << "]\nvs\n[" << studentAnswer2 << "]" << endl;
    }
    else
    {
        cout << "correct print!" << endl;
        cout << "[" << sout2.str() << "]" << endl;
    }

    cout << endl << "sa->has(\"car\"): " << boolalpha << sa->has("car") << endl;
    cout << endl << "sa[0] = (" << (*sa)[0]->key << "," << (*sa)[0]->value << ")" << endl;
    cout << endl << "sa[1] = (" << (*sa)[1]->key << "," << (*sa)[1]->value << ")" << endl;

    delete sa;

    cout << endl << endl << "==========" << "Test case 6" << "==========" << endl;
    BST<int, int>* bst2 = new BST<int, int>;
    bst2->add(2, 22);
    bst2->add(3, 33);
    bst2->add(1, 11);
    bst2->printTree();
    BST<int, int>* bst3 = new BST<int, int>(*bst2);
    cout << "remove result: " << boolalpha << bst2->remove(2) << endl;
    cout << "getValue result: " << bst2->get(1) << endl;
    cout << "getValue result: " << bst2->get(2) << endl;
    cout << "getValue result: " << bst2->get(3) << endl;
    cout << "bst2:" << endl;
    bst2->printTree();
    cout << "bst3:" << endl;
    bst3->printTree();

    delete bst2;
    delete bst3;

    cout << endl << endl << "==========" << "Test case 7" << "==========" << endl;
    int tableSize = 5;
    Container<int, string>** bstTable = new Container<int, string>*[tableSize]; //it is created in the main, but should be deleted in HashingVault's destructor
    for(int i=0; i<tableSize; i++) bstTable[i] = new BST<int, string>;
    int (*fun)(int) = [](int n){return n % 5;}; //note: A lambda can only be converted to a function pointer if it does not capture
    HashingVault<int, string>* bstHV = new HashingVault<int, string>(tableSize, bstTable, fun);
    cout << endl << "add result: " << boolalpha << bstHV->add(2, "b") << endl;
    cout << *bstHV;
    cout << endl << "add result: " << boolalpha << bstHV->add(0, "z") << endl;
	cout << *bstHV;
	cout << endl << "add result: " << boolalpha << bstHV->add(17, "bb") << endl;
	cout << *bstHV;
	cout << endl << "add result: " << boolalpha << bstHV->add(22, "bbb") << endl;
	cout << *bstHV;
	cout << endl << "add result: " << boolalpha << bstHV->add(12, "bbbb") << endl;
	cout << *bstHV;
	cout << endl << "add result: " << boolalpha << bstHV->add(12, "cccc") << endl;
	cout << *bstHV;

    cout << endl << endl << "==========" << "Test case 8" << "==========" << endl;
    int tableSize2 = 4;
    int (*fun2)(int) = [](int n){return (n*3) % 4;};
    Container<int, string>** bstTable2 = new Container<int, string>*[tableSize2];
    for(int i=0; i<tableSize2; i++) bstTable2[i] = new BST<int, string>;
    bstHV->rehash(tableSize2, bstTable2, fun2);
    cout << *bstHV;

    delete bstHV;

    cout << endl << endl << "==========" << "Test case 9" << "==========" << endl;
    int tableSize3 = 3;
    Container<int, int>** saTable = new Container<int, int>*[tableSize3];
    for(int i=0; i<tableSize3; i++) saTable[i] = new SmartArray<int, int>;
    int (*fun3)(int) = [](int n){return (n*n) % 3;};
    HashingVault<int, int>* saHV = new HashingVault<int, int>(tableSize3, saTable, fun3);
	cout << endl << "add result: " << boolalpha << saHV->add(6, 66) << endl;
	cout << *saHV;
    cout << endl << "add result: " << boolalpha << saHV->add(1, 11) << endl;
    cout << *saHV;
    cout << endl << "add result: " << boolalpha << saHV->add(2, 22) << endl;
	cout << *saHV;
	cout << endl << "add result: " << boolalpha << saHV->add(3, 33) << endl;
	cout << *saHV;
	cout << endl << "add result: " << boolalpha << saHV->add(4, 44) << endl;
	cout << *saHV;
	cout << endl << "add result: " << boolalpha << saHV->add(5, 55) << endl;
	cout << *saHV;

    cout << endl << endl << "==========" << "Test case 10" << "==========" << endl;
    int tableSize4 = 2;
    int (*fun4)(int) = [](int n){return (n/3) % 2;};
    Container<int, int>** saTable2 = new Container<int, int>*[tableSize4];
    for(int i=0; i<tableSize4; i++) saTable2[i] = new SmartArray<int, int>;
    saHV->rehash(tableSize4, saTable2, fun4);
    cout << *saHV;

    delete saHV;
    }

    cout << "\n\nEnd of main.\n\n";
    if (PairCounter::counter || BSTNodeCounter::counter || ContainerCounter::counter || HashingVaultCounter::counter) {
    	cout << "There is MEMORY LEAK!\nHeap Profiling:\n";
    	cout << "Number of Pairs: " << PairCounter::counter << endl;
    	cout << "Number of BSTNodes: " << BSTNodeCounter::counter << endl;
    	cout << "Number of Containers: " << ContainerCounter::counter << endl;
    	cout << "Number of HashingVaults: " << HashingVaultCounter::counter << endl;
    }
    else cout << "No memory leak, good to go.\n";

    return 0;
}
