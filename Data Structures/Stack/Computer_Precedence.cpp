#include <iostream>
#include <cmath>
#include "stack_linklist.h"
#include <vector>
#include <stack>
using namespace std;

class Precedence {



    public:
    int postfix(string exp) { //Note the method expects a postfix expression to work with.

        Stack s; // created our stack obj.

        for (int i = 0; i < exp.length(); i++) {
            if (not(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')) {
                s.push(exp[i] - '0');
            }
            else {
                int second_digi = s.get_top();
                s.pop();
                int first_digi = s.get_top();
                s.pop();

                switch (exp[i]) {
                    case '+':
                        s.push(first_digi+second_digi);
                        break;
                    case '-':
                        s.push(first_digi-second_digi);
                        break;
                    case '*':
                        s.push(first_digi*second_digi);
                        break;
                    case '/':
                        s.push(first_digi/second_digi);
                        break;
                    case '^':
                        s.push(first_digi^second_digi);
                        break;



                }

            }
        }

        return s.get_top();
    }

    vector<char> infix_to_postfix(string exp) {
        stack<char> s;
        vector<char> output;
        for (int i = 0; i < exp.length(); i++) {
            if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^') {
                if (s.empty()) {
                    s.push(exp[i]);
                }
                else {
                    if (exp[i] == '(') {
                        s.push(exp[i]);

                    }
                    if (exp[i] == ')') {
                        while (s.top() != '(') {
                            output.push_back(s.top());
                            s.pop();
                        }
                        s.pop();
                    }
                    if (s.top() == '*' && exp[i] == '^') {
                        s.push(exp[i]);

                    }
                    else if (s.top() == '*' && exp[i] == '*') {
                        output.push_back(s.top());
                        s.pop();
                        s.push(exp[i]);
                    }
                    else if (s.top() == '*' && exp[i] == '/') {
                        output.push_back(s.top());
                        s.pop();
                        s.push(exp[i]);
                    }
                    else if (s.top() == '*' && exp[i] == '+') {
                        output.push_back(s.top());
                        s.pop();
                        s.push(exp[i]);
                    }
                    else if (s.top() == '*' && exp[i] == '-') {
                        output.push_back(s.top());
                        s.pop();
                        s.push(exp[i]);
                    }

                    else if (s.top() == '/' && exp[i] == '^') {
                            s.push(exp[i]);

                    }
                    else if (s.top() == '/' && exp[i] == '*') {
                            output.push_back(s.top());
                            s.pop();
                            s.push(exp[i]);
                    }
                    else if (s.top() == '/' && exp[i] == '/') {
                            output.push_back(s.top());
                            s.pop();
                            s.push(exp[i]);
                    }
                    else if (s.top() == '/' && exp[i] == '+') {
                            output.push_back(s.top());
                            s.pop();
                            s.push(exp[i]);
                    }
                    else if (s.top() == '/' && exp[i] == '-') {
                            output.push_back(s.top());
                            s.pop();
                            s.push(exp[i]);
                    }

                    else if (s.top() == '^' && exp[i] == '^') {
                        output.push_back(s.top());
                        s.pop();
                        s.push(exp[i]);

                    }
                    else if (s.top() == '^' && exp[i] == '*') {
                        output.push_back(s.top());
                        s.pop();
                        s.push(exp[i]);
                    }
                    else if (s.top() == '^' && exp[i] == '/') {
                        output.push_back(s.top());
                        s.pop();
                        s.push(exp[i]);
                    }
                    else if (s.top() == '^' && exp[i] == '+') {
                        output.push_back(s.top());
                        s.pop();
                        s.push(exp[i]);
                    }
                    else if (s.top() == '^' && exp[i] == '-') {
                        output.push_back(s.top());
                        s.pop();
                        s.push(exp[i]);
                    }

                    else if (s.top() == '+' && exp[i] == '^') {
                        s.push(exp[i]);

                    }
                    else if (s.top() == '+' && exp[i] == '*') {
                        s.push(exp[i]);
                    }
                    else if (s.top() == '+' && exp[i] == '/') {
                        s.push(exp[i]);
                    }
                    else if (s.top() == '+' && exp[i] == '+') {
                        output.push_back(s.top());
                        s.pop();
                        s.push(exp[i]);
                    }
                    else if (s.top() == '+' && exp[i] == '-') {
                        output.push_back(s.top());
                        s.pop();
                        s.push(exp[i]);
                    }

                    else if (s.top() == '-' && exp[i] == '^') {
                        s.push(exp[i]);

                    }
                    else if (s.top() == '-' && exp[i] == '*') {
                        s.push(exp[i]);
                    }
                    else if (s.top() == '-' && exp[i] == '/') {
                        s.push(exp[i]);
                    }
                    else if (s.top() == '-' && exp[i] == '+') {
                        output.push_back(s.top());
                        s.pop();
                        s.push(exp[i]);
                    }
                    else if (s.top() == '-' && exp[i] == '-') {
                        output.push_back(s.top());
                        s.pop();
                        s.push(exp[i]);
                    }




                }

            }
            else {
                output.push_back(exp[i]);
            }
        }

        while (!s.empty()) {
            output.push_back(s.top());
            s.pop();
        }

        return output;

    }
};

int main() {

    Precedence p1;
    int res = p1.postfix("32^3/1+");
    vector<char> result;
    result = p1.infix_to_postfix("3^2/3+1");

    for (char i : result) {
        cout << i;
    }
    cout << endl;
    cout << res << endl;

}
