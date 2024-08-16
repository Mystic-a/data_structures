
bool IsOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%');
}


bool IsOperand(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}


int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}


bool eqlOrhigher(char op1, char op2) {
    int p1 = precedence(op1);
    int p2 = precedence(op2);
    if (p1 == p2) {
        if (op1 == '^')
            return false;
        return true;
    }
    return p1 > p2;
}



string convert(string infix) {
    stack<char> S;
    string postfix = "";
    char ch;

    S.push('(');
    infix += ')';
    for (int i = 0; i < infix.length(); i++) {
        ch = infix[i];

        if (ch == ' ')
            continue;
        else if (ch == '(')
            S.push(ch);
        else if (IsOperand(ch))
            postfix += ch;
        else if (IsOperator(ch)) {
            while (!S.empty() && eqlOrhigher(S.top(), ch)) {
                postfix += S.top();
                S.pop();
            }
            S.push(ch);/
        } else if (ch == ')') {
            while (!S.empty() && S.top() != '(') {
                postfix += S.top();
                S.pop();
            }
            S.pop();
        }
    }
    return postfix;
}
