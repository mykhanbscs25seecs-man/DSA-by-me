#include <iostream>
#include <C:\Users\User\OneDrive\Desktop\3rd sem\Dsa\DSA-byMe\DSA-by-me\Data Structures\linked list\linklist.h>
using namespace std;

class Stack {

private:
    linklist the_list;
    linklist::node *top = nullptr;

public:
    void push(int data) {

        the_list.insertb(data);
        top = the_list.starter;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
        }
        else {
            the_list.deleteb();
            top = the_list.starter;
        }
    }

    void peek() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
        }
        else {
            cout << top->data << endl;
        }
    }

    int isEmpty() {

        return top == nullptr;
    }

    void tell_size() {
        cout << the_list.size << endl;
    }


};

int main() {

    Stack s;
    for (int i = 1; i <= 10; i++) {
        s.push(i);
    }
    s.peek();
    s.pop();
    s.peek();
    s.tell_size();

}