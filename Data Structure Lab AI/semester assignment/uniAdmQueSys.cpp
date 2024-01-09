#include <iostream>
using namespace std;
class student
{
public:
    string name;
    int meritScore;
    student(int ms = 0, string n = " ")
    {
        meritScore = ms;
        name = n;
    }
};

class node
{
public:
    student data;

    node *next;

    node(student val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
public:
    node *head;
    int length;

    Queue()
    {
        head = NULL;
        length = 0;
    }
    ~Queue()
    {
        node *curr = NULL;
        while (head != NULL)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
    void enqueue(student s)
    {
        node *n = new node(s);
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
        length++;
    }

    int dequeue()
    {
        cout << "deque" << endl;
        if (head == NULL)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            int x = head->data.meritScore;
            node *temp = head;
            head = head->next;
            delete temp;
            length--;
            return x;
        }
    }

    void print()
    {
        node *curr = head;

        while (curr != NULL)
        {
            cout << curr->data.name << " ";
            cout << curr->data.meritScore;
            curr = curr->next;
        }
        cout << endl;
    }

    student peak()
    {
        // student s;
        if (length != 0)
        {
            // cout << "Front is: " << head->data << endl;
            return head->data;
        }

        cout << "Queue is empty" << endl;
        return student();
    }
};

int main()
{
    Queue q1;
    Queue q2;
    Queue q3;

    // cout << "Enter your choice: " << endl;
    // int choice;
    // cin >> choice;
    // cout << "Enter 1 to add student to the queue" << endl;
    // cout << "Enter 2 to process admissions" << endl;
    // cout << "Enter 3 to print the queue" << endl;
    // cout << "Enter 4 to see who is next" << endl;
    // cout << "ENter 5 to exit" << endl;

    while (1)
    {
        // cout << "Enter your choice: " << endl;
        // cin >> choice;
        cout << "Enter 1 to add student to the queue" << endl;
        cout << "Enter 2 to process admissions" << endl;
        cout << "Enter 3 to print the queue" << endl;
        cout << "Enter 4 to see who is next" << endl;
        cout << "ENter 5 to exit" << endl;
        cout << "Enter your choice: " << endl;
        int choice;
        cin >> choice;

        // string name;
        //   int meritsc;
        // cout << "Enter name of the student" << endl;
        // cin >> name;
        // cout << "ENter merit score" << endl;
        // cin >> meritsc;

        if (choice == 1)
        {
            // string name;
            // int meritsc;
            cout << "Enter name of the student" << endl;
            string name;
            cin >> name;
            cout << "ENter merit score" << endl;
            int meritsc;
            cin >> meritsc;
            student s(meritsc, name);

            if (q1.length < q2.length && q1.length < q3.length)
            {
                q1.enqueue(s);
            }
            else if (q2.length < q1.length && q2.length < q3.length)
            {
                q2.enqueue(s);
            }
            else if (q3.length < q1.length && q3.length < q2.length)
            {
                q3.enqueue(s);
            }
            else if (q1.length == q2.length && q3.length > q1.length)
            {
                // Enqueue in q1 or q2 (choose one, for simplicity, let's use q1)
                q1.enqueue(s);
            }
            else if (q1.length == q3.length && q2.length > q1.length)
            {
                // Enqueue in q1 or q3 (choose one, for simplicity, let's use q1)
                q1.enqueue(s);
            }
            else if (q2.length == q3.length && q1.length > q2.length)
            {
                // Enqueue in q2 or q3 (choose one, for simplicity, let's use q2)
                q2.enqueue(s);
            }
            else
            {
                // If all queues have the same length, enqueue in any of them (for simplicity, let's use q1)
                q1.enqueue(s);
            }
        }
        // if (choice == 2)
        // {
        //     int m;
        //     if (q2.length != 0 && q2.length < q1.length && q2.length < q3.length)
        //     {

        //         for (int i = 0; i < q2.length; i++)
        //         {
        //             m = q2.dequeue();
        //             if (m >= 50)
        //             {
        //                 cout << " congrats you have secured the admission" << endl;
        //             }
        //             else
        //                 cout << "sorry you couldnt get the admission" << endl;
        //         }
        //     }
        //     else if (q1.length != 0 && q1.length < q2.length && q1.length < q3.length)
        //     {
        //         for (int i = 0; i < q2.length; i++)
        //         {
        //             m = q1.dequeue();
        //             if (m >= 50)
        //             {
        //                 cout << " congrats you have secured the admission" << endl;
        //             }
        //             else
        //                 cout << "sorry you couldnt get the admission" << endl;
        //         }
        //     }
        //     else if (q1.length != 0 && q3.length < q1.length && q3.length < q2.length)
        //     {
        //         for (int i = 0; i < q2.length; i++)
        //         {
        //             m = q3.dequeue();
        //             if (m >= 50)
        //             {
        //                 cout << " congrats you have secured the admission" << endl;
        //             }
        //             else
        //                 cout << "sorry you couldnt get the admission" << endl;
        //         }
        //     }
        else if (choice == 2)
        {
            int m;
            if (q2.length != 0 && q2.length < q1.length && q2.length < q3.length)
            {
                for (int i = 0; i < q2.length; i++)
                {
                    m = q2.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }
            else if (q1.length != 0 && q1.length < q2.length && q1.length < q3.length)
            {
                for (int i = 0; i < q1.length; i++) // Fix: Change to q1.length
                {
                    m = q1.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }
            else if (q3.length != 0 && q3.length < q1.length && q3.length < q2.length)
            {
                for (int i = 0; i < q3.length; i++) 
                {
                    m = q3.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }
            else if (q3.length == 0 && q1.length < q2.length)
            {
                for (int i = 0; i < q1.length; i++) 
                {
                    m = q1.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }

            else if (q1.length == 0 && q2.length < q3.length)
            {
                for (int i = 0; i < q2.length; i++) 
                {
                    m = q1.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }

            else if (q2.length == 0 && q1.length < q3.length)
            {
                for (int i = 0; i < q1.length; i++) 
                {
                    m = q1.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }

            else if (q2.length == 0 && q3.length < q1.length)
            {
                for (int i = 0; i < q1.length; i++) 
                {
                    m = q1.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }

            else if (q2.length == 0 && q3.length == 0)
            {
                for (int i = 0; i < q1.length; i++) 
                {
                    m = q1.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }
            else if (q2.length == 0 && q3.length == 0 && q1.length == 0)
            {
                cout << "all queues are empty";
            }
            else if (q1.length == 0 && q3.length == 0)
            {
                for (int i = 0; i < q2.length; i++) 
                {
                    m = q2.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }

            else if (q1.length == 0 && q2.length == 0)
            {
                for (int i = 0; i < q3.length; i++) 
                {
                    m = q3.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }

            else if (q1.length == q2.length && q2.length == q3.length)
            {
                for (int i = 0; i < q3.length; i++) 
                {
                    m = q3.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }
            else if (q1.length == q2.length && q3.length < q1.length)
            {
                for (int i = 0; i < q3.length; i++) 
                {
                    m = q3.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }

            else if (q1.length == q3.length && q2.length < q1.length)
            {
                for (int i = 0; i < q2.length; i++) 
                {
                    m = q2.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }
            else if (q2.length == q3.length && q1.length < q2.length)
            {
                for (int i = 0; i < q1.length; i++) 
                {
                    m = q1.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }
            else if (q2.length == q3.length && q1.length == 0)
            {
                for (int i = 0; i < q2.length; i++) 
                {
                    m = q2.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }

            else if (q1.length == q3.length && q2.length == 0)
            {
                for (int i = 0; i < q3.length; i++) 
                {
                    m = q3.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }
            else if (q1.length == q2.length && q3.length == 0)
            {
                for (int i = 0; i < q1.length; i++) 
                {
                    m = q1.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }

            else if (q2.length > q3.length && q1.length == 0)
            {
                for (int i = 0; i < q3.length; i++) 
                {
                    m = q3.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }

            else if (q2.length < q3.length && q1.length == 0)
            {
                for (int i = 0; i < q2.length; i++) 
                {
                    m = q2.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }

            else if (q1.length < q3.length && q2.length == 0)
            {
                for (int i = 0; i < q1.length; i++) 
                {
                    m = q1.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }

            else if (q1.length > q3.length && q2.length == 0)
            {
                for (int i = 0; i < q3.length; i++) 
                {
                    m = q3.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }

            else if (q1.length < q2.length && q3.length == 0)
            {
                for (int i = 0; i < q1.length; i++) 
                {
                    m = q1.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }

            else if (q1.length > q2.length && q3.length == 0)
            {
                for (int i = 0; i < q2.length; i++) 
                {
                    m = q2.dequeue();
                    if (m >= 50)
                    {
                        cout << " congrats you have secured the admission" << endl;
                    }
                    else
                        cout << "sorry you couldn't get the admission" << endl;
                }
            }
        }

       else if (choice == 3)
        {
            cout << "Number of students in first queue: " << q1.length << endl;

            cout << "Data in first queue" << endl;
            q1.print();
            cout << "Number of students in second queue: " << q2.length << endl;
            cout << "Data in second queue" << endl;
            q2.print();
            cout << "Number of students in third queue: " << q3.length << endl;
            cout << "Data in third queue" << endl;
            q3.print();
        }
        // if (choice == 4)
        // {
        //     int ch;
        //     cout << " ENter queue number to check for" << endl;
        //     cin >> ch;
        //     if (ch == 1)
        //     {
        //         q1.peak();
        //     }
        //     else if (ch == 2)
        //     {
        //         q2.peak();
        //     }
        //     else if (ch == 3)
        //     {
        //         q3.peak();
        //     }
        // }

        else if (choice == 4)
        {
            int ch;
            cout << "Enter queue number to check for" << endl;
            cin >> ch;
            if (ch == 1)
            {
                student s = q1.peak();
                cout << "Next student in queue 1: " << s.name << " " << s.meritScore << endl;
            }
            else if (ch == 2)
            {
                student s = q2.peak();
                cout << "Next student in queue 2: " << s.name << " " << s.meritScore << endl;
            }
            else if (ch == 3)
            {
                student s = q3.peak();
                cout << "Next student in queue 3: " << s.name << " " << s.meritScore << endl;
            }
        }

        else{
            cout << " Exiting the program" << endl;

            break;
        }
    }
}