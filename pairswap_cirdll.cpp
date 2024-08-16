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

// Function to pairwise swap elements in the circular doubly linked list
void pairwiseSwap() {
    if (head == nullptr || head->next == head) {
        return;
    }

    Node* temp = head;
    do {
        // Swap data of temp and temp->next
        int tempData = temp->data;
        temp->data = temp->next->data;
        temp->next->data = tempData;

        // Move temp by two nodes
        temp = temp->next->next;
    } while (temp != head && temp->next != head);
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

    pairwiseSwap();

    cout << "List after Pairwise Swap: ";
    display();

    return 0;
}
