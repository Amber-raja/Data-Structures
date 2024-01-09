#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class DoubleLinkedList
{
    int length;
    Node *head;

public:
    DoubleLinkedList()
    {
        head = NULL;
        length = 0;
    }

    void insert(int pos, int value)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        Node *newNode = new Node(value);

        if (pos == 1)
        {

            newNode->next = head;
            if (head != NULL)
            {
                head->prev = newNode;
            }

            head = newNode;
        }
        else
        {
            Node *curr = head;
            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }

            newNode->prev = curr;
            newNode->next = curr->next;

            if (curr->next != NULL)
            {
                curr->next->prev = newNode;
            }
            curr->next = newNode;
        }
        length++;
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

    void reverse()
    {

        Node *curr = head;
        Node *temp = NULL;

        while (curr != NULL)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        if (temp != NULL)
            head = temp->prev;
    }

    void removeDuplicates()
    {
        Node *curr = head;
        Node *temp = nullptr;
        Node *duplicate = nullptr;

        while (curr && curr->next)
        {

            temp = curr;
            while (temp->next)
            {

                if (curr->data == temp->next->data)
                {
                    duplicate = temp->next;
                    temp->next = temp->next->next;
                    delete (duplicate);
                    length--;
                }
                else // This is tricky: only advance if no deletion
                    temp = temp->next;
            }
            curr = curr->next;
        }
    }
};

int main()
{

    DoubleLinkedList l1;
    l1.insert(1, 100);
    l1.insert(2, 200);
    l1.insert(3, 300);
    l1.insert(1, 200);
    l1.insert(2, 400);
    l1.insert(3, 300);
    l1.insert(4, 400);
    l1.insert(5, 500);
    l1.insert(6, 600);
    l1.print();
    l1.reverse();
    l1.print();
    l1.removeDuplicates();
    l1.print();

    return 0;
}