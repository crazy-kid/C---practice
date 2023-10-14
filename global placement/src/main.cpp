#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>

#include "rectangle.h"

int main(int argc, char const* argv[])
{
    const int n = 10, split = 5;
    int range[2] = { 100,30 };
    int maxSize[2] = { 18,15 };
    float avgArea = 0;

    Rectangle::setRange(range[0], range[1]);
    vector<Rectangle> rects;
    for (int i = 0;i < n;i++) {
        int length = rand() % (maxSize[0]) + 1;
        int width = rand() % (maxSize[1]) + 1;
        rects.push_back(Rectangle(length, width));
        avgArea += length * width;
        rects[i].print();
    }

    cout << endl << "Area Sum = " << avgArea << "  avgArea = " << (avgArea /= split) << endl << endl;;

    float leftArea = avgArea;
    int binIndex = 0, cur = 0;
    while (binIndex < split) {
        int shape[2];
        rects[cur].getShape(shape);
        if (leftArea <= rects[cur].getArea()) {
            float overflow = rects[cur].getArea() - leftArea;
            float leftLen = leftArea / shape[1];
            rects[cur].setPosition((binIndex + 1) * (range[0] / split) - leftLen, 0);
            binIndex++;
            leftArea = avgArea - overflow;
        }
        else {
            rects[cur].setPosition(binIndex * (range[0] / split), range[1] - shape[1]);
            leftArea -= rects[cur].getArea();
        }
        cur++;
    }

    for (Rectangle& d : rects)
        d.print();
    return 0;
}
