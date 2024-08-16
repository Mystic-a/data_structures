#include <iostream>
using namespace std;

// Definition of the singly linked list node
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at a specific position
void insert(Node*& head, int data, int position) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (position < 0) {
        cout << "Invalid position. Position should be non-negative." << endl;
        delete newNode;
        return;
    }

    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    for (int i = 0; current != nullptr && i < position - 1; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position out of bounds." << endl;
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete a node at a specific position
void deleteNode(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    if (position < 0) {
        cout << "Invalid position. Position should be non-negative." << endl;
        return;
    }

    Node* current = head;

    if (position == 0) {
        head = current->next;
        delete current;
        return;
    }

    for (int i = 0; current != nullptr && i < position - 1; ++i) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Position out of bounds." << endl;
        return;
    }

    Node* nodeToDelete = current->next;
    current->next = current->next->next;
    delete nodeToDelete;
}

// Function to print the linked list
void printList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        cout << current->data << "  ";
        current = current->next;
    }
    cout << "NULL" << endl;
}




int main() {
    Node* head = nullptr;
    int n, data, position;
    char choice;

    // Input number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    // Input elements into the linked list
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> data;
        insert(head, data, i); // Insert at position i
    }

    do {
        cout << "\nChoose operation:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Print\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter the data to insert: ";
                cin >> data;
                cout << "Enter the position to insert: ";
                cin >> position;
                insert(head, data, position);
                break;
            case '2':
                cout << "Enter the position to delete: ";
                cin >> position;
                deleteNode(head, position);
                break;
            case '3':
                cout << "Current Linked List: ";
                printList(head);
                break;
            case '4':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '4');



    return 0;
}

