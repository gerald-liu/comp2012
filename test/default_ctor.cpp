#include <iostream>
#include <cstring>
using namespace std;

class Word {
private:
	int frequency; char* str;
	void set(int f, const char* s) { frequency = f; str = new char [strlen(s)+1]; strcpy(str, s); }
public:
	Word() { set(0, "d"); cout << "default constructor\n"; }
	~Word() { delete[] str; cout << "destructor\n"; }
	void print() const { cout << str << " : " << frequency << " ; " 
		<< reinterpret_cast<void*>(str) << endl; } // Also prints the address of object’s str array
};

int main() {
	//Word;			// Compilation Error: declaration does not declare anything
	Word();			// initialization with default constructor, POOR GUY
	Word w;			// initialization with default constructor

	Word w0();		// function declaration with name "w0" and return type Word
	Word w1{};		// initialization with default constructor

    //w0.print();	// Compilation Error: request for member 'print' in 'w0', which is of non-class type 'Word ()'
	w1.print();
	
	Word Word();	// function declaration with name "Word" and return type Word; may have other errors
    //Word.print();	// Compilation Error: request for member 'print' in 'Word', which is of non-class type 'Word ()'
}