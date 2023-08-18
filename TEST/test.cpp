#include <iostream>
#include <cstring>

using namespace std;

int& f1(int& a);
const int& f2(int& a);

int main() {
    int num1 = 1, num2 = 2;
    const int num3 = 3;
    f1(num1) = 5;//可以通过编译，语句执行后num==5。
    cout << num1 << endl;
    // f2(num2) = 9;//无法通过编译，f2(num2)无法作为左值。
}

int& f1(int& a) {
    a++;
    return a;
}

const int& f2(int& a) {
    a++;
    return a;
}