#include <iostream>
using namespace std;

int main() {
    // Define the array and its size
    const int SIZE = 10;
    int arr[SIZE] = {1, 2, 3, 4, 5, 2, 3, 2, 1, 2};
    int element;

    // Ask the user for the element to search
    cout << "Enter the element to search: ";
    cin >> element;

    // Initialize a counter to keep track of occurrences
    int count = 0;

    // Loop through the array to count occurrences of the element
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == element) {
            count++;
        }
    }

    // Output the result
    cout << "The element " << element << " occurs " << count << " times in the array." << endl;

    return 0;
}
