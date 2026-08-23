#include <iostream>
#include <forward_list>
#include <stack>
using namespace std;

class MinStack {
    stack <int> st; // stack to store record of minimum values.
    forward_list <int> the_list;

public:
    void push(int x) {
        the_list.push_front(x);
        if(st.empty()){
            st.push(x);
        }

        else if (x <= st.top()) {
            st.push(x);
        }
    }

    void pop() {
        if (the_list.empty()) {
            return;
        }
        int x = this->top();
        the_list.pop_front();

        if (x == st.top()) {
            st.pop(); //what we are popping if thats equal to the min then pop of that min too
            // so now top of st points for the new minimum.

        }


    }

    int top() {
        if (the_list.empty()) {
            return -1;
        }
        return the_list.front();
    }

    int getMin() {
        if (the_list.empty()) {
            return -1;
        }
        return st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */