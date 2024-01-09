#include <iostream>
#include <string>

using namespace std;

// Node class for expression tree
class Node {
public:
    string value;
    Node* left;
    Node* right;

    Node(string val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to build an expression tree from an infix expression
Node* buildExpressionTree(string infix) {
    Node* root = nullptr;
    Node* temp = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
    stack<Node*> stack;

    for (int i = 0; i < infix.length(); i++) {
        if (isOperator(infix[i])) {
            right = stack.top();
            stack.pop();
            left = stack.top();
            stack.pop();

            temp = new Node(string(1, infix[i]));
            temp->left = left;
            temp->right = right;

            stack.push(temp);
        }
        else {
            temp = new Node(string(1, infix[i]));
            stack.push(temp);
        }
    }

    root = stack.top();
    stack.pop();

    return root;
}


// Function to evaluate an expression tree
int evaluateExpressionTree(Node* root) {
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return stoi(root->value);

    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    if (root->value == "+")
        return leftValue + rightValue;
    else if (root->value == "-")
        return leftValue - rightValue;
    else if (root->value == "*")
        return leftValue * rightValue;
    else if (root->value == "/")
        return leftValue / rightValue;

    return 0;
}

// Function to build an expression tree from a postfix expression
Node* buildExpressionTree(string postfix) {
    Node* root = nullptr;
    Node* temp = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;

    for (int i = 0; i < postfix.length(); i++) {
        if (!isOperator(postfix[i])) {
            temp = new Node(string(1, postfix[i]));
            root = temp;
        }
        else {
            temp = new Node(string(1, postfix[i]));
            right = root;
            left = new Node(string(1, postfix[i - 1]));
            temp->left = left;
            temp->right = right;
            root = temp;
        }
    }

    return root;
}

// Function to evaluate an expression tree
int evaluateExpressionTree(Node* root) {
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return stoi(root->value);

    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    if (root->value == "+")
        return leftValue + rightValue;
    else if (root->value == "-")
        return leftValue - rightValue;
    else if (root->value == "*")
        return leftValue * rightValue;
    else if (root->value == "/")
        return leftValue / rightValue;

    return 0;
}
// 

int main() {
    string postfixExpression;
    cout << "Enter a postfix expression: ";
    cin >> postfixExpression;

    Node* root = buildExpressionTree(postfixExpression);

    int result = evaluateExpressionTree(root);
    cout << "Result: " << result << endl;

    return 0;
}
