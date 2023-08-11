#include <iostream>

using namespace std;

void print(const char* str, int i = 0);

int main() {
    char* str = "abcdefg";
    print(str);
    print(str);
    print(str, 2);
}

void print(const char* str, int i) {
    static int count = 0;
    count++;
    if (i != 0)
        for (int i = 0;i < count;i++)
            cout << str << endl;
    else
        cout << str << endl;
}
