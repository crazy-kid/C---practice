#include <iostream>
#include <string>
#include <valarray>
#include "wine.h"


Wine::Wine(const char* l, int y, const int yr[], const int bot[])
    : label(l), year(y), Pair<valarray<int>, valarray<int>>(valarray<int>(yr, y), valarray<int>(bot, y))
{}

Wine::Wine(const char* l, int y)
    :label(l), year(y), Pair<valarray<int>, valarray<int>>(valarray<int>(0, 0), valarray<int>(0, 0))
{}

void Wine::getBootles()
{
    cout << "Enter" << label << " data for " << year << " year(s):\n";
    this->first().resize(year);
    this->second().resize(year);
    for (int i = 0;i < year;i++) {
        cout << "Enter year: ";
        cin >> this->first()[i];
        cout << "Enter bottles for that year: ";
        cin >> this->second()[i];
    }
}

const string& Wine::getLabel() const
{
    return label;
}

int Wine::sum() const
{
    return this->second().sum();
}

void Wine::show()
{
    cout << "Wine: " << label << endl;
    cout << "   Year    Bottles" << year << endl;
    for (int i = 0;i < year;i++)
        cout << "   " << this->first()[i] << "    " << this->second()[i] << endl;

}