#include <iostream>
using namespace std;

/*Lets implement stack ds that is a LIFO data structure here is implemented using arrays
 * We implement can add data into stack just like we do in arrays but the thing is we cant
 * insert data anywhere it will be inserted always atlast aka top of the stack and will also
 * be removed from the stack's top.
 *
 */

class Stack {

public:
    int size = 0; //User will give size as input because stack like array will be fix in size
    int top = -1; //top -1 indicates that the stack is empty initially, top is nothing just the index
    // of top element so the top element can be accessed.

private:

    int *ptr = nullptr; //pointer that is null and constructor will set its value.

public:
    //Constructor will initialize the size value
    Stack(int size) {
        this->size = size;
        ptr = new int[size];//a dynamic array is created in the heap because the size is user defined.
    }

    //Used to insert data at the top of stack
    void push(int data) {
        if (top == size - 1) { //As top is the index to last element if == size-1 then no more data can be
            //stored, size full.
            cout << "Stack Overflow" << endl;
            return;
        }
        //else if space available just move the top by one pos and insert the data.
        top++;
        ptr[top] = data;

    }

    //Used to delete data from the end/top.
    void pop() {
        if (top == -1) {//This mans stack is already empty nothing to delete.
            cout << "Stack Underflow" << endl;
            return;
        }
        //Just move the top backwards, dont need to delete the data left behind , it will be over
        //-written on push and stack will also not consider that as its available part.
        top--;
    }

    //Used to get value of the top element
    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        }
        else {
            return ptr[top];
        }

    }

    int isempty() {
        if (top == -1) {
            return 1;
        }

        return 0;
    }

    int is_full() {
        if (top == size-1) {
            return 1;
        }
        return 0;
    }

    int tell_size() {
        return top + 1;
    }

    //Destructor function to free up the dynamic array when the main ends to prevent memory leak.
    void destroy() {
        delete[] ptr;
        ptr = nullptr;

    }

    ~Stack() {
        this->destroy();
    }
};


//main function testing stack.
int main() {

    Stack s1(5);
    for ( int i = 1 ; i <= 7; i++) {
        s1.push(i);
    }
    cout << s1.tell_size() << endl;
    cout << s1.peek() << endl;
    cout << s1.is_full() << endl;
    cout << s1.isempty() << endl;
    s1.pop();
    cout << s1.tell_size() << endl;



}
