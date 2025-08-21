#include <iostream>
#include <map>
#include <stdexcept>
#include <cmath>
#include "Stack_LinkedList.h"

using namespace std;

#define pl(a) cout << a << endl

// set precedence
int getPrecedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// check if char is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%');
}

// check if char is operand
bool isOperand(char c) {
    return isalnum(c);
}

// apply operators
double applyOp(double val1, double val2, char op) {
    switch (op) {
        case '+': return val1 + val2;
        case '-': return val1 - val2;
        case '*': return val1 * val2;
        case '/':
            if (val2 == 0) throw runtime_error("Division by zero!");
            return val1 / val2;
        case '^': return pow(val1, val2);
        case '%': return static_cast<int>(val1) % static_cast<int>(val2);
        default: throw runtime_error("Unknown operator.");
    }
}

// function to convert infix to postfix
string infixToPostfix(const string& infix) {
    string postfix = "";
    Stack_LinkedList<char> s;

    for (char c : infix) {
        if (isOperand(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            if (!s.isEmpty() && s.peek() == '(') {
                s.pop();
            } else {
                throw runtime_error("Mismatched parentheses in infix expression.");
            }
        } else if (isOperator(c)) {
            while (!s.isEmpty() && getPrecedence(s.peek()) >= getPrecedence(c)) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty()) {
        if (s.peek() == '(') {
            throw runtime_error("Mismatched parentheses in infix expression.");
        }
        postfix += s.pop();
    }
    return postfix;
}

// conversion from prefix to infnix
string prefixToInfix(const string& prefix) {
    Stack_LinkedList<string> s;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isOperand(c)) {
            s.push(string(1, c));
        } else if (isOperator(c)) {
            if (s.isEmpty()) throw runtime_error("Invalid prefix expression: not enough operands.");
            string op1 = s.pop();
            if (s.isEmpty()) throw runtime_error("Invalid prefix expression: not enough operands.");
            string op2 = s.pop();

            string new_expr = "(" + op1 + c + op2 + ")";
            s.push(new_expr);
        } else {
            throw runtime_error("Invalid character in prefix expression.");
        }
    }
    if (s.isEmpty()) throw runtime_error("Empty prefix expression.");
    return s.pop();
}

// evaluate the postfix expression
double evaluatePostfix(const string& postfix, const map<char, double>& values) {
    Stack_LinkedList<double> s;

    for (char c : postfix) {
        if (c==' ') continue;
        if (isOperand(c)) {
            if (values.count(c)) {
                s.push(values.at(c));
            } else {
                if (isdigit(c)) {
                    s.push(c - '0');
                } else {
                    throw runtime_error("Undefined operand: " + string(1, c));
                }
            }
        } else if (isOperator(c)) {
            if (s.isEmpty()) throw runtime_error("Invalid postfix expression: not enough operands.");
            double val2 = s.pop();
            if (s.isEmpty()) throw runtime_error("Invalid postfix expression: not enough operands.");
            double val1 = s.pop();
            s.push(applyOp(val1, val2, c));
        } else {
            throw runtime_error("Invalid character in postfix expression.");
        }
    }
    if (s.isEmpty()) throw runtime_error("Empty postfix expression.");
    if (s.getSize() != 1) throw runtime_error("Invalid postfix expression: too many operands.");
    return s.pop();
}

// evaluate the prefix expression
double evaluatePrefix(const string& prefix, const map<char, double>& values) {
    Stack_LinkedList<double> s;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (c==' ') continue;
        if (isOperand(c)) {
            if (values.count(c)) {
                s.push(values.at(c));
            } else {
                if (isdigit(c)) {
                    s.push(c - '0');
                } else {
                    throw runtime_error("Undefined operand: " + string(1, c));
                }
            }
        } else if (isOperator(c)) {
            if (s.isEmpty()) throw runtime_error("Invalid prefix expression: not enough operands.");
            double val1 = s.pop();
            if (s.isEmpty()) throw runtime_error("Invalid prefix expression: not enough operands.");
            double val2 = s.pop();
            s.push(applyOp(val1, val2, c));
        } else {
            throw runtime_error("Invalid character in prefix expression.");
        }
    }
    if (s.isEmpty()) throw runtime_error("Empty prefix expression.");
    if (s.getSize() != 1) throw runtime_error("Invalid prefix expression: too many operands.");
    return s.pop();
}

