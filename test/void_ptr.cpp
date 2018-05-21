#include <iostream>

using namespace std;

class A {
    private:
        int i;
    public:
        A(int i) : i{i} {}
        void print() const {cout << i << endl;}
};

int main() {
    A obj{5};
    void* p = &obj;
    int* q = (int*)p;
    *q = 10;
    obj.print();
    return 0;
}
