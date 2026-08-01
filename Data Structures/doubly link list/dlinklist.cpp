#include <iostream>
using namespace std;

class dlink_list {

    class node {
    public:
        int data;
        node* next = nullptr;
        node* prev = nullptr;
    };

public:
    node* head = nullptr;
    node* tail = nullptr;
    int size = 0;

    //function in order to fill up the dll.
    void populate(int data) {
        if (head == nullptr) {
            head = new node();
            head->data = data;
            tail = head;
            size ++;

        }
        else {
            node *obj = new node();
            obj->data = data;
            tail->next = obj;
            obj->prev = tail;
            tail = obj;
            obj = nullptr;
            size++;
        }
    }

    //use to print the whole dll
    void print_all() {

        node *current = head;
        while (current != nullptr) {

            cout << current->data << " ";
            current = current->next;

        }
        cout << endl;

    }

    //use to print the whole dll in reverse.
    void print_rev() {

        node *current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;

    }

    //Used to insert at the begining.
    void insertb(int data) {

        if (head == nullptr) {
            this->populate(data);
        }
        else {
            node *obj = new node();
            obj->data = data;
            obj->next = head;
            head->prev = obj;
            head = obj;
            obj = nullptr;
            size++;
        }

    }

    //use to insert data anywhere
    void insert_anywhere(int pos, int data) {


        if (pos == 1) {
            insertb(data);
        }
        else if (head == nullptr) {
            cout << "List is empty for the given position" << endl;
        }
        else {
            if (pos < 1 || pos > size+1) {
                cout << "Invalid Position" << endl;
            }
            if (pos == size+1) {
                this->populate(data);
            }
            else {
                node *current = head;
                int counter = 1;
                while (current != nullptr) {
                    if (counter == pos-1) {
                        node *obj = new node();
                        obj->data = data;
                        node *temp = current->next;
                        current->next = obj;
                        obj->next = temp;
                        temp->prev = obj;
                        obj->prev  = current;
                        size++;
                        break;

                    }
                    current = current->next;
                    counter++;
                }
            }

        }


    }

};



int main() {

    dlink_list theList;

    for (int i = 1; i <= 5; i++) {
        theList.populate(i);
    }

    theList.insertb(0);
    theList.print_all();
    theList.print_rev();
    theList.insert_anywhere(4,-2);
    theList.print_all();
    theList.print_rev();

}
