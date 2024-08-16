#include <iostream>
using namespace std;

// Define the structure of a node in the doubly linked list
struct Node {
    int data;  // Data stored in the node
    Node* prev; // Pointer to the previous node in the list
    Node* next; // Pointer to the next node in the list

    // Constructor to initialize a node with given data
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Function to insert a node at a specific position in the doubly linked list
void insertAtPosition(Node** head, int position, int data) {
    // Create a new node and allocate memory
    Node* newNode = new Node(data);

    // Insert at the beginning of the list
    if (position == 0) {
        // New node points to the current head
        newNode->next = *head;

        // Previous of new node is null as it's the new head
        newNode->prev = nullptr;

        if (*head != nullptr) {
            // If list is not empty, set the previous of old head to new node
            (*head)->prev = newNode;
        }

        // Update the head to point to the new node
        *head = newNode;
    } else {
        // Pointer to traverse the list
        Node* current = *head;

        // Counter to track the position
        int count = 0;

        // Traverse to the node at position - 1
        while (current != nullptr && count < position - 1) {
            current = current->next; // Move to the next node
            count++; // Increment position counter
        }

        // If reached end of list and position not found
        if (current == nullptr) {
            // Inform user about out of range position
            cout << "Position out of range" << endl;
            delete newNode; // Clean up allocated memory for newNode
            return; // Exit function
        }

        // Insert the new node between current and current->next
        newNode->next = current->next; // New node's next is set to current node's next
        newNode->prev = current; // New node's previous is set to current node

        if (current->next != nullptr) {
            // If there's a node after current, set its previous to new node
            current->next->prev = newNode;
        }

        // Set current node's next to the new node
        current->next = newNode;
    }
}

// Function to delete a node at a specific position in the doubly linked list
void deleteNodeAtPosition(Node** head, int position) {
    if (*head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = *head;

    for (int i = 0; current != nullptr && i < position; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position out of bounds." << endl;
        return;
    }

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    }
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    if (current == *head) {
        *head = current->next;
    }

    delete current; // Deallocate memory for the deleted node
}

// Function to print the doubly linked list from head to tail
void printListForward(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to delete the entire doubly linked list to free memory
void deleteLinkedList(Node** head) {
    Node* current = *head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    *head = nullptr; // Reset head to nullptr
}

int main() {
    Node* head = nullptr;
    int n, data, position;
    char choice;

    // Input number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    // Input elements into the doubly linked list
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> data;
        insertAtPosition(&head, i, data); // Insert at position i
    }

    do {
        cout << "\nChoose operation:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Print Forward\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter the data to insert: ";
                cin >> data;
                cout << "Enter the position to insert: ";
                cin >> position;
                insertAtPosition(&head, position, data);
                break;
            case '2':
                cout << "Enter the position to delete: ";
                cin >> position;
                deleteNodeAtPosition(&head, position);
                break;
            case '3':
                cout << "Current Linked List (Forward): ";
                printListForward(head);
                break;
            case '4':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '4');

    // Delete the entire doubly linked list before exiting
    deleteLinkedList(&head);

    return 0;
}
