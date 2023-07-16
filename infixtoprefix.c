#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for expression tree node
struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new expression tree node
struct TreeNode* createNode(char value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return 1;
    }
    return 0;
}

// Function to perform preorder traversal and concatenate the operators and operands
void preorderTraversal(struct TreeNode* root, char* prefix) {
    if (root == NULL) {
        return;
    }

    // Process the current node
    strncat(prefix, &(root->data), 1);

    // Traverse the left subtree
    preorderTraversal(root->left, prefix);

    // Traverse the right subtree
    preorderTraversal(root->right, prefix);
}

// Function to convert infix expression to prefix expression
void infixToPrefix(char* infix, char* prefix) {
    int infixLen = strlen(infix);

    // Create an empty stack for the expression tree
    struct TreeNode** stack = (struct TreeNode**)malloc(infixLen * sizeof(struct TreeNode*));
    int top = -1;

    for (int i = infixLen - 1; i >= 0; i--) {
        char ch = infix[i];

        // If the current character is an operand, push it onto the stack
        if (!isOperator(ch)) {
            stack[++top] = createNode(ch);
        }
        else {
            // If the current character is an operator, pop two operands from the stack
            struct TreeNode* operand1 = stack[top--];
            struct TreeNode* operand2 = stack[top--];

            // Create a new tree node with the operator as the root and the operands as its children
            struct TreeNode* operatorNode = createNode(ch);
            operatorNode->left = operand1;
            operatorNode->right = operand2;

            // Push the operator node onto the stack
            stack[++top] = operatorNode;
        }
    }

    // Perform preorder traversal on the root of the expression tree to get the prefix expression
    preorderTraversal(stack[top], prefix);

    // Free the memory allocated for the stack
    free(stack);
}

int main() {
    char infix[50];
    char prefix[50];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    // Convert infix to prefix
    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
