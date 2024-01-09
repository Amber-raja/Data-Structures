#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <stdlib.h>
#include <ctime>
using namespace std;

class Student
{
public:
    string name;
    int merit;
};

class Node
{
public:
    Student data;
    Node *next;
};

class StudentsQueues
{
private:
    int size;
    Node *front;
    Node *rear;

public:
    StudentsQueues() : front(NULL), rear(NULL), size(0) {}
    ~StudentsQueues();

    bool isEmpty();
    bool isFull();
    void enqueue(Student);
    void dequeue();
    Student getFront();
    void display();
    int getSize();
    int getMaxMerit();
};

StudentsQueues::~StudentsQueues()
{
    while (!isEmpty())
    {
        dequeue();
    }
}
bool StudentsQueues::isFull()
{
    return size >= 10;
}
bool StudentsQueues::isEmpty()
{
    return (front == NULL);
}

void StudentsQueues::enqueue(Student student)
{
    if (isFull())
    {
        cout << "Queue is full." << endl;
        return;
    }

    Node *newNode = new Node;
    newNode->data = student;
    newNode->next = NULL;

    if (isEmpty())
    {
        front = newNode;
    }
    else
    {
        rear->next = newNode;
    }

    rear = newNode;
    size++;
}

void StudentsQueues::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Node *temp = front;
    front = front->next;
    delete temp;
    size--;
}

int StudentsQueues::getSize()
{
    return size;
}

Student StudentsQueues::getFront()
{
    return front->data;
}

void StudentsQueues::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Node *temp = front;
    while (temp != NULL)
    {
        cout << "Name: " << temp->data.name << endl;
        cout << "Merit: " << temp->data.merit << endl;
        temp = temp->next;
    }
}

int main()
{
    Student student;
    int size1, size2, size3;
    int queuesNum;
    StudentsQueues Q1, Q2, Q3;

    int choice;
    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Add Students to the StudentsQueues" << endl;
        cout << "2. Process Admissions" << endl;
        cout << "3. Check StudentsQueues Status" << endl;
        cout << "4. See who is next" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the Student Name: ";
            cin >> student.name;
            cout << "Enter the Student Merit: ";
            cin >> student.merit;
            size1 = Q1.getSize();
            size2 = Q2.getSize();
            size3 = Q3.getSize();

            if (size1 <= size2 && size1 <= size3)
            {
                Q1.enqueue(student);
            }
            else if (size2 <= size1 && size2 <= size3)
            {
                Q2.enqueue(student);
            }
            else
            {
                Q3.enqueue(student);
            }

            cout << "Student added to the queue" << endl;
            break;

        case 2:
            while (!Q1.isEmpty() || !Q2.isEmpty() || !Q3.isEmpty())
            {
                if (!Q1.isEmpty())
                {
                    cout << "Processing student from Queue 1: " << Q1.getFront().name << endl;
                    Q1.dequeue();
                }
                if (!Q2.isEmpty())
                {
                    cout << "Processing student from Queue 2: " << Q2.getFront().name << endl;
                    Q2.dequeue();
                }
                if (!Q3.isEmpty())
                {
                    cout << "Processing student from Queue 3: " << Q3.getFront().name << endl;
                    Q3.dequeue();
                }
            }

            cout << "All Admissions are Processed" << endl;
            break;

        case 3:
            cout << "Queue 1: No of Student = " << Q1.getSize() << endl;
            Q1.display();
            cout << endl;

            cout << "Queue 2: No of Student = " << Q2.getSize() << endl;
            Q2.display();
            cout << endl;

            cout << "Queue 3: No of Student = " << Q3.getSize() << endl;
            Q3.display();
            cout << endl;
            break;

        case 4:
            cout << "Enter queue number from 1 to 3: ";
            cin >> queuesNum;

            if (queuesNum == 1 && !Q1.isEmpty())
            {
                cout << "Next student in Queue 1: " << Q1.getFront().name << endl;
            }
            else if (queuesNum == 2 && !Q2.isEmpty())
            {
                cout << "Next student in Queue 2: " << Q2.getFront().name << endl;
            }
            else if (queuesNum == 3 && !Q3.isEmpty())
            {
                cout << "Next student in Queue 3: " << Q3.getFront().name << endl;
            }
            else
            {
                cout << "Queue is empty" << endl;
            }
            break;

        case 5:
            cout << "Exiting program" << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }

        cout << endl;
    }

    return 0;
}