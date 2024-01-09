#include <iostream>
#include <cstring>

using naqmespace std;
class Stack {
private:
    static const int MAX_SIZE = 100;
    char data[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(char c) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        data[++top] = c;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
        return data[top--];
    }
};

void reverseString(char* str) {
    int len = strlen(str);
    Stack stack;
    for (int i = 0; i < len; i++) {
        stack.push(str[i]);
    }
    for (int i = 0; i < len; i++) {
        str[i] = stack.pop();
    }
}

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);
    reverseString(str);
    cout << "Reversed string: " << str << endl;
    return 0;
}
