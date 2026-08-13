//
// Created by User on 8/10/2026.
//
#pragma once

#ifndef DSA_BYME_STACK_LINKLIST_H
#define DSA_BYME_STACK_LINKLIST_H

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

    int get_top() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
        }
        else {
            return top->data;
        }
    }

    int isEmpty() {

        return top == nullptr;
    }

    void tell_size() {
        cout << the_list.size << endl;
    }


};





#endif //DSA_BYME_STACK_LINKLIST_H
