#include <iostream>
using namespace std;
#include <string>

class Node
{
public:
	string val;
	Node *next;
	Node(string val)
	{
		this->val = val;
		next = NULL;
	}
};
class Stack
{
public:
	Node *top;
	int length;

	Stack()
	{
		top = NULL;
		length = 0;
	}
	~Stack()
	{
		Node *curr = NULL;
		while (top != NULL)
		{
			curr = top;
			top = top->next;
			delete curr;
		}
	}

	bool isEmpty()
	{
		if (top == NULL)
		{
			return true;
			cout << "Stack is empty" << endl;
		}
		else
		{
			return false;
		}
	}

	void push(string val)
	{

		Node *n = new Node(val);
		n->next = top;
		top = n;
		length++;
	}

	string pop()
	{
		if (top == NULL)
		{
			// bool istrue= true;
			cout << "Stack underflow" << endl;
		}
		Node *curr = top;
		string val = curr->val;
		top = top->next;
		delete curr;
		length--;
		return val;
	}
};

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
	bool isFull()
	{
		if (((rear + 1) % size) == front)
		{
			return true;
		}
		else
			return false;
	}

	void enqueue(string val)
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
	}

	string dequeue()
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
			cout << "currently at " << val<< endl;
		}
		else
		{
			return;
		}
	}

	void getFront()
	{
		cout << " " << arr[front] << endl;
	}
};

int main()
{
	int choice;
	// Set up the stack for encounters
	Stack encounters;

	Queue mansionQueue(6);
	mansionQueue.enqueue("The Gateway to Darkness");
	mansionQueue.enqueue("The Creeping Corridor");
	mansionQueue.enqueue("The Abandoned Lounge");
	mansionQueue.enqueue("The Haunted Gallery");
	mansionQueue.enqueue("The Shadowed Library");
	mansionQueue.enqueue("The Broken Window");
	cout << "Start exploring the mansion? " << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cin >> choice;
	if (choice == 1)
	{
		// write the rest of the logic to control the mansion exploration
      mansionQueue.dequeue();
		cout << "Did you encounter a ghost or an evil spirit" << endl;
		cout << "1. yes" << endl;
		cout << "2. no" << endl;
		int enc;
		cin >> enc;
		if (enc == 1)
		{
			cout << "What did you see: " << endl;
			string st;
			cin>>st;
			mansionQueue.enqueue(st);
		}
		cout<<" Yayy, you escaped safe and sound"<<endl;
	}
	else
	{
		cout << "See you next time" << endl;
		return 0;
	}
}