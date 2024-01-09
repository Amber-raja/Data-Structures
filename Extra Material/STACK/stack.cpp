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
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.print();

    return 0;
}

1. Write a program that swaps two numbers using a stack. Make use of push and pop
operations.