#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    double salary;
};

void bubbleSort(Employee arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].salary > arr[j+1].salary) {
                // Swap arr[j] and arr[j+1]
                Employee temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printEmployees(Employee arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Name: " << arr[i].name << ", Salary: " << arr[i].salary << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee* employees = new Employee[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter name for employee " << i+1 << ": ";
        cin >> employees[i].name;
        cout << "Enter salary for employee " << i+1 << ": ";
        cin >> employees[i].salary;
    }

    bubbleSort(employees, n);

    cout << "\nEmployees sorted by salary in ascending order:\n";
    printEmployees(employees, n);


    return 0;
}
