#include <iostream>

#include "folder.h"

using namespace std;

int main()
{
	File a("a");
	File b("b");
	File c("c");
	File d("d");

	cout << "Folder f1" << endl;

	Folder f1;
	f1.addFile(a);
	f1.addFile(b);
	f1.addFile(d);
	f1.addFile(a);

	f1.print();

	cout << boolalpha << 
	"f1 contains a? " << f1.contains(a) << endl <<
	"f1 contains b? " << f1.contains(b) << endl << 
	"f1 contains c? " << f1.contains(c) << endl <<
	"f1 contains d? " << f1.contains(d) << endl;

	cout << endl;

	cout << "Folder f2" << endl;
	Folder f2 = Folder(f1);

	f2.print();

	cout << endl;

	cout << "Folder f3" << endl;
	Folder f3 = Folder(1);
	f3.addFile(a);
	f3.addFile(b);
	f3.addFile(c);

	f3.print();

	return 0;
}