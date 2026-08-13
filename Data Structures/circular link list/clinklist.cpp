#include <iostream>
using namespace std;

class Clinklist {

friend class Josephus;

public:

    class node {
        public:
        int data;
        node *next;
    };

private:
    node *head = nullptr;


public:
    int size = 0;

    void populate(int data) {

        if (head == nullptr) {
            head = new node();
            head->data = data;
            head->next = head;
            size++;
        }
        else {
            node *current = head;
            do {
                current = current->next;

            }while (current->next != head);

            current->next = new node();
            current->next->data = data;
            current->next->next = head;
            size++;
        }

    }

    void print() {

        if (head == nullptr) {
            cout<<"List is empty"<<endl;
        }
        else {
            node *current = head;
            do {
                cout << current->data << " ";
                current = current->next;
            }while (current != head);
            cout<<endl;

        }
    }

    void insertb(int data) {
        if (head == nullptr) {
            this->populate(data);
        }
        else {
            node *current = head;

            do {
                current = current->next;
            }while (current->next != head);

            node *temp = head;
            head = new node();
            head->data = data;
            head->next = temp;
            current->next = head;
            size++;
        }


    }

    void insert_anywhere(int pos, int data) {

        if (pos == 0) {

            this->insertb(data);
            return;
        }
        if (head == nullptr) {
            cout << "List is empty"<<endl;
            return;
        }

        if (pos < 1 || pos > size + 1) {
            cout << "Wrong Position"<<endl;
            return;
        }

        if (pos == 1) {
            this->insertb(data);
            return;
        }

        node *current = head;
        int counter = 1;
        do {
            //will also work for the tail insertion.
            if (counter == pos-1) {

                node *temp = current->next;
                current->next = new node();
                current->next->data = data;
                current->next->next = temp;
                size++;
            }

            current = current->next;
            counter++;
        }while (current != head);


    }

    void deleteb() {

        if (head == nullptr) {
            cout << "List is empty." << endl;
        }
        else {
             node *current = head;
             do {
                 current = current->next;
             }while (current->next != head);
             node *temp = head;
             head = head->next;
             delete temp;
             if (size != 1) {
                 current->next = head;
             }
             size--;

        }
    }

    void delete_anywhere(int pos) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (pos < 1 || pos > size) {
            cout << "Wrong Position." << endl;
            return;
        }

        if (pos == 1) {
            this->deleteb();
            return;
        }

        node *current = head;
        int counter = 1;
        do {
            //this will also work for the tail node
            if (counter == pos-1) {

                node *temp = current->next;
                current->next = current->next->next;
                delete temp;
                size--;
            }
            current = current->next;
            counter++;
        }while (current->next != head);


    }

    void delete_all() {
        if (head == nullptr) {
            return;
        }

        node *temp = nullptr;
        node *current = head;
        //first we need to break the cycle.
        do {
            current = current->next;
        }while (current->next != head);

        current->next = nullptr;
        //broke the cycle

        //now we will delete
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }

        size = 0;
    }


    ~Clinklist() {
        this->delete_all();
    }

};



