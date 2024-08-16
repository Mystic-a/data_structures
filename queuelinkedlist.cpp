#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node

    Node(int value) : data(value), next(nullptr) {}
};

// Define the Queue class
class Queue {
private:
    Node* front;    // Pointer to the front of the queue
    Node* rear;     // Pointer to the rear of the queue

public:
    // Constructor
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Add an element to the rear of the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued into queue.\n";
    }

    // Remove and return the element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return -1; // Indicating an error (as an example)
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        cout << value << " dequeued from queue.\n";
        return value;
    }

    // Display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Main function to test the Queue
int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\nQueue Operations Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

