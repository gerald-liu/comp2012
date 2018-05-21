#include <iostream>
#include <cstring>

using namespace std;

class Word {
private:
	int freq; char* str;
	void setstr(const char* s) { str = new char[strlen(s)+1]; strcpy(str,s); }
public:
	// The following str{nullptr} is necessary. Why?
	Word(const Word& w): str{nullptr}
		{ cout << "Copy: "; *this = w; }
	Word(const char* s, int k = 1) : freq(k) { cout << "Conversion: from \"" << s << "\"\n"; setstr(s); }
	
	const Word& operator=(const Word& w) {
		if (this != &w) {
			cout << "op= with " << w.str;
			cout << "\tthis->str is " << (str ? str : "nullptr") << endl;
			freq = w.freq; delete [] str; setstr(w.str);
		}
		return *this;
	}
};

int main() {
	Word ship("Titanic"); // Which constructor?
	Word movie(ship); // Which constructor?
	Word song("My heart will go on"); // Which constructor?
	song = song; // Call assignment operator (self-assignment, not executed)
	song = movie; // Call assignment operator
}