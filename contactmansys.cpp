#include <iostream>
#include <string>
using namespace std;

class Contact {
public:
    string id;
    string name;
    string phone;
    string email;
    Contact* next;
};

Contact* head = nullptr;

// Function to add a new contact
void addContact(string id, string name, string phone, string email) {
    Contact* newContact = new Contact();
    newContact->id = id;
    newContact->name = name;
    newContact->phone = phone;
    newContact->email = email;

    if (head == nullptr) {
        head = newContact;
        head->next = head;
    } else {
        Contact* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newContact;
        newContact->next = head;
    }

    cout << "Contact added successfully." << endl;
}

// Function to remove a contact by ID
void removeContact(string id) {
    if (head == nullptr) {
        cout << "Contact list is empty." << endl;
        return;
    }

    Contact* temp = head;
    Contact* prev = nullptr;

    // Handle case when the head needs to be removed
    if (head->id == id) {
        if (head->next == head) { // Only one contact in the list
            delete head;
            head = nullptr;
        } else {
            Contact* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = head->next;
            temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Contact removed successfully." << endl;
        return;
    }

    // Find the contact to remove
    do {
        if (temp->next->id == id) {
            Contact* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Contact removed successfully." << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Contact not found." << endl;
}

// Function to update a contact by ID
void updateContact(string id, string name, string phone, string email) {
    if (head == nullptr) {
        cout << "Contact list is empty." << endl;
        return;
    }

    Contact* temp = head;
    do {
        if (temp->id == id) {
            temp->name = name;
            temp->phone = phone;
            temp->email = email;
            cout << "Contact updated successfully." << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Contact not found." << endl;
}

// Function to search for a contact by ID
void searchContact(string id) {
    if (head == nullptr) {
        cout << "Contact list is empty." << endl;
        return;
    }

    Contact* temp = head;
    do {
        if (temp->id == id) {
            cout << "Contact found:" << endl;
            cout << "ID: " << temp->id << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Phone: " << temp->phone << endl;
            cout << "Email: " << temp->email << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Contact not found." << endl;
}

// Function to display all contacts
void displayContacts() {
    if (head == nullptr) {
        cout << "No contacts to display." << endl;
        return;
    }

    Contact* temp = head;
    do {
        cout << "ID: " << temp->id << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Phone: " << temp->phone << endl;
        cout << "Email: " << temp->email << endl;
        cout << "----------------------" << endl;
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int choice;
    string id, name, phone, email;

    do {
        cout << "Contact Management System" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Remove Contact" << endl;
        cout << "3. Update Contact" << endl;
        cout << "4. Search Contact" << endl;
        cout << "5. Display All Contacts" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Phone: ";
                cin >> phone;
                cout << "Enter Email: ";
                cin >> email;
                addContact(id, name, phone, email);
                break;
            case 2:
                cout << "Enter ID to remove: ";
                cin >> id;
                removeContact(id);
                break;
            case 3:
                cout << "Enter ID to update: ";
                cin >> id;
                cout << "Enter new Name: ";
                cin >> name;
                cout << "Enter new Phone: ";
                cin >> phone;
                cout << "Enter new Email: ";
                cin >> email;
                updateContact(id, name, phone, email);
                break;
            case 4:
                cout << "Enter ID to search: ";
                cin >> id;
                searchContact(id);
                break;
            case 5:
                displayContacts();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
