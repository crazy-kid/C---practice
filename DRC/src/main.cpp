#include <iostream>
#include <queue>
#include <unordered_set>
#include "rectangle.h"

using namespace std;

priority_queue<Rectangle*, vector<Rectangle*>, cmp> rect_queue;
vector<Rectangle*> cache;
unordered_set<Rectangle*> ans;

void init();

int main(int argc, char const* argv[])
{
    init();
    while (rect_queue.size() > 1) {
        Rectangle* cur = rect_queue.top();
        rect_queue.pop();
        while (!rect_queue.empty() && cur->_right > rect_queue.top()->_left - Rectangle::gap) {
            Rectangle* rect = rect_queue.top();
            rect_queue.pop();
            cache.push_back(rect);
            if (!isValid(*cur, *rect)) {
                ans.insert(cur);
                ans.insert(rect);
            }
        }
        for (Rectangle* ptr : cache) {
            rect_queue.push(ptr);
        }
        cache.clear();
    }

    for (Rectangle* ptr : ans)
        ptr->print();
    return 0;
}

void init() {
    Rectangle* rect_ptr_1 = new Rectangle(0, 7, 4, 0);
    Rectangle* rect_ptr_2 = new Rectangle(11, 14, 4, 0);
    Rectangle* rect_ptr_3 = new Rectangle(0, 4, 12, 7);
    Rectangle* rect_ptr_4 = new Rectangle(14, 18, 19, 9);
    Rectangle* rect_ptr_5 = new Rectangle(6, 10, 20, 13);
    rect_queue.push(rect_ptr_1);
    rect_queue.push(rect_ptr_2);
    rect_queue.push(rect_ptr_3);
    rect_queue.push(rect_ptr_4);
    rect_queue.push(rect_ptr_5);
}