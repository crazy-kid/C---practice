#ifndef WINE_H_
#define WINE_H_
#include <iostream>
#include <string>
#include <valarray>
#include "pairs.h"

using namespace std;

// typedef std::valarray<int> ArrayInt;
// typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : private Pair<valarray<int>, valarray<int>>
{
private:
    string label;
    int year;
public:
    Wine(const char* l, int y, const int yr[], const int bot[]);
    Wine(const char* l, int y);
    void getBootles();
    const string& getLabel() const;
    int sum() const;
    void show();
};
#endif 