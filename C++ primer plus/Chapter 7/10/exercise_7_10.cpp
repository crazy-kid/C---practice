#include <iostream>

using namespace std;

double add(double, double);
double sub(double, double);
double div(double, double);
double mul(double, double);
typedef double (*fptr)(double, double);
fptr funcArray[4] = { add,sub,div,mul };

int main() {
    double a, b;
    cout << "Enter two double: ";
    int size = sizeof(funcArray) / sizeof(funcArray[0]);
    while (cin >> a >> b && !cin.fail()) {
        for (int i = 0;i < size;i++) {
            cout << funcArray[i](a, b) << " ";
        }
        cout << endl;
        cout << "Enter two double: ";
    }
}


double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double div(double a, double b) { return a / b; }
double mul(double a, double b) { return a * b; }