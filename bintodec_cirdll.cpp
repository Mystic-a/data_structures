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

// Function to convert the binary number in the circular doubly linked list to decimal
int convertBinaryToDecimal() {
    if (head == nullptr) {
        return 0;
    }

    int decimal = 0;
    Node* temp = head;
    do {
        decimal = decimal * 2 + temp->data;
        temp = temp->next;
    } while (temp != head);

    return decimal;
}

int main() {
    int n, value;

    cout << "Enter the number of binary digits: ";
    cin >> n;

    cout << "Enter the binary digits (0 or 1): ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        if (value != 0 && value != 1) {
            cout << "Invalid binary digit. Only 0 or 1 allowed." << endl;
            return 1;
        }
        insertAtEnd(value);
    }

    cout << "Circular Doubly Linked List: ";
    display();

    int decimal = convertBinaryToDecimal();
    cout << "Decimal equivalent: " << decimal << endl;

    return 0;
}
