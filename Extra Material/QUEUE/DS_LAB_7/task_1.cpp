#include <iostream>
#include <string>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int capacity;
    int length;
    string *arr;

public:
    Queue(int size)
    {
        this->capacity = size;
        arr = new string[size];
        front = 0;
        rear = 0;
        length = 0;
    }

    bool isFull()
    {
        return ((rear + 1) % capacity == front);
    }

    bool isEmpty()
    {
        return (front == rear);
    }

    void enqueue(string value)
    {
        if (isFull())
        {
            cout << "\nQueue is Full\n";
            return;
        }

        *(arr + rear) = value;

        if (rear == capacity - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        cout << "Patient " << value << " now waiting in the queue.\n";
        length++;
    }

    string dequeue()
    {
        if (isEmpty())
        {
            cout << "\nQueue is Empty\n";
            return "";
        }

        string str = *(arr + front);
        front = (front + 1) % capacity;
        length--;
        return str;
    }

    string peek()
    {
        if (isEmpty())
        {
            cout << "\nQueue is Empty\n";
            return "";
        }
        return *(arr + front);
    }

    void displayQueue()
    {

        if (isEmpty())
        {
            cout << "\nNo more patients.\n";
            return;
        }
        cout << "\nPatients in queue are: \n";

        for (int i = front; i != rear; i = (i + 1) % capacity)
        {
            cout << *(arr + i) << " ";
        }
        cout << endl;
    }
};

void menu()
{
    cout << endl
         << "***************************" << endl;
    cout << "\tMenu" << endl;
    cout << "***************************" << endl;
    cout << "1. Enter a patient in waiting queue." << endl;
    cout << "2. Send next patient to the doctor." << endl;
    cout << "3. See who's next." << endl;
    cout << "4. Display all patients in the queue." << endl;
    cout << "5. Exit." << endl;
    cout << "------------------------------------------------" << endl;
}
int main()
{
    int queue;
    string name;

    cout << "Enter the number of seats in the waiting area: ";
    cin >> queue;
    cin.ignore();

    Queue q(queue + 1);
    while (true)
    {

        int choice;
        menu();
        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            if (!q.isFull())
            {
                cout << "Enter the name of the patient: ";
                getline(cin, name);
                q.enqueue(name);
            }
            else
            {
                cout << "The Queue is full.\n";
            }
            break;
        case 2:
            if (!q.isEmpty())
            {
                cout << "\nPatient " << q.dequeue() << " now with the doctor.\n";
            }
            else
            {
                cout << "No more patients.\n";
            }
            break;
        case 3:
            if (!q.isEmpty())
            {
                cout << "Next Patient in queue: " << q.peek() << "\n";
            }
            else
            {
                cout << "No more patients.\n";
            }
            break;
        case 4:
            q.displayQueue();
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice. Please enter a correct option.\n";
        }
    }
    return 0;
}
