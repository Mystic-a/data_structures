#include <iostream>
using namespace std;

int main() {
    int n;

    // Input the number of elements
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Declare an array of size n
    int arr[n];

    // Input the elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int uniqueCount = 0;

    // Iterate through the array to count unique elements
    for (int i = 0; i < n; ++i) {
        bool isUnique = true;
        for (int j = 0; j < i; ++j) {  // Iterate only up to i (not including i)
            if (arr[i] == arr[j]) {
                isUnique = false;
                break;  // Exit the loop early if a duplicate is found
            }
        }
        if (isUnique) {
            ++uniqueCount;
        }
    }

    // Output the number of unique elements
    cout << "The number of unique elements in the array is: " << uniqueCount << endl;
    return 0;
}

