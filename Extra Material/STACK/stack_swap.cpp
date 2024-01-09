#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Stack
{
private:
    Node *head;
    int length;

public:
    Stack()
    {
        head = NULL;
        length = 0;
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        length++;
    }

    int pop()
    {
        if (length == 0)
        {
            cout << "Stack is empty, can't pop." << endl;
            return 0;
        }

        int value = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        length--;
        return value;
    }

    void print()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

void swapNumbers(Stack &s, int &a, int &b)
{
    Stack tempStack;
    int temp;

    // Pop elements from stack and push them into tempStack
    while (s.pop() != a)
    {
        tempStack.push(s.pop());
    }

    // Swap a with b
    a = s.pop();
    s.push(b);

    // Push back the elements from tempStack to original stack
    while (tempStack.pop() != 0)
    {
        s.push(tempStack.pop());
    }

    // Swap b with a
    b = s.pop();
    s.push(a);
}

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();

    int a = 3;
    int b = 5;

    swapNumbers(s, a, b);

    s.print();

    return 0;

}


