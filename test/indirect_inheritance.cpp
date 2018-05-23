class B { protected: int a; };

class D : protected B { };

int main() {
	D obj;
	B& ref = obj;
	return 0;
}