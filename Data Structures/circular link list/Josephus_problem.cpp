#include <iostream>
#include "clinklist.cpp"
#include <random>
using namespace std;

class Josephus {


Clinklist list;
int min = 1;
int max = 0;

    public:
    Josephus(int n) {
        if (n == 0) {
            min = 0;
        }

        max = n;
        //populating circular list
        for (int i = 1; i <= n; i++) {
            list.populate(i);
        }
    }

    Clinklist::node *survivor() {


        if (list.head == nullptr) {
            return nullptr;
        }

        std::random_device rd;
        std::mt19937 gen(rd());

        Clinklist::node *start = list.head;


        while (start->next != start) {

            Clinklist::node *tail = start;

            do {

            tail = tail->next;


        }while (tail->next != start);

            std::uniform_int_distribution<int> distrib(min, max);
            int pos = distrib(gen);

            Clinklist::node *current = start;
            int count = 1;

            do {
                if (pos == 1) {
                    //it will work perfectly because everytime the loop calculates the tail.
                    Clinklist::node *t = start;
                    if (start == list.head) {
                        list.head = list.head->next;
                    }
                    start = start->next;
                    delete t;
                    tail->next = start;

                    break;
                }
                if (count == pos-1) {

                    Clinklist::node *temp = current->next;
                    if (temp == list.head) {
                        list.head = temp->next;
                    }
                    start = temp->next;
                    current->next =  current->next->next;


                    delete temp;

                    break;
                }
                current = current->next;
                count++;
            }while (current->next != start);

            //calculating size at the end of the remaing circle
            max--;
        }

        return start;


    }

};


int main() {

    Josephus j1(15);
    Clinklist::node *ptr = j1.survivor();
    cout << ptr->data << endl;


}