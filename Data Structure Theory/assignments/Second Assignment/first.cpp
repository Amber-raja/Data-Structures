#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Stack
{
private:
    int size;  
    int top;   
    char *Arr; 
public:
    Stack(int s)
    {
        size = s;
        top = -1;
        Arr = new char[size];
    }

    ~Stack()
    {
        delete[] Arr;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }

    void push(char value)
    {
        if (isFull())
        {
            cout << "Stack is full" << endl;
            return;
        }
        Arr[++top] = value;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return -1; 
        }
        return Arr[top--];
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return Arr[top];
    }
};

int evalPostFixExp(const string& postfix) {
    Stack op(postfix.length());

    for (char c : postfix) {
        if (isdigit(c)) {
            op.push(c - '0');
        } else if (c != ' ') {
            int op2 = op.pop();
            int op1 = op.pop();

            switch (c) {
                case '+':
                    op.push(op1 + op2);
                    break;
                case '-':
                    op.push(op1 - op2);
                    break;
                case '*':
                    op.push(op1 * op2);
                    break;
                case '/':
                    op.push(op1 / op2);
                    break;
                case '^':
                    op.push(pow(op1, op2));
                    break;
                default:
                    cout << "Invalid operator" << endl;
                    return -1;
            }
        }
    }

    if (op.isEmpty()) {
        cout << "Stack is empty" << endl;
        return 0;
    }

    return op.peek();
}

int main() {
    string postfixExpression = "6 2 3 + - 3 8 2 / + * 2 ^ 3 +";
    int ans = evalPostFixExp(postfixExpression);
    cout << "Answer: " << ans << endl;
    return 0;
}