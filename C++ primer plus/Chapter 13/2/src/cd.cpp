#include "cd.h"
#include <iostream>
#include <cstring>

Cd::Cd(char* s1, char* s2, int n, double x)
{
    performers = new char[strlen(s1) + 1];
    strcpy(performers, s1);
    label = new char[strlen(s2) + 1];
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd& d)
{
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    performers = nullptr;
    label = nullptr;
    selections = 0;
    playtime = 0;
}

Cd::~Cd()
{
    if (performers != nullptr)
        delete[] performers;
    if (label != nullptr)
        delete[] label;
}

void Cd::Report()const
{
    std::cout << "performers: " << performers << std::endl;
    std::cout << "label: " << label << std::endl;
    std::cout << "selections: " << selections << std::endl;
    std::cout << "palytime: " << playtime << std::endl;
    std::cout << std::endl;
}

Cd& Cd::operator=(const Cd& d)
{
    if (this == &d)
        return *this;
    if (performers != nullptr)
        delete[] performers;
    if (label != nullptr)
        delete[] label;
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}