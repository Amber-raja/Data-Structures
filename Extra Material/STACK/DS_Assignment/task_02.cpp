#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int capacity;
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
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << *(arr + i) << " ";
        }
        cout << endl;
    }
};

bool bracketsMatching(const string &str)
{
    Stack bracketsStack(str.length());

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '[' || ch == '{')
        {
            bracketsStack.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (bracketsStack.isEmpty() ||
                (ch == ')' && bracketsStack.peek() != '(') ||
                (ch == ']' && bracketsStack.peek() != '[') ||
                (ch == '}' && bracketsStack.peek() != '{'))
            {
                return false;
            }
            bracketsStack.pop();
        }
    }

    return bracketsStack.isEmpty();
}

int main()
{
    string str;

    cout << "Enter a string with brackets: ";
    getline(cin, str);

    if (bracketsMatching(str))
    {
        cout << "Brackets matched." << endl;
    }
    else
    {
        cout << "Brackets not Matched." << endl;
    }

    return 0;
}