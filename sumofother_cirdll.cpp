#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

// Function to insert a node at the end of the circular doubly linked list
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
    }
}

// Function to display the circular doubly linked list
void display() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Function to modify each node to contain the sum of all nodes except itself
void modifyNodes() {
    if (head == nullptr) {
        return;
    }

    // Step 1: Calculate the total sum of all nodes
    int totalSum = 0;
    Node* temp = head;
    do {
        totalSum += temp->data;
        temp = temp->next;
    } while (temp != head);

    // Step 2: Update each node with the total sum minus the node's current value
    temp = head;
    do {
        temp->data = totalSum - temp->data;
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n, value;

    cout << "Enter the number of elements in the list: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        insertAtEnd(value);
    }

    cout << "Original Circular Doubly Linked List: ";
    display();

    modifyNodes();

    cout << "Modified Circular Doubly Linked List: ";
    display();

    return 0;
}
