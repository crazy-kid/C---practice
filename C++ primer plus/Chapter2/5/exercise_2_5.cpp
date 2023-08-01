#include <iostream>

using namespace std;

int main() {
    float Celsius;
    cout << "Please enter a Celsius value: ";
    cin >> Celsius;
    cout << Celsius << " degrees Celsius is " << 1.8 * Celsius + 32 << " degress Fahrenheit" << endl;
}