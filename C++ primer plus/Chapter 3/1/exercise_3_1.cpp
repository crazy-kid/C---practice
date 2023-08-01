#include <iostream>

using namespace std;

const int FOOT_TO_INCH = 12;

int main() {
    int height;
    cout << "Enter your height in inches_";
    cin >> height;
    cout << endl << "Your Height convert to " << height / FOOT_TO_INCH;
    cout << " foot and " << height % FOOT_TO_INCH << " inch height." << endl;
    return 0;
}