// C program to demonstrate insert
// operation in binary
// search tree.

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

struct node {
    int key;
    struct node *left, *right;
};

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
        fprintf(myfile,"%c\n",root->key);
        inorder(root->right,myfile);
    }
}

// A utility function to insert
// a new node with given key in BST
struct node* insert(struct node* node, int key)
{
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key >= node->key)
        node->right = insert(node->right, key);

    // Return the (unchanged) node pointer
    return node;
}
void preorder (struct node *root,FILE *myfile)
{
  if (root != NULL)
    {
      printf ("%c ", root->key);
      fprintf(myfile,"%c\n",root->key);
      preorder (root->left,myfile);
      preorder (root->right,myfile);
    }
}
void postorder(struct node *root,FILE *myfile)
{
    if(root!=NULL){
      postorder (root->left,myfile);
      postorder (root->right,myfile);
      printf ("%c ", root->key);
      fprintf(myfile,"%c\n",root->key);
    }

}
// Driver Code
int main()
{
    FILE *myfile;
    myfile= fopen("randomnochar.txt","w");
    int n;
    printf("Enter the no.\n");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        fprintf(myfile,"%c\n",rand()%(91-65)+65);
    }
    fclose(myfile);
    myfile= fopen("randomnochar.txt","r");
    char arr1[20];
    
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
        root=insert(root,arr1[i]);
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
    return 0;
}