#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(const string& expression) {
    stack<int> S;

    for (char c : expression) {
        // Skip spaces
        if (c == ' ') continue;

        // If the character is a digit, push it onto the stack
        if (isdigit(c)) {
            S.push(c - '0'); // Convert char digit to integer and push
        }
        // If the character is an operator, pop two values from the stack and apply the operator
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int operand2 = S.top(); S.pop();
            int operand1 = S.top(); S.pop();
            switch (c) {
                case '+': S.push(operand1 + operand2); break;
                case '-': S.push(operand1 - operand2); break;
                case '*': S.push(operand1 * operand2); break;
                case '/': S.push(operand1 / operand2); break;
            }
        }
        // Ignore any other characters
    }

    return S.top(); // Return the result from the stack
}

int main() {
    string postfix_expression;

    cout << "Enter a postfix expression (e.g., '23 4 * 5 +'): ";
    getline(cin, postfix_expression);

    int result = evaluatePostfix(postfix_expression);
    cout << "The result of the postfix expression is: " << result << endl;

    return 0;
}
