#include <iostream>
using namespace std;

// Constants
const int MAX_SIZE = 100; // Maximum size for the array holding differing elements

// Function to compare two stacks and find differing elements
bool areStacksEqual(int stack1[], int top1, int stack2[], int top2, int diff1[], int diff2[], int& diffCount) {
    // Initialize the index for differing elements
    diffCount = 0;
    bool isEqual = true;

    // Compare elements by popping from both stacks
    while (top1 >= 0 && top2 >= 0) {
        if (stack1[top1] != stack2[top2]) {
            isEqual = false;
            diff1[diffCount] = stack1[top1];
            diff2[diffCount] = stack2[top2];
            diffCount++;
        }
        top1--;
        top2--;
    }

    // If one stack is empty but the other isn't, they differ in size
    while (top1 >= 0) {
        isEqual = false;
        diff1[diffCount] = stack1[top1];
        diff2[diffCount] = -1; // Indicate no corresponding element in stack2
        diffCount++;
        top1--;
    }

    while (top2 >= 0) {
        isEqual = false;
        diff1[diffCount] = -1; // Indicate no corresponding element in stack1
        diff2[diffCount] = stack2[top2];
        diffCount++;
        top2--;
    }

    return isEqual;
}

int main() {
    // Example data for stack1 and stack2
    int stack1[MAX_SIZE] = {1, 2, 3, 4};
    int stack2[MAX_SIZE] = {1, 2, 3, 5};

    // Define tops of the stacks
    int top1 = 3; // Index of the last element in stack1
    int top2 = 3; // Index of the last element in stack2

    // Arrays to store differing elements
    int diff1[MAX_SIZE], diff2[MAX_SIZE];
    int diffCount;

    // Check if stacks are equal and get differing elements if any
    if (areStacksEqual(stack1, top1, stack2, top2, diff1, diff2, diffCount)) {
        cout << "The stacks are equal." << endl;
    } else {
        cout << "The stacks are not equal." << endl;
        cout << "Differing elements:\n";
        for (int i = 0; i < diffCount; i++) {
            cout << "stack1: " << (diff1[i] != -1 ? to_string(diff1[i]) : "None")
                 << " | stack2: " << (diff2[i] != -1 ? to_string(diff2[i]) : "None") << endl;
        }
    }

    return 0;
}
