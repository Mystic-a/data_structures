#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* head = nullptr;

// Function to insert an element at the end
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == nullptr) {
        head = newNode;
        head->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Function to display the circular linked list
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

// Function to create a circular linked list from user input
void createListFromInput(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        insertAtEnd(arr[i]);
    }
}

// Function to delete every nth element of the circular linked list until the list becomes empty
void deleteEveryNthElement(int n) {
    if (head == nullptr || n <= 0) return;

    Node* current = head;
    Node* prev = nullptr;

    while (head != nullptr && head->next != head) {
        int count = 1;

        // Find the nth node
        while (count != n) {
            prev = current;
            current = current->next;
            count++;
        }

        // If the node to be deleted is the head node
        if (current == head) {
            prev = head;
            while (prev->next != head) {
                prev = prev->next;
            }
            cout << "Deleted node: " << head->data << endl;
            prev->next = head->next;
            delete head;
            head = prev->next;
            current = head;
        } else {
            // Delete the nth node
            cout << "Deleted node: " << current->data << endl;
            prev->next = current->next;
            delete current;
            current = prev->next;
        }
    }

    // Delete the last remaining node
    if (head != nullptr) {
        cout << "Deleted node: " << head->data << endl;
        delete head;
        head = nullptr;
    }
}

int main() {
    int n, value, deletePos;

    cout << "Enter the number of elements in the list: ";
    cin >> n;
    int* arr = new int[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Create circular linked list from input array
    createListFromInput(arr, n);

    cout << "Enter the position interval to delete: ";
    cin >> deletePos;

    // Delete every nth element and display deleted nodes
    deleteEveryNthElement(deletePos);

    delete[] arr;
    return 0;
}

