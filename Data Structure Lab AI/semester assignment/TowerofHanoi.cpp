#include <iostream>

using namespace std;

class Stack {
public:
    int* arr;
    int top;
    int capacity;

    Stack(int size = 0) {
        capacity = size;
        top = -1;
        arr = new int[size];
    }

    ~Stack() {
        delete[] arr;
    }

    bool isFull() {
        return (top == capacity - 1);
    }

    bool isEmpty() {
        return (top == -1);
    }

    void push(int val) {
        if (!isFull()) {
            top++;
            arr[top] = val;
        }
    }

    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return -1;
    }

    int peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return -1;
    }

    void move(Stack& src, Stack& dest, char s, char d) {
        int disk1 = src.peek();
        int disk2 = dest.peek();

        if (disk1 == -1) {
            src.push(dest.pop());
            cout << "Move the disk " << disk2 << " from " << d << " to " << s << endl;
        } else if (disk2 == -1) {
            dest.push(src.pop());
            cout << "Move the disk " << disk1 << " from " << s << " to " << d << endl;
        } else if (disk1 > disk2) {
            src.push(dest.pop());
            cout << "Move the disk " << disk2 << " from " << d << " to " << s << endl;
        } else {
            dest.push(src.pop());
            cout << "Move the disk " << disk1 << " from " << s << " to " << d << endl;
        }
    }

    void iterativeTowerOfHanoi(int n, Stack& src, Stack& aux, Stack& dest) {
        int totalMoves;
        char s = 'S', d = 'D', a = 'A';

        if (n % 2 == 0) {
            char temp = d;
            d = a;
            a = temp;
        }

        totalMoves = (1 << n) - 1;

        for (int i = n; i >= 1; i--) {
            src.push(i);
        }
        int count = 0;
        for (int i = 1; i <= totalMoves; i++) {
            if (i % 3 == 1) {
                move(src, dest, s, d);
            } else if (i % 3 == 2) {
                move(src, aux, s, a);
            } else if (i % 3 == 0) {
                move(aux, dest, a, d);
            }
            count++;
        }

        cout << "Total moves: " << count<< endl;
    }
};

int main() {
    cout << "Enter number of disks: " << endl;
    int numDisks;
    cin >> numDisks;
    Stack s;
    Stack A(numDisks);
    Stack C(numDisks);
    Stack B(numDisks);

    s.iterativeTowerOfHanoi(numDisks, A, B, C);

    return 0;
}