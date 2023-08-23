#include <iostream>
#include <string>
#include "worker.h"

using namespace std;

void Worker::Set()
{
    cout << "Enter worker's name: ";
    getline(cin, fullname);
    cout << "Enter worker's ID: ";
    cin >> id;
}

void Worker::Show() const
{
    cout << "Name: " << fullname << endl;
    cout << "Employee ID: " << id << endl;
}
