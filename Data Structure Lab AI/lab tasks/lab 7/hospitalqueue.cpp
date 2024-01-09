#include <iostream>
using namespace std;

class Queue
{
    int front;
    int rear;
    int size;
    string *arr;

public:
    Queue(int size)
    {
        front = -1;
        rear = -1;
        this->size = size;
        arr = new string[size];
    }
    bool isFull()
    {
        if (((rear + 1) % size) == front)
        {
            return true;
        }
        else
            return false;
    }

    bool isEmpty()
    {
        if (rear == -1 && front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueu(string val)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = val;
        cout << "Patient " << val << "  now waiting in queue" << endl;
    }

    void dequeu()
    {
        string val = arr[front];
        if (!isEmpty())
        {
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % size;
            }
            cout << "Patient " << val << "  now with doctor" << endl;
        }
        else
        {
            cout << "No more patients." << endl;
            return;
        }
    }

   

    string getFront()
    {
        return arr[front];
    }

    void display()
    {
        if (isEmpty())
        {
            return;
        }
        int i = front;
        do
        {
            cout << arr[i] << " " << endl;
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        cout << endl;
    }
};

int main()
{
    int seat;
    string name;
    cout << "Enter number of seat in waiting area:";
    cin >> seat;
    Queue hospital(seat);
    int option;
    do
    {
        cout << "Enter an option: " << endl;
        cout << "1.Enter a patient in waiting queue: " << endl;
        cout << "2.Send next patinet to doctor: " << endl;
        cout << "3.See who's next: " << endl;
        cout << "4. Dsiaply all patients: " << endl;
        cout << "5. Exit" << endl;
        cin >> option;
        if (option == 1)
        {
            cout << "Enter name of patient: ";
            cin >> name;
            hospital.enqueu(name);
        }
        else if (option == 2)
        {
            hospital.dequeu();
        }
        else if (option == 3)
        {
            cout << "Next patient in queue: " << hospital.getFront() << endl;
        }
        else
        {
            hospital.display();
        }

    } while (option != 5);
}