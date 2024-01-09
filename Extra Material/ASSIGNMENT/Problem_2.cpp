#include <iostream>
#include <math.h>
#include <string>
#define size 5
using namespace std;

class Stack
{
public:
    int arr[size];
    int top;
    char name;

    Stack(char c) : top(-1), name(c) {}
    int pop();
    void push(int);
    int topElement();
};

void Stack::push(int d)
{
    top++;
    arr[top] = d;
}

int Stack::pop()
{
    int temp = arr[top];
    top--;
    return temp;
}
int Stack::topElement()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return arr[top];
    }
}
void move(Stack &from, Stack &to)
{
    int element = from.pop();
    to.push(element);
    cout << "Disk " << element << " move from peg " << from.name << " to peg " << to.name << endl;
}

void towerOfHanoi(int, Stack &, Stack &, Stack &);
int main()
{
    Stack D1('A');
    Stack D2('B');
    Stack D3('C');
    int discs;
    cout << "Enter Total Number of Discs: ";
    cin >> discs;
    towerOfHanoi(discs, D1, D2, D3);
    cout << "Total number of moves: " << (int)pow(2, discs) - 1 << endl;
    return 0;
}

void towerOfHanoi(int disk, Stack &d1, Stack &d2, Stack &d3)
{
    int totalMoves = pow(2, disk) - 1;

    if (disk % 2 == 0)
    {
        swap(d2.name, d3.name);
    }

    int i = disk;
    while (i >= 1)
    {
        d1.push(i);
        i--;
    }

    int j = 1;

    while (j <= totalMoves)

    {
        if (j % 3 == 1)
        {
            if ((d3.topElement() != -1 && d1.topElement() < d3.topElement()) || d3.topElement() == -1)
            {
                move(d1, d3);
            }
            else
            {
                move(d3, d1);
            }
        }

        else if (j % 3 == 2)
        {
            if ((d1.topElement() != -1 && d1.topElement() < d2.topElement()) || d2.topElement() == -1)
            {
                move(d1, d2);
            }
            else
            {
                move(d2, d1);
            }
        }
        else
        {
            if ((d3.topElement() != -1 && d3.topElement() < d2.topElement()) || d2.topElement() == -1)
            {
                move(d3, d2);
            }
            else
            {
                move(d2, d3);
            }
        }
        j++;
    }
}