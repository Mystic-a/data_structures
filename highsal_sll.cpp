#include <iostream>
#include <string>

using namespace std;

// Define the structure of a node in the singly linked list
struct Node {
    int id;           // Employee ID
    string name;      // Employee name
    double salary;    // Employee salary
    Node* next;       // Pointer to the next node in the list

    Node(int empId, const string& empName, double empSalary)
        : id(empId), name(empName), salary(empSalary), next(nullptr) {}
};

// Function to insert a new node at the end of the singly linked list
void insertAtEnd(Node*& head, int id, const string& name, double salary) {
    Node* newNode = new Node(id, name, salary);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
}

// Function to find the employee with the highest salary
Node* findHighestSalary(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* highest = head;
    Node* current = head->next;

    while (current != nullptr) {
        if (current->salary > highest->salary) {
            highest = current;
        }
        current = current->next;
    }

    return highest;
}

// Function to print the details of a single employee
void printEmployee(const Node* employee) {
    if (employee != nullptr) {
        cout << "ID: " << employee->id << ", Name: " << employee->name << ", Salary: " << employee->salary << endl;
    }
}

// Function to print all employees in the list
void printList(Node* head) {
    while (head != nullptr) {
        printEmployee(head);
        head = head->next;
    }
}

// Driver code to test the functions
int main() {
    Node* head = nullptr;
    int n, id;
    string name;
    double salary;

    cout << "Enter the number of employees: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter details of employee " << (i + 1) << " (ID, Name, Salary): ";
        cin >> id;
        cin.ignore(); // To ignore the newline character left in the buffer
        getline(cin, name);
        cin >> salary;
        insertAtEnd(head, id, name, salary);
    }

    cout << "\nEmployee List:" << endl;
    printList(head);

    Node* highestSalaryEmployee = findHighestSalary(head);
    if (highestSalaryEmployee != nullptr) {
        cout << "\nEmployee with the highest salary:" << endl;
        printEmployee(highestSalaryEmployee);
    } else {
        cout << "\nNo employees in the list." << endl;
    }

    return 0;
}
