#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include <iostream>

using namespace std;

class Rectangle {

public:
    int _left;
    int _right;
    int _up;
    int _down;
    static const int gap = 4;

    Rectangle(int left, int right, int up, int down);
    void print() { cout << _left << " " << _right << " " << _up << " " << _down << endl; };
    friend bool compare(const Rectangle& rect1, const Rectangle& rect2);
    friend bool isValid(const Rectangle& rect1, const Rectangle& rect2);
};

bool operator<(const Rectangle& rect1, const Rectangle& rect2);

struct cmp {
    bool operator()(const Rectangle* const rect1, const Rectangle* const rect2);
};

#endif