// queue.h -- interface for a queue
#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

template <class T>
class Queue
{
private:
    struct Node { T item; struct Node* next; };
    enum { Q_SIZE = 10 };
    Node* front;
    Node* rear;
    int items;
    const int qsize;
    Queue(const Queue& q) : qsize(0) { }
    Queue& operator=(const Queue& q) { return *this; }
public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isempty() const { return items == 0; }
    bool isfull() const { return items == Q_SIZE; }
    int queuecount() const { return items; }
    bool enqueue(const T& item);
    bool dequeue(T& item);
};


template <class T>
Queue<T>::Queue(int qs)
    : qsize(qs), front(nullptr), rear(nullptr), items(0)
{}

template <class T>
Queue<T>::~Queue()
{
    T item;
    while (!isempty())
        dequeue(item);
}


// template <class T>
// bool Queue<T>::isempty() const { return items == 0; }
// bool isfull() const;
// int queuecount() const;

template <class T>
bool Queue<T>::enqueue(const T& item) {
    if (isfull()) {
        std::cout << "queue is full!!" << std::endl;
        return false;
    }
    Node* add = new Node;
    items++;
    add->item = item;
    add->next = nullptr;
    if (front == nullptr)
        front = add;
    else
        rear->next = add;
    rear = add;
    return true;
}

template <class T>
bool Queue<T>::dequeue(T& item)
{
    if (isempty()) {
        std::cout << "queue is empty!!" << std::endl;
        return false;
    }
    items--;
    item = front->item; // 返回pop出的元素
    Node* del = front;
    if (items == 0)
        rear = nullptr;
    front = front->next;
    delete del;
    return true;
}

#endif
