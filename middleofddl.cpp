#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

int findLength(Node* head) {
    int length = 0;
    Node* curr = head;
    while (curr != nullptr) {
        length++;
        curr = curr->next;
    }
    return length;
}

void printMiddle(Node* head) {
    int length = findLength(head);
    Node* curr = head;

    // Move to the middle node
    for (int i = 0; i < (length / 2); i++) {
        curr = curr->next;
    }

    if (length % 2 == 0) {
        // If the length is even, print the middle two nodes
        cout << "Middle of the doubly linked list: " << curr->prev->data << " and " << curr->data << endl;
    } else {
        // If the length is odd, print the middle node
        cout << "Middle of the doubly linked list: " << curr->data << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n < 1) {
        cout << "The list must have at least one node." << endl;
        return 1;
    }

    cout << "Enter the values of the nodes: ";
    int value;
    Node* head = nullptr;
    Node* current = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> value;
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
        }
    }

    printMiddle(head);

    return 0;
}


