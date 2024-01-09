#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    struct Node {
        string data;
        Node* next;
        Node(const string& value) : data(value), next(nullptr) {}
    };

    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(const string& value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    string peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return "";
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack undoStack;
    Stack redoStack;

    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    undoStack.push(input);

    cout << "Undo/Redo functionality using a stack:" << endl;
    cout << "1. Undo" << endl;
    cout << "2. Redo" << endl;
    cout << "3. Exit" << endl;

    int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (undoStack.isEmpty()) {
                cout << "Nothing to undo." << endl;
            } else {
                string undoneString = undoStack.peek();
                undoStack.pop();
                redoStack.push(undoneString);
                cout << "Undone: " << undoneString << endl;
            }
        } else if (choice == 2) {
            if (redoStack.isEmpty()) {
                cout << "Nothing to redo." << endl;
            } else {
                string redoneString = redoStack.peek();
                redoStack.pop();
                undoStack.push(redoneString);
                cout << "Redone: " << redoneString << endl;
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
