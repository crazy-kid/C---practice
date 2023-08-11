#include <iostream>
#include <string>

using namespace std;

struct CandyBar {
    string name;
    float weight;
    int cal;
};

void set(CandyBar& candyBar, string name = "Millennium Munch", float weight = 2.85, int cal = 350);
void show(const CandyBar& candyBar);

int main() {
    CandyBar candy1;
    CandyBar candy2;
    CandyBar candy3;
    set(candy1, "Hello", 4.5, 200);
    set(candy2, "World", 5.5, 300);
    set(candy3, "C++", 6.5, 400);
    show(candy1);
    show(candy2);
    show(candy3);
    return 0;
}

void set(CandyBar& candyBar, string name, float weight, int cal) {
    candyBar.name = name;
    candyBar.weight = weight;
    candyBar.cal = cal;
}

void show(const CandyBar& candyBar) {
    cout << "Brand: " << candyBar.name << endl;
    cout << "weight: " << candyBar.weight << endl;
    cout << "cal: " << candyBar.cal << endl;
}