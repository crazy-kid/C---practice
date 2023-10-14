#include <iostream>
#include <stdlib.h>
#include "rectangle.h"

using namespace std;

int Rectangle::_range[2] = { 0,0 };

Rectangle::Rectangle(int length, int width)
{
    _shape[0] = length;
    _shape[1] = width;
    // 随机分配位置
    _position[0] = rand() % (_range[0] - _shape[0] + 1);
    _position[1] = rand() % (_range[1] - _shape[1] + 1);
    _area = _shape[0] * _shape[1];
}