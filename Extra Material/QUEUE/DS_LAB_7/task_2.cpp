#include <iostream>

using namespace std;

class Visitor
{
public:
    string name;
    int attraction;
    Visitor *next;

    Visitor(string n, int a)
    {
        name = n;
        attraction = a;
        
        next = NULL;
    }
};

class Queue
{
private:
    Visitor *head;
    Visitor *tail;
    int length;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    void Enqueue(string name, int a)
    {
        Visitor *n = new Visitor(name, a);
        if (length > 0)
        {
            tail->next = n;
            tail = n;
        }
        else
        {
            head = n;
            tail = n;
        }
        length++;
    }

    Visitor *Dequeue()
    {
        if (length > 0)
        {
            Visitor *temp = head;
            head = head->next;
            length--;
            return temp;
        }
        else
        {
            cout << "No more visitors in the queue\n";
            return NULL;
        }
    }

    bool isEmpty()
    {
        return length == 0;
    }
};

int main()
{
    string attractions[3] = {"Roller Coaster", "Motion Ride", "Round Wheel"};
    int size = 5;
    Queue ticketQueue;
    Queue attractionQueue[size];

    while (true)
    {
        cout << "Menu\n";
        cout << "1. Enter a visitor in tickets purchase queue.\n";
        cout << "2. Sell a ticket.\n";
        cout << "3. Process all queues.\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            string visitorName;
            cout << "Enter the visitor's name: ";
            cin >> visitorName;
            ticketQueue.Enqueue(visitorName, 0);
            cout << endl;
        }
        else if (choice == 2)
        {
            if (!ticketQueue.isEmpty())
            {
                Visitor *visitor = ticketQueue.Dequeue();
                cout << "Now selling ticket to: " << visitor->name << "...\n";
                cout << "1. Roller Coaster\n";
                cout << "2. Motion Ride\n";
                cout << "3. Round Wheel\n";
                cout << "Which attraction's ticket " << visitor->name << " wants?: ";
                int a;
                cin >> a;
                visitor->attraction = a;
                attractionQueue[a - 1].Enqueue(visitor->name, a);
                cout << endl;
            }
        }
        else if (choice == 3)
        {
            for (int i = 0; i < size; i++)
            {

                while (!attractionQueue[i].isEmpty())
                {
                    Visitor *visitor = attractionQueue[i].Dequeue();
                    cout << "Visitor " << visitor->name << " now enjoying " << attractions[visitor->attraction - 1] << "\n";
                    delete visitor;
                }
            }
        }
    }

    return 0;
}
