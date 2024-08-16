#include <iostream>
#include <string>

using namespace std;

// Define the maximum number of employees the stack can hold
#define MAX 100

// Structure to store employee data
struct Employee {
    string name;  // Employee's name
    int id;       // Employee's ID
    float salary; // Employee's salary
};

// Class to represent a stack of employees
class EmployeeStack {
private:
    Employee stack[MAX]; // Array to hold employees
    int top;             // Index of the top employee in the stack

public:
    // Constructor to initialize the stack
    EmployeeStack() : top(-1) {}

    // Check if the stack is full
    bool isFull() {
        return top >= MAX - 1;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top < 0;
    }

    // Add a new employee to the stack
    void push(const Employee& emp) {
        if (isFull()) {
            cout << "The stack is full. Can't add more employees." << endl;
        } else {
            stack[++top] = emp; // Increment top and add employee
            cout << "Added employee: " << emp.name << endl;
        }
    }

    // Remove the top employee from the stack
    void pop() {
        if (isEmpty()) {
            cout << "The stack is empty. Can't remove any employees." << endl;
        } else {
            cout << "Removed employee: " << stack[top].name << endl;
            top--; // Decrement top
        }
    }

    // Show the top employee without removing them
    void peek() {
        if (isEmpty()) {
            cout << "The stack is empty. No employees to show." << endl;
        } else {
            Employee emp = stack[top];
            cout << "Top employee: " << endl;
            cout << "Name: " << emp.name << endl;
            cout << "ID: " << emp.id << endl;
            cout << "Salary: " << emp.salary << endl;
        }
    }

    // Display all employees in the stack
    void print() {
        if (isEmpty()) {
            cout << "The stack is empty. No employees to display." << endl;
        } else {
            cout << "Employees in the stack:" << endl;
            for (int i = top; i >= 0; i--) {
                cout << "Name: " << stack[i].name
                     << ", ID: " << stack[i].id
                     << ", Salary: " << stack[i].salary << endl;
            }
        }
    }
};

// Main function
int main() {
    EmployeeStack empStack; // Create a stack of employees
    int choice; // To store user's choice
    Employee emp; // To store employee data

    do {
        // Show menu options to the user
        cout << "\nStack Operations Menu:" << endl;
        cout << "1. Add (Push) an Employee" << endl;
        cout << "2. Remove (Pop) an Employee" << endl;
        cout << "3. Show Top Employee (Peek)" << endl;
        cout << "4. Show All Employees (Print)" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Input employee details
                cout << "Enter employee name: ";
                cin.ignore(); // Ignore the newline character left by cin
                getline(cin, emp.name); // Read full line for the name
                cout << "Enter employee ID: ";
                cin >> emp.id;
                cout << "Enter employee salary: ";
                cin >> emp.salary;
                empStack.push(emp); // Add the employee to the stack
                break;

            case 2:
                empStack.pop(); // Remove the top employee from the stack
                break;

            case 3:
                empStack.peek(); // Show the top employee
                break;

            case 4:
                empStack.print(); // Show all employees
                break;

            case 5:
                cout << "Exiting the program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5); // Loop until the user chooses to exit

    return 0;
}

