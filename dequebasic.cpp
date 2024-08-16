#include <iostream>
using namespace std;

// Define the Node structure for the doubly linked list
struct Node {
    int data;
    Node* prev; // Pointer to the previous node
    Node* next; // Pointer to the next node

    // Constructor
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Define the Deque class
class Deque {
private:
    Node* front; // Pointer to the front of the deque
    Node* rear;  // Pointer to the rear of the deque

public:
    // Constructor
    Deque() : front(nullptr), rear(nullptr) {}

    // Destructor
    ~Deque() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Check if the deque is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Insert item x at the front end of the deque
    void push(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        cout << x << " pushed to front of deque.\n";
    }

    // Remove and return the front item from the deque
    int pop() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot pop.\n";
            return -1; // Indicating an error (as an example)
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        if (front != nullptr) {
            front->prev = nullptr;
        } else {
            rear = nullptr; // If the deque becomes empty
        }
        delete temp;
        cout << value << " popped from front of deque.\n";
        return value;
    }

    // Insert item x at the rear end of the deque
    void inject(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        cout << x << " injected to rear of deque.\n";
    }

    // Remove and return the rear item from the deque
    int eject() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot eject.\n";
            return -1; // Indicating an error (as an example)
        }
        int value = rear->data;
        Node* temp = rear;
        rear = rear->prev;
        if (rear != nullptr) {
            rear->next = nullptr;
        } else {
            front = nullptr; // If the deque becomes empty
        }
        delete temp;
        cout << value << " ejected from rear of deque.\n";
        return value;
    }
};

int main() {
    Deque dq;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push to front\n";
        cout << "2. Pop from front\n";
        cout << "3. Inject to rear\n";
        cout << "4. Eject from rear\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            dq.push(value);
            break;
        case 2:
            dq.pop();
            break;
        case 3:
            cout << "Enter value to inject: ";
            cin >> value;
            dq.inject(value);
            break;
        case 4:
            dq.eject();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}

