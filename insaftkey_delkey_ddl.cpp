#include <iostream>
using namespace std;

// Define the structure of a node in the doubly linked list
struct Node {
    int data;  // Data stored in the node
    Node* prev; // Pointer to the previous node in the list
    Node* next; // Pointer to the next node in the list

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Function to insert a node after a specific key in the doubly linked list
void insertAfterKey(Node*& head, int key, int data) {
    Node* current = head;

    // Traverse the list to find the key
    while (current != nullptr && current->data != key) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Key not found." << endl;
        return;
    }

    // Create a new node
    Node* newNode = new Node(data);

    // Adjust pointers to insert the new node
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

// Function to delete a node with a specific key in the doubly linked list
void deleteNodeWithKey(Node*& head, int key) {
    Node* current = head;

    // Traverse the list to find the key
    while (current != nullptr && current->data != key) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Key not found." << endl;
        return;
    }

    // Adjust pointers to remove the node
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    delete current;
}

// Function to print the doubly linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver code to test the insertion and deletion functions
int main() {
    Node* head = nullptr;

    int n, data;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> data;
        insertAfterKey(head, i == 0 ? -1 : data, data); // Insert at end
    }

    char choice;
    int key;
    do {
        cout << "\nChoose operation:\n";
        cout << "1. Insert After Key\n";
        cout << "2. Delete Key\n";
        cout << "3. Print List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter the key after which to insert: ";
                cin >> key;
                cout << "Enter the data to insert: ";
                cin >> data;
                insertAfterKey(head, key, data);
                break;
            case '2':
                cout << "Enter the key to delete: ";
                cin >> key;
                deleteNodeWithKey(head, key);
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
