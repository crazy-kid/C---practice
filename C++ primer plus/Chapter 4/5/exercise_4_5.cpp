#include <iostream>
#include <cstring>

using namespace std;

struct CandyBar
{
    char brand[30];
    double weight;
    int calorie;
};

int main() {
    CandyBar snack = { "Mocha Munch",2.3,350 };
    cout << snack.brand << endl;
    cout << snack.weight << endl;
    cout << snack.calorie << endl;
}