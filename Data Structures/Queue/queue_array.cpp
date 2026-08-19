#include <iostream>
using namespace std;

class Queue_linklist {

    int front = 0;
    int rear = -1;
    int counter = 0;
    int capacity = 0;
    //creating simple array
    //array pointer
    int *ptr = nullptr;
public:
    Queue_linklist(int s) {
        this->capacity = s;
        ptr = new int[s];
    }

    void enqueue(int x) {

        //check at the start to handle this condition
        if (counter == capacity ) {
            cout << "Queue is full" << endl;
            return;
        }
        //we can do rear++ but as we have to use circular array we have to modulo it by size too.
        rear = (rear+1) % capacity;
        ptr[rear] = x; //inserting element inside the queue
        counter++; // increasing size.
    }


    int dequeue() {
        if (counter == 0 ) {
            cout << "Queue is empty" << endl;
        }
        else {
            int value = ptr[front];
            front = (front + 1) % capacity; // no need to remove the element the data will be overwritten automatically
            counter--;
            return value;
        }
    }

    int isEmpty() {
        return counter == 0;
    }
    int isFull() {
        return counter == capacity;
    }

    int size() {
        return counter;
    }

    int peek() {
        if (counter == 0 ) {
            cout << "Queue is empty" << endl;

        }
        else {
            return ptr[front];
        }
    }

    ~Queue_linklist() {
        delete [] ptr;
    }




};

//The presence of counter variable really made the code easy where full and empty conditions can be easily checked
// by checking the counter value.


int main() {
    Queue_linklist q(10);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    for (int i = 0; i < 4; i++) {
        cout << q.dequeue() << endl;
    }
    for (int i = 0; i < 10; i++) {
        q.enqueue(i);
    }

    cout << q.isFull() << endl;

}