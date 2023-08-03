#include <iostream>
#include <cstring>

using namespace std;

struct CandyBar
{
    char brand[30];
    double weight;
    int calorie;
};
// void print(CandyBar);

void print(CandyBar candyBar) {
    cout << candyBar.brand << endl;
    cout << candyBar.weight << endl;
    cout << candyBar.calorie << endl;
}

int main() {
    CandyBar snacks[3] = {
        { "Mocha Munch",2.3,350 },
        {"Hershery bar",4.2,550},
        {"Musketeers",2.6,430} };
    for (int i = 0;i < 3; i++) {
        print(snacks[i]);
    }
}