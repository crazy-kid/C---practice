#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char firstName[30], lastName[30], fullName[60];
    cout << "Enter your first name: ";
    cin.getline(firstName, 30);
    cout << "Enter your last name: ";
    cin.getline(lastName, 30);
    strcpy(fullName, lastName);
    strcat(fullName, ", ");
    strcat(fullName, firstName);
    cout << fullName << endl;
    return 0;
}