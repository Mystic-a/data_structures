#include <iostream>
#include <string>

using namespace std;

// Define the structure of a node in the doubly linked list
struct Node {
    string data;  // Data stored in the node
    Node* prev; // Pointer to the previous node in the list
    Node* next; // Pointer to the next node in the list

    Node(string val) : data(val), prev(nullptr), next(nullptr) {}
};

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(Node*& head, const string& data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

// Function to reverse the doubly linked list
void reverseList(Node*& head) {
    if (head == nullptr) {
        return;
    }

    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        // Swap the next and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node in the original list
        current = current->prev;
    }

    // Adjust the head of the list
    if (temp != nullptr) {
        head = temp->prev;
    }
}

// Function to print the doubly linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Driver code to test the functions
int main() {
    Node* head = nullptr;
    int n;
    string data;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> data;
        insertAtEnd(head, data);
    }

    cout << "Original List: ";
    printList(head);

    reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
