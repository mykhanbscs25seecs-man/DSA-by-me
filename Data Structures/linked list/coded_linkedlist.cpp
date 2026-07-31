#include <iostream>
using namespace std;



class Node {
public:
    int data;
    Node* next = nullptr;
};

int main(){
    Node* head = nullptr;
    Node* temp = nullptr;
    for (int i = 1; i <= 3; i++) {

        Node* ob = new Node();
        ob->data = i;
        if (not(temp == nullptr)) {
            temp->next = ob;
        }
        temp = ob;
        if(i == 1) {
            head = ob;
        }



    }

    //accssing linked list
    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
}

