#include <iostream>
#include <cstring>

using namespace std;

void f1(int* a);
typedef void (*p1)(int* a);
p1 ptr1 = f1;

int main() {
    char str[] = "Hello";
    cout << strlen(str) << endl;;
    cout << sizeof(str) << endl;;
}

void f1(int* a) {
    cout << *a << endl;
}