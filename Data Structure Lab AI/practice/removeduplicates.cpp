#include <iostream>

// Define the node structure
struct node {
    int data;
    node* next;
};

// Global variable representing the head of the linked list
node* head = nullptr;
int length = 0; // Assuming you have a variable to keep track of the length of the list

// Function to insert a new node at the beginning of the linked list
void insert(int val) {
    node* newNode = new node{val, head};
    head = newNode;
    length++;
}

// Function to print the linked list
void printList() {
    node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Function to remove duplicate elements from the linked list
void dub() {
    node* curr = head;
    node* temp = nullptr;
    node* prev = nullptr;
    
    while (curr != nullptr) {
        temp = curr->next;
        prev = curr;

        while (temp != nullptr) {
            if (curr->data == temp->data) {
                // Remove the duplicate node
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
                length--;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
}

int main() {
    // Insert some nodes for demonstration
    insert(1);
    insert(2);
    insert(3);
    insert(2);
    insert(4);
    insert(1);

    std::cout << "Original linked list: ";
    printList();

    // Remove duplicates
    dub();

    std::cout << "Linked list after removing duplicates: ";
    printList();

    return 0;
}
