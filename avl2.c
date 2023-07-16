#include <stdio.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
  int balance;
};

struct node *new_node(int data) {
  struct node *node = malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->balance = 0;
  return node;
}

int get_balance(struct node *node) {
  if (node == NULL) {
    return 0;
  }
  return node->balance;
}

void left_rotate(struct node *node) {
  struct node *right_child = node->right;
  struct node *right_child_left = right_child->left;

  // Rotate the tree
  right_child->left = node;
  node->right = right_child_left;

  // Update the balance factors
  node->balance = get_balance(node->left) - get_balance(node->right);
  right_child->balance = get_balance(right_child->left) + get_balance(right_child->right);
}

void right_rotate(struct node *node) {
  struct node *left_child = node->left;
  struct node *left_child_right = left_child->right;

  // Rotate the tree
  left_child->right = node;
  node->left = left_child_right;

  // Update the balance factors
  node->balance = get_balance(node->left) - get_balance(node->right);
  left_child->balance = get_balance(left_child->left) + get_balance(left_child->right);
}

void insert(struct node **root, int data) {
  if (*root == NULL) {
    *root = new_node(data);
  } else {
    if (data < (*root)->data) {
      insert(&(*root)->left, data);
    } else if (data > (*root)->data) {
      insert(&(*root)->right, data);
    }

    // Update the balance factor of the current node
    (*root)->balance = get_balance(*root);

    // If the balance factor is not 0, then perform rotations as needed to restore the balance of the tree
    if ((*root)->balance == -2) {
      if (get_balance((*root)->left) == 1) {
        left_rotate((*root)->left);
      }
      right_rotate(*root);
    } else if ((*root)->balance == 2) {
      if (get_balance((*root)->right) == -1) {
        right_rotate((*root)->right);
      }
      left_rotate(*root);
    }
  }
}

void delete(struct node **root, int data) {
  if (*root == NULL) {
    return;
  }

  if (data < (*root)->data) {
    delete(&(*root)->left, data);
  } else if (data > (*root)->data) {
    delete(&(*root)->right, data);
  } else {
    // If the node has only one child, then simply remove the node
    if ((*root)->left == NULL) {
      struct node *temp = *root;
      *root = (*root)->right;
      free(temp);
    } else if ((*root)->right == NULL) {
      struct node *temp = *root;
    }
  }
}
int main()
{
  struct node *root=NULL;
  Printf("Enter the Tree:\n"); 
  int m;
  insert(root,7);
  
  return 0;
}