// evaluate the infnix expression
double evaluateInfix(const string& infix, const map<char, double>& values) {
    Stack_LinkedList<double> operands;
    Stack_LinkedList<char> operators;

    for (size_t i = 0; i < infix.length(); ++i) {
        char c = infix[i];

        if (c == ' ') continue;

        if (isOperand(c)) {
            if (values.count(c)) {
                operands.push(values.at(c));
            } else if (isdigit(c)) {
                operands.push(c - '0');
            } else {
                throw runtime_error("Undefined operand: " + string(1, c));
            }
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.isEmpty() && operators.peek() != '(') {
                if (operands.getSize() < 2) throw runtime_error("Invalid infix expression: not enough operands for operator.");
                double val2 = operands.pop();
                double val1 = operands.pop();
                char op = operators.pop();
                operands.push(applyOp(val1, val2, op));
            }
            if (!operators.isEmpty() && operators.peek() == '(') {
                operators.pop();
            } else {
                throw runtime_error("Mismatched parentheses in infix expression.");
            }
        } else if (isOperator(c)) {
            while (!operators.isEmpty() && getPrecedence(operators.peek()) >= getPrecedence(c)) {
                if (operands.getSize() < 2) throw runtime_error("Invalid infix expression: not enough operands for operator.");
                double val2 = operands.pop();
                double val1 = operands.pop();
                char op = operators.pop();
                operands.push(applyOp(val1, val2, op));
            }
            operators.push(c);
        } else {
            throw runtime_error("Invalid character in infix expression.");
        }
    }

    while (!operators.isEmpty()) {
        if (operators.peek() == '(') {
            throw runtime_error("Mismatched parentheses in infix expression.");
        }
        if (operands.getSize() < 2) throw runtime_error("Invalid infix expression: not enough operands for operator.");
        double val2 = operands.pop();
        double val1 = operands.pop();
        char op = operators.pop();
        operands.push(applyOp(val1, val2, op));
    }
    if (operands.isEmpty()) throw runtime_error("Empty infix expression.");
    if (operands.getSize() != 1) throw runtime_error("Invalid infix expression: too many operands.");
    return operands.pop();
}

int main() {

    pl("--- Expression Conversion and Evaluation ---");

    pl("\n--- Infix to Postfix Conversion ---");
    string infix1 = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix1 = infixToPostfix(infix1);
    pl("Infix: " + infix1);
    pl("Postfix: " + postfix1);

    string infix3 = "(A + (B * C- D) ^ E) / (F * (G + H))";
    string postfix3 = infixToPostfix(infix3);
    pl("\nInfix: " + infix3);
    pl("Postfix: " + postfix3);

    pl("\n--- Prefix to Infix Conversion ---");
    string prefix2 = "*-A/BC-/AKL";
    string infix2 = prefixToInfix(prefix2);
    pl("Prefix: " + prefix2);
    pl("Infix: " + infix2);

    pl("\n--- Evaluation of Arithmetic Expressions ---");

    map<char, double> sampleValues = {
        {'A', 2}, {'B', 3}, {'C', 10}, {'D', 8}, {'E', 4},
        {'F', 5}, {'G', 2}, {'H', 2}, {'I', 2}, {'J', 1}
    };

    string infixEval = "((A ^ B) * (C - D / E) + F) / (G * (H ^ I - J))";
    try {
        double resultInfix = evaluateInfix(infixEval, sampleValues);
        pl("\nInfix Expression: " + infixEval);
        pl("Evaluated Result (Infix): " + to_string(resultInfix));
    } catch (const exception& e) {
        cerr << "Error evaluating Infix: " << e.what() << endl;
    }

    string prefixEval = "/ + * ^ A B - C / D E F * G - ^ H I J";
    try {
        double resultPrefix = evaluatePrefix(prefixEval, sampleValues);
        pl("\nPrefix Expression: " + prefixEval);
        pl("Evaluated Result (Prefix): " + to_string(resultPrefix));
    } catch (const exception& e) {
        cerr << "Error evaluating Prefix: " << e.what() << endl;
    }

    string postfixEval = "A B ^ C D E / - * F + G H I ^ J - * /";
    try {
        double resultPostfix = evaluatePostfix(postfixEval, sampleValues);
        pl("\nPostfix Expression: " + postfixEval);
        pl("Evaluated Result (Postfix): " + to_string(resultPostfix));
    } catch (const exception& e) {
        cerr << "Error evaluating Postfix: " << e.what() << endl;
    }

    return 0;
}