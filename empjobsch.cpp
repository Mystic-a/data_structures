#include <iostream>
using namespace std;

class Employee {
public:
    int id;
    string name;
    int tasks;
    Employee* next;

    Employee(int id, string name, int tasks) {
        this->id = id;
        this->name = name;
        this->tasks = tasks;
        this->next = NULL;
    }
};
void insertEnd(Employee** head, int id, string name, int tasks) {
    Employee* newEmployee = new Employee(id, name, tasks);

    if (*head == NULL) {
        *head = newEmployee;
        newEmployee->next = newEmployee;
    } else {
        Employee* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newEmployee;
        newEmployee->next = *head;
    }
}


void jobScheduling(Employee* head) {
    if (head == NULL) return;

    Employee* current = head;
    int turn = 1;
    while (true) {
        if (current->tasks > 0)
            {
            cout << "Turn " << turn << ": Task of " << current->id << endl;
            current->tasks--;
            turn++;
        if (current->tasks == 0)
        {
                cout << "The task completed first is employee " << current->id << "." << endl;
                break;
            }
        }
        current = current->next;
    }
}


int main() {
    Employee* head = NULL;

    insertEnd(&head, 1, "AAA", 3);
    insertEnd(&head, 2, "BBB", 1);


    jobScheduling(head);

    return 0;
}
