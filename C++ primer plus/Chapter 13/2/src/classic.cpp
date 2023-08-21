#include "classic.h"
#include <iostream>
#include <cstring>

Classic::Classic(char* performers, char* label, char* works, int selections, double x)
    :Cd(performers, label, selections, x)
{
    this->works = new char[strlen(works) + 1];
    strcpy(this->works, works);
}

Classic::Classic(const Classic& cic)
    :Cd(cic)
{
    this->works = new char[strlen(cic.works) + 1];
    strcpy(this->works, cic.works);
}

Classic::Classic()
    :Cd()
{
    works = nullptr;
}

Classic::~Classic()
{
    if (works != nullptr)
        delete[] works;
}

void Classic::Report()const
{
    std::cout << "works: " << works << std::endl;
    Cd::Report();
}

Classic& Classic::operator=(const Classic& cic)
{
    if (this == &cic)
        return *this;
    if (works != nullptr)
        delete[] works;
    works = new char[strlen(cic.works) + 1];
    strcpy(works, cic.works);
    Cd::operator=(cic);
}