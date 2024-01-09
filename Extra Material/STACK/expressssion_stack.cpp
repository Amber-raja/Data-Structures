#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    int maxSize;
    int top;
    char* stackArray;

public:
    Stack(int size) {
        maxSize = size;
        top = -1;
        stackArray = new char[maxSize];
    }

    ~Stack() {
        delete[] stackArray;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == maxSize - 1);
    }

    void push(char value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        stackArray[++top] = value;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
        return stackArray[top--];
    }

    char peek() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return '\0';
        }
        return stackArray[top];
    }
};

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    else
        return -1;
}

string infixToPostfix(string infix) {
    string postfix = "";
    Stack stack(infix.length());

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            stack.push(c);
        }
        else if (c == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
            }
            if (!stack.isEmpty() && stack.peek() != '(') {
                cout << "Invalid Expression!" << endl;
                return "";
            }
            else {
                stack.pop();
            }
        }
        else {
            while (!stack.isEmpty() && precedence(c) <= precedence(stack.peek())) {
                postfix += stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    cin >> infixExpression;

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}
