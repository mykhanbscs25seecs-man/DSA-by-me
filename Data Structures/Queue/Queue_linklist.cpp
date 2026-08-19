#include <iostream>
#include "D:\Me\DSA-by-me\Data Structures\linked_list\linklist.h"
using namespace std;

class Queue_linklist {

    linklist l;
    linklist::node *front = nullptr;
    linklist::node *rear = nullptr;
    public:
    void enqueue(int data) {
        if (front == nullptr) {
            linklist::node *obj = new linklist::node();
            l.starter = obj;
            l.tail = obj;
            front = l.starter;
            rear = l.tail;
            front->data = data;
            front->next = nullptr;
            l.size++;
            return;
        }
        linklist::node *ptr = new linklist::node();
        l.tail->next = ptr;
        l.tail = ptr;
        rear = l.tail;
        rear->next = nullptr;
        rear->data = data;
        l.size++;
    }

    int dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;

        }
        else {
            int value = front->data;
            if (front->next == nullptr) {
                front = nullptr;
                rear = nullptr;
            }
            l.deleteb();
            front = l.starter;

            return value;
        }

    }

    int is_empty() {
        return front == nullptr;
    }

    int size() {
        return l.size;
    }

    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;

        }
        else {
            return front->data;
        }

    }





};


int main() {

    Queue_linklist ql;
    for (int i = 0; i < 5; i++) {
        ql.enqueue(i);
    }
    while (ql.is_empty() == 0) {
        int value = ql.dequeue();
        cout << value << endl;
    }

}