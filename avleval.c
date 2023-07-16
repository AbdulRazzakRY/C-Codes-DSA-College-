#include <stdio.h>
#include <stdlib.h>
#include<time.h>

struct node {
  int key;
  struct node *left;
  struct node *right;
  int balance;
};
struct node *new_node(int key) {
  struct node *node = malloc(sizeof(struct node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->balance = 0;
  return node;
};

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

// A utility function to create a new BST node
struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
            temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node* root,FILE *myfile)
{
    if (root != NULL) {
        inorder(root->left,myfile);
        printf("%d ", root->key);
        fprintf(myfile,"%d\n",root->key);
        inorder(root->right,myfile);
    }
}

// A utility function to insert
// a new node with given key in BST
struct node* insert1(struct node* node, int key)
{
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert1(node->left, key);
    else if (key >= node->key)
        node->right = insert1(node->right, key);

    // Return the (unchanged) node pointer
    return node;
}

struct node* insert2(struct node *root, int key) {
  if (root == NULL) {
    root = new_node(key);
  } else {
    if (key < (root)->key) {
      insert2((root)->left, key);
    } else if (key > (root)->key) {
      insert2((root)->right, key);
    }

    // Update the balance factor of the current node
    (root)->balance = get_balance(root);

    // If the balance factor is not 0, then perform rotations as needed to restore the balance of the tree
    if ((root)->balance == -2) {
      if (get_balance((root)->left) == 1) {
        left_rotate((root)->left);
      }
      right_rotate(root);
    } else if ((root)->balance == 2) {
      if (get_balance((root)->right) == -1) {
        right_rotate((root)->right);
      }
      left_rotate(root);
    }
  }
}

void preorder (struct node *root,FILE *myfile)
{
  if (root != NULL)
    {
      printf ("%d ", root->key);
      fprintf(myfile,"%d\n",root->key);
      preorder (root->left,myfile);
      preorder (root->right,myfile);
    }
}
void postorder(struct node *root,FILE *myfile)
{
    if(root!=NULL){
      postorder (root->left,myfile);
      postorder (root->right,myfile);
      printf ("%d ", root->key);
      fprintf(myfile,"%d\n",root->key);
    }

}
// Driver Code
int main()
{
    FILE *myfile;
    myfile= fopen("randomnofiles.txt","w");
    int n=20;
    for(int i=0; i<n; i++){
        fprintf(myfile,"%d\n",rand()%50);
    }
    fclose(myfile);
    myfile= fopen("randomnofiles.txt","r");
    int arr1[20];
    
    for (int i = 0; i < 20; i++)
    {
        fscanf(myfile,"%d",&arr1[i]);
    }
    for (int i = 0; i < 20; i++)
    {
        fprintf(myfile,"%d",arr1[i]);
    }
    struct node* root = NULL;
    for (int i = 0; i < 20; i++)
    {
        root=insert1(root,arr1[i]);
    }

    float start=0,stop=0;
    printf("Inorder:-");
    myfile=fopen("inorder.txt","w");
    start=clock();
    inorder(root,myfile);
    printf("\n");
    stop=clock();
    float time1=(float)(stop-start);
    fprintf(myfile,"Time taken for inorder is %f sec\n",time1);
    fclose(myfile);


    printf("preorder:-");
    myfile=fopen("preorder.txt","w");
    start=clock();
    preorder(root,myfile);
    printf("\n");
    stop=clock();
    float time2=(float)(stop-start);
    fprintf(myfile,"Time taken for inorder is %f sec\n",time2);
    fclose(myfile);


    printf("postorder:-");
    myfile=fopen("postorder.txt","w");
    start=clock();
    postorder(root,myfile);
    stop=clock();
    float time3=(float)(stop-start);
    fprintf(myfile,"Time taken for inorder is %f sec\n",time3);
    fclose(myfile);

    //After Balancing
     root = NULL;
    for (int i = 0; i < 20; i++)
    {
        root=insert2(root,arr1[i]);
    }

    start=0,stop=0;
    printf("\nInorder for AVL for balancing tree:-");
    myfile=fopen("inorder.txt","a");
    start=clock();
    inorder(root,myfile);
    printf("\n");
    stop=clock();
    time1=(float)(stop-start);
    fprintf(myfile,"Time taken for inorder is %f sec\n",time1);
    fclose(myfile);


    printf("preorder for AVL for balancing tree:-");
    myfile=fopen("preorder.txt","a");
    start=clock();
    preorder(root,myfile);
    printf("\n");
    stop=clock();
    time2=(float)(stop-start);
    fprintf(myfile,"Time taken for inorder is %f sec\n",time2);
    fclose(myfile);


    printf("postorder for AVL for balancing tree:-");
    myfile=fopen("postorder.txt","a");
    start=clock();
    postorder(root,myfile);
    stop=clock();
    time3=(float)(stop-start);
    fprintf(myfile,"Time taken for inorder is %f sec\n",time3);
    fclose(myfile);
    return 0;
}