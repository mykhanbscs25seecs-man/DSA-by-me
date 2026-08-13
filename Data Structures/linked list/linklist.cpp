#include <codecvt>
#include <iostream>
#include <cmath>
using namespace std;



class linklist {

friend class Stack;

    class node {
        public:
        int data;
        node* next = nullptr;
    };


public:
    int size = 0;
    node* starter = nullptr;



    void populate(int input) {
        if (starter == nullptr) {
            node *obj = new node();
            obj->data = input;
            starter = obj;
            size++;
        }
        else {

            node* current = starter;
            while (current->next != nullptr) {
                current = current->next;
            }

            node *obj = new node();
            obj->data = input;
            current->next = obj;
            current = nullptr;
            size++;
        }


    }

    void print() {
        if (starter == nullptr) {

            cout << "List is empty" << endl;
        }
        node * current = starter;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void del_list() {

        node * head = starter;
        node * temp = nullptr;
        if (head == nullptr) {
            cout << "List is empty" << endl;
        }
        else {
            while (head->next != nullptr) {
                temp = head->next;
                delete head;
                head = temp;

            }


            delete head;


            head = nullptr;
            temp = nullptr;
            this->size = 0;
            this->starter = nullptr;
        }
        }


    void insertb(int value) {
        if (starter != nullptr) {
            node *obj = new node();
            obj->data = value;
            obj->next = starter;
            starter = obj;
            size++;
        }
        else {
            this->populate(value);
        }
    }

    void deleteb() {
        if (starter != nullptr) {
            node *temp = starter->next;
            delete starter;
            starter = temp;
            temp = nullptr;
            size--;
        }
        else {
            cout << "The list is empty" << endl;
        }
    }

    void insert_anywhere(int pos, int value) {
        node *current = starter;
        int counter = 1;
        if (starter == nullptr) {
            cout << "List is empty" << endl;
        }
        else {
            if (pos > size+1 or pos < 1) {
                cout << "Invalid position !" << endl;
            }
            else {
                if (pos == 1) {
                    this->insertb(value);
                }
                else {
                    while (current != nullptr) {
                        if (counter == pos-1) {

                            node *obj = new node();

                            obj->data = value;
                            if (pos-1 == size) {
                                obj->next = nullptr;
                            }
                            else {
                                obj->next = current->next;
                            }

                            current->next = obj;

                        }
                        current = current->next;
                        counter++;
                    }
                    size++;
                }

            }
        }



    }

    void delete_anywhere(int pos) {
        if (starter != nullptr) {
            node *current = starter;
            node *temp = nullptr;
            int counter = 1;
            if (pos > size or pos < 1) {
                cout << "Invalid position !" << endl;
            }
            else {

                if (pos == 1) {
                    this->deleteb();
                }
                else {
                    while (current != nullptr) {
                        if (counter == pos-1) {
                            temp = current;
                            temp = current->next;
                            current->next = (current->next)->next;
                            temp->next = nullptr;
                            delete temp;
                            temp = nullptr;
                        }
                        current = current->next;
                        counter++;
                    }

                    size--;
                }



            }

        }
        else {
            cout << "The list is empty" << endl;
        }
    }


   void reverse_list() {
        if (starter == nullptr) {
            cout << "List is empty" << endl;
        }
        else {

            node *current = starter;
            node *temp = starter;
            int counter = 1;
            while (true) {



                if (starter->next == nullptr) {
                    if (counter != 1) {
                        current->next = temp;
                        temp = nullptr;
                        current = nullptr;
                        break;
                    }

                    break;


                }

                starter = starter->next;


                if (counter == 1) {
                    current = starter;
                    temp->next = nullptr;
                }
                else {
                    current->next = temp;
                    temp = current;
                    current = starter;


                }
                counter++;



            }

        }
    }


    node* middle_node(node* head) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
        }
        else {
            node* current = head;
            int s = 1;
            //logic to determine size of the list
            while (current->next != nullptr) {
                current = current->next;
                s++;
            }

            if (s == 1) {
                return head;
            }

            //getting the middle number of the node
            int middleNum = 0;

            if (s%2 != 0) {
                middleNum = ceil(s/2.0);
            }
            else {
                middleNum = s / 2 + 1;
            }

            //now we target the middle node to return its header.
            current = head;
            int counter = 1;
            while (current->next != nullptr) {

                if (counter == middleNum) {
                    return current;
                }
                current = current->next;
                counter++;


            }

        }

    }


    void show(node* curr) {
        cout << curr->data << endl;
    }

    ~linklist() {
        this->del_list();
    }


};




int main() {


    linklist mylist;
    for (int i = 1; i <= 8; i++) {
        mylist.populate(i);
    }
    mylist.print();

    mylist.show(mylist.middle_node(mylist.starter));


}
