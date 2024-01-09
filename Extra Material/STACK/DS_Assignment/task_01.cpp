#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

class Stack
{
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        top = -1;
    }

    void push(int value)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        *(arr + top) = value;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int value = *(arr + top);
        top--;
        return value;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return *(arr + top);
    }

    bool is_empty()
    {
        return top == -1;
    }

    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << *(arr + i) << " ";
        }
        cout << endl;
    }

    int evaluatePostfix(string expression)
    {
        for (int i = 0; i < expression.length(); i++)
        {
            if (expression[i] >= '0' && expression[i] <= '9')
            {
                push(expression[i] - '0');
            }
            else if (expression[i] == ' ')
            {
                continue;
            }
            else
            {
                int op2 = pop();
                int op1 = pop();

                switch (expression[i])
                {

                case '/':
                    if (op2 != 0)
                    {
                        push(op1 / op2);
                    }
                    else
                    {
                        cout << "ERROR::Undefined." << endl;
                        return -1;
                    }
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '+':
                    push(op1 + op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;

                case '^':
                    push(pow(op1, op2));
                    break;
                default:
                    cout << "ERROR:: Invalid operator" << endl;
                    return -1;
                }
            }
        }
        return peek();
    }
};

int main()
{
    int temp = 0;
    string sample = "8 2 5 + * 6 3 ^ / 9 3 - +";
    Stack stack(sample.length());
    cout << "Length: " << sample.length() << endl;
    temp = stack.evaluatePostfix(sample);
    if (temp != -1)
    {
        cout << "Result: " << temp << endl;
    }
    return 0;
}