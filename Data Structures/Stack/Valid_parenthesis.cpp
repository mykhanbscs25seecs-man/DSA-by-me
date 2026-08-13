#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class valid_parenthesis { //assumes that the string given can only have parenthesis.

public:
    int validity(string str) {
        stack<char> s;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                s.push(str[i]);
            }
            else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
                if (s.empty()) {
                    return 0;
                }
                if (s.top() == '(' && str[i] == ')') {
                    s.pop();
                }
                else if (s.top() == '{' && str[i] == '}') {
                    s.pop();
                }
                else if (s.top() == '[' && str[i] == ']') {
                    s.pop();
                }
                else {
                    return 0;
                }

            }



        }

        if (!s.empty()) { // any bracket opened has not be closed.
            return 0;
        }

        return 1;


    }



};

int main() {

    valid_parenthesis v;
    cout << v.validity("}") << endl;
}