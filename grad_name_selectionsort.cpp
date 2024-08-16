#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    double grade;
};

void selectionSortByName(Student students[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (students[j].name < students[minIndex].name) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        Student temp = students[i];
        students[i] = students[minIndex];
        students[minIndex] = temp;
    }
}

void selectionSortByGrade(Student students[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (students[j].grade < students[minIndex].grade) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        Student temp = students[i];
        students[i] = students[minIndex];
        students[minIndex] = temp;
    }
}

void printStudents(Student students[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Name: " << students[i].name << ", Grade: " << students[i].grade << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student* students = new Student[n];
    for (int i = 0; i < n; ++i) {
        cout << "Enter name for student " << i + 1 << ": ";
        cin >> students[i].name;
        cout << "Enter grade for student " << i + 1 << ": ";
        cin >> students[i].grade;
    }

    int choice;
    cout << "Sort by: 1. Name  2. Grade\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        selectionSortByName(students, n);
    } else if (choice == 2) {
        selectionSortByGrade(students, n);
    } else {
        cout << "Invalid choice!";
        delete[] students;
        return 1;
    }

    cout << "\nStudents sorted by ";
    cout << (choice == 1 ? "name:\n" : "grade:\n");
    printStudents(students, n);

    delete[] students;
    return 0;
}
