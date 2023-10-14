#include <algorithm>
#include <iostream>
#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(int left, int right, int up, int down) :
    _left(left), _right(right), _up(up), _down(down)
{
    if (left >= right || down >= up) cout << "Invalid Rectangle" << endl;
}

bool compare(const Rectangle& rect1, const Rectangle& rect2) {
    if (rect1._left != rect2._left) {
        return rect1._left < rect2._left;
    }
    else
        return rect1._up <= rect2._up;
}

bool isValid(const Rectangle& rect1, const Rectangle& rect2) {
    int dx = max(max(0, rect2._left - rect1._right), max(0, rect1._left - rect2._left));
    int dy = max(max(0, rect2._down - rect1._up), max(0, rect1._down - rect2._up));
    if (dx + dy < 4) return false;
    return true;
}

bool operator<(const Rectangle& rect1, const Rectangle& rect2) {
    return compare(rect1, rect2);
}


bool cmp::operator()(const Rectangle* const rect1, const Rectangle* const rect2) {
    return !compare(*rect1, *rect2);
}
