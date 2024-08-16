#include <iostream>
#include <string>

using namespace std;

// Structure to store student data
struct Student {
    string name;
    int rollNumber;
    char grade;
    Student* next; // Pointer to the next student in the stack
};

// Class to implement a stack using a linked list
class StudentStack {
private:
    Student* top; // Pointer to the top of the stack

public:
    // Constructor to initialize the stack
    StudentStack() : top(nullptr) {}

    // Destructor to clean up the stack
    ~StudentStack() {
        while (!isEmpty()) {
            pop(); // Clean up all nodes
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Push a new student onto the stack
    void push(const string& name, int rollNumber, char grade) {
        // Create a new student node
        Student* newStudent = new Student;
        newStudent->name = name;
        newStudent->rollNumber = rollNumber;
        newStudent->grade = grade;
        newStudent->next = top; // Point to the current top
        top = newStudent; // Update the top to the new student
        cout << "Student " << name << " added to the stack." << endl;
    }

    // Pop the top student from the stack
    void pop() {
        if (isEmpty()) {
            cout << "The stack is empty. No students to remove." << endl;
        } else {
            Student* temp = top; // Temporary pointer to the top student
            top = top->next; // Move top to the next student
            cout << "Student " << temp->name << " removed from the stack." << endl;
            delete temp; // Delete the old top student
        }
    }

    // Peek at the top student without removing them
    void peek() {
        if (isEmpty()) {
            cout << "The stack is empty. No students to show." << endl;
        } else {
            cout << "Top student: " << endl;
            cout << "Name: " << top->name << endl;
            cout << "Roll Number: " << top->rollNumber << endl;
            cout << "Grade: " << top->grade << endl;
        }
    }

    // Print all students in the stack
    void print() {
        if (isEmpty()) {
            cout << "The stack is empty. No students to display." << endl;
        } else {
            cout << "Students in the stack:" << endl;
            Student* current = top; // Start from the top of the stack
            while (current != nullptr) {
                cout << "Name: " << current->name
                     << ", Roll Number: " << current->rollNumber
                     << ", Grade: " << current->grade << endl;
                current = current->next; // Move to the next student
            }
        }
    }
};

// Main function
int main() {
    StudentStack studentStack; // Create a stack for students
    int choice;
    string name;
    int rollNumber;
    char grade;

    do {
        // Display the menu for stack operations
        cout << "\nStack Operations Menu:" << endl;
        cout << "1. Add (Push) a Student" << endl;
        cout << "2. Remove (Pop) a Student" << endl;
        cout << "3. Show Top Student (Peek)" << endl;
        cout << "4. Show All Students (Print)" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Input student details
                cout << "Enter student name: ";
                cin.ignore(); // Ignore the newline character left by cin
                getline(cin, name);
                cout << "Enter student roll number: ";
                cin >> rollNumber;
                cout << "Enter student grade (A/B/C/etc.): ";
                cin >> grade;
                studentStack.push(name, rollNumber, grade); // Push the student onto the stack
                break;

            case 2:
                studentStack.pop(); // Pop the top student from the stack
                break;

            case 3:
                studentStack.peek(); // Show the top student
                break;

            case 4:
                studentStack.print(); // Show all students in the stack
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

