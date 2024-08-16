#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to reverse a string using a stack
string reverseString(const string& str) {
    stack<char> charStack; // Create a stack to hold characters

    // Push all characters of the string onto the stack
    for (char ch : str) {
        charStack.push(ch);
    }

    // Pop characters from the stack and append to result string
    string reversedStr;
    while (!charStack.empty()) {
        reversedStr += charStack.top(); // Get the top character
        charStack.pop(); // Remove the top character
    }

    return reversedStr; // Return the reversed string
}

int main() {
    string str = "GeeksQuiz";
    cout << "Original string: " << str << endl;

    string reversedStr = reverseString(str);
    cout << "Reversed string: " << reversedStr << endl;

    return 0;
}
