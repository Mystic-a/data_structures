#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if a character is an opening parenthesis
bool isOpening(char c) {
    return c == '{' || c == '[' || c == '(';
}

// Function to check if a character is a closing parenthesis
bool isClosing(char c) {
    return c == '}' || c == ']' || c == ')';
}

// Function to check if two parentheses are of the same type
bool isMatching(char open, char close) {
    return (open == '{' && close == '}') ||
           (open == '[' && close == ']') ||
           (open == '(' && close == ')');
}

// Function to check if the parentheses in the expression are balanced
bool isBalanced(const string& expression) { //Takes parameter, 'expression', which is a constant reference to a string.
    stack<char> s;

    for (char c : expression) { //c of type char that will be used to represent each character in the expression string as the loop iterates.
        if (isOpening(c)) {
            s.push(c);
        } else if (isClosing(c)) {
            if (s.empty() || !isMatching(s.top(), c)) {
                return false;
            }
            s.pop();
        }
    }

    // If stack is empty, all parentheses were matched
    return s.empty();
}

int main() {
    string expression1 = "{a+b} – {c-d}";
    string expression2 = "{a+b} – c-d}";
    string expression3 = "{a+b} – }c-d{";

    cout << "Expression 1: " << (isBalanced(expression1) ? "Balanced" : "Unbalanced") << endl;
    cout << "Expression 2: " << (isBalanced(expression2) ? "Balanced" : "Unbalanced") << endl;
    cout << "Expression 3: " << (isBalanced(expression3) ? "Balanced" : "Unbalanced") << endl;

    return 0;
}
