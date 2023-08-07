#include <iostream>

using namespace std;

int main() {
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;
    for (int row = 0;row < rows;row++) {
        for (int i = 0;i < rows - row - 1;i++)
            cout << '.';
        for (int i = 0;i <= row;i++)
            cout << '*';
        cout << endl;
    }
}