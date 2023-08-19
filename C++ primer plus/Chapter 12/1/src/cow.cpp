#include "cow.h"
#include <string.h>
#include <iostream>

using namespace std;

// dufault constructor
Cow::Cow() {
    name[0] = '\0';
    hobby = nullptr;
    weight = 0;
}

// constructor
Cow::Cow(const char* nm, const char* ho, double wt)
{
    strcpy(name, nm);
    hobby = new char[strlen(ho) + 1];
    strcpy(hobby, ho);
    weight = wt;
}

// copy constructor
Cow::Cow(const Cow& c)
{
    strcpy(name, c.name);
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow()
{
    delete[] hobby;
}

Cow& Cow::operator=(const Cow& c)
{
    if (&c == this)
        return *this;
    // cout << (void*)hobby << endl;
    if (hobby != nullptr)
        delete[] hobby;
    strcpy(name, c.name);
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    // cout << "return" << endl;
    return *this;
}

void Cow::ShowCow() const
{
    cout << " name: " << name;
    cout << " hobby: ";
    if (hobby != nullptr)
        cout << hobby;
    else
        cout << "nullptr";
    cout << " weight: " << weight;
    cout << endl;
}