#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;
string infixToPostfix(string& infix) {
    Stack s;
    string Postfix;
    s.makeEmpty();
    for (char a : infix) {
        if (a >= '0' && a <= '9') {
            Postfix += a;
        }
        else {
            if (a == '(') s.push(a);
            else if (a == '*' || a == '/') {
                while (!s.isEmpty() && (s.getTop() == '*' || s.getTop() == '/')) {
                    Postfix += s.getTop();
                    s.pop();
                }
                s.push(a);
            }
            else if (a == '+' || a == '-') {
                while (!s.isEmpty() && s.getTop() != '(') {
                    Postfix += s.getTop();
                    s.pop();
                }
                s.push(a);
            }
            else {
                while (!s.isEmpty() && s.getTop() != '(') {
                    Postfix += s.getTop();
                    s.pop();
                }
                s.pop();
            }
        }
    }
    while (!s.isEmpty()) {
        Postfix += s.getTop();
        s.pop();
    }
    return Postfix;
}

int evaluatePostfix(string& postfix) {
    Stack s;
    char a;
    int n1, n2, result;
    for (int i = 0; i < postfix.length(); i++) {
        a = postfix[i];
        if (a >= '0' && a <= '9') {
            s.push(a - '0');
        }
        else if (a == '+' || a == '-' || a == '*' || a == '/') {
            n2 = s.getTop();
            s.pop();
            n1 = s.getTop();
            s.pop();
            switch (a) {
            case '+':
                result = n1 + n2;
                break;
            case '-':
                result = n1 - n2;
                break;
            case '*':
                result = n1 * n2;
                break;
            case '/':
                if (n2 != 0) {
                    result = n1 / n2;
                }
                else {
                    cout << "Error: Division by zero" << endl;
                    return -1;
                }
                break;
            }
            s.push(result);
        }
    }
    return s.getTop();
}



int main() {
    string infix = "1*(3+5)";
    cout << "Question: " << infix << endl;
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;
    cout << "Evaluation: " << evaluatePostfix(postfix) << "\n\n";
    infix = "5+6";
    cout << "Question: " << infix << endl;
    postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;
    cout << "Evaluation: " << evaluatePostfix(postfix) << "\n\n";
    infix = "4+2*3";
    cout << "Question: " << infix << endl;
    postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;
    cout << "Evaluation: " << evaluatePostfix(postfix) << "\n\n";
    infix = "4+1*5-6/7";
    cout << "Question: " << infix << endl;
    postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;
    cout << "Evaluation: " << evaluatePostfix(postfix) << "\n\n";
}

