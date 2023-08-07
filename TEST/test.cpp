#include <iostream>

using namespace std;

void f1(int* a);
typedef void (*p1)(int* a);
p1 ptr1 = f1;

int main() {
    int a = 3;
    ptr1(&a);
}

void f1(int* a) {
    cout << *a << endl;
}