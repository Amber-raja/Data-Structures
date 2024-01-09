#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

class Node
{
public:
    int data;    // void enqueue(int value)
    // {

    //     Node *newNode;
    //     Node *rear;
    //     rear = head;
    //     newNode = new Node(value);
    //     if (head == NULL)
    //     {
    //         head = newNode;
    //         newNode->next = NULL;
    //     }
    //     else
    //     {
    //         rear->next = newNode;
    //         rear = rear->next;
    //         rear = NULL;
    //     }
    //     length++;
    // }
    Node *next;    // void enqueue(int value)
    // {

    //     Node *newNode;
    //     Node *rear;
    //     rear = head;
    //     newNode = new Node(value);
    //     if (head == NULL)
    //     {
    //         head = newNode;
    //         newNode->next = NULL;
    //     }
    //     else
    //     {
    //         rear->next = newNode;
    //         rear = rear->next;
    //         rear = NULL;
    //     }
    //     length++;
    // }
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Queue
{

private:
    Node *head;
    int length = 0;

public:
    Queue()
    {
        head = NULL;
    }

    void enqueue(int value)
    {

        Node *newNode;
        Node *rear;
        rear = head;
        newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = rear->next;
        }
        length++;
    }

    void print()
    {
        Node *curr;
        curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
};

int main()
{
    Queue q1;
    q1.enqueue(11);
    q1.enqueue(12);
    q1.enqueue(13);
    q1.enqueue(14);
    q1.print();

    return 0;
}