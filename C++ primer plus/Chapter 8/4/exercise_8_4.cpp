#include <iostream>
using namespace std;
#include <cstring>
struct stringy {
    char* str;
    int ct;
};

void set(stringy&, char*);
void show(const stringy&, int times = 1);
void show(const char* const str, int times = 1);

int main() {
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");
    return 0;
}

void set(stringy& b, char* str) {
    b.ct = strlen(str);
    b.str = new char[b.ct + 1];
    strcpy(b.str, str);
}


void show(const stringy& b, int times) {
    for (int i = 0;i < times;i++)
        cout << b.str << endl;
}

void show(const char* const str, int times) {
    for (int i = 0;i < times;i++)
        cout << str << endl;
}