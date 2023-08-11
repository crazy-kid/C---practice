#include <iostream>
#include <string>

using namespace std;

void translate(string& str);

int main() {
    string str;
    cout << "Enter a string (q to quit): ";
    getline(cin, str);
    while (str != "q") {
        translate(str);
        cout << str << endl;
        cout << "Next string (q to quit): ";
        getline(cin, str);
    }
    cout << "Bye" << endl;
    return 0;
}

void translate(string& str) {
    for (int i = 0;i < str.size();i++)
        str[i] = toupper(str[i]);
}