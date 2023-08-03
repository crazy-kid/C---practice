#include <iostream>

using namespace std;

int main() {
    char firstName[30], lastName[30], grade;
    int age;
    cout << "What is your first name? ";
    cin.getline(firstName, 30);
    cout << "What is your last name? ";
    cin.getline(lastName, 30);
    cout << "What letter grade do you deserve? ";
    cin >> grade;
    cout << "What is your age? ";
    cin >> age;
    cout << "Name " << lastName << "," << firstName << endl;
    cout << "Grade: " << char(grade + 1) << endl;
    cout << "Age: " << age << endl;
    return 0;
}