#include <iostream>
#include "worker.h"
#include "queue.h"
const int SIZE = 5;

using namespace std;

int main()
{
    Queue<Worker> queue;
    Worker w1;
    w1.Set();
    queue.enqueue(w1);
    Worker w2;
    queue.dequeue(w2);
    w2.Show();
    return 0;
}
