#include <iostream>
using namespace std;

// Define the node structure
struct node {
    int data;
    node* next;
};

// Global variable representing the head of the linked list
node* head = nullptr;

// Function to insert a new node at the beginning of the linked list
void insert(int val) {
    node* newNode = new node{val, head};
    head = newNode;
}

// Function to print the linked list
void printList() {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to reverse the linked list
void reverse() {
    node* curr = head;
    node* prev = nullptr;
    node* next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main() {
    // Insert some nodes for demonstration
    insert(1);
    insert(3);
    insert(8);
    insert(4);

    cout << "Original linked list: ";
    printList();

    // Reverse the linked list
    reverse();

    cout << "Reversed linked list: ";
    printList();

    return 0;
}
