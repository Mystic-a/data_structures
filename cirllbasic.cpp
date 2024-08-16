#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* head = nullptr;

// Function to insert an element at the beginning
void insertAtBeginning(int value) {
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
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

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

// Function to insert an element at the nth position
void insertAtNthPosition(int value, int position) {
    Node* newNode = new Node();
    newNode->data = value;

    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; ++i) {
        temp = temp->next;
    }

    if (temp->next == head) {
        cout << "Position out of range. Inserting at the end." << endl;
        insertAtEnd(value);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
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

int main() {
    int n, value, position, choice;

    cout << "Enter the number of elements in the list: ";
    cin >> n;
    int* arr = new int[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Create circular linked list from input array
    createListFromInput(arr, n);

    while (true) {
        cout << "\nCircular Linked List Operations:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at nth Position\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the beginning: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at the end: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert at: ";
                cin >> position;
                insertAtNthPosition(value, position);
                break;
            case 4:
                cout << "The circular linked list is: ";
                display();
                break;
            case 5:
                delete[] arr;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
