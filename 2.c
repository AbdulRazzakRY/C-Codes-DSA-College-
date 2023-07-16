// // // struct node
// // // {
// // //     struct node *next;
// // //     struct node *prew;
// // //     int data;
// // // };

// // // struct node *dlt_all_less_than_val(struct node *head, int value)
// // // {
// // //     struct node *p = head;                                            // p points head
// // //     struct node *q = head->next;                                      // q points head successive element
// // //     while (q->data != value && q->next != head) // Loop to cheack value value present or not & q points head
// // //     {
// // //         q = q->next;
// // //         p = p->next; // Increment p & q
// // //     }
// // //     if (q->data <= value) // If data is less than or equal to value enters
// // //     {
// // //         p->next = q->next;
// // //         q->next->prew = p;
// // //         free(q);               // Delet the value and free the node
// // //         dltval(head, q->data); // Reapets till all the values less than present value are deleted
// // //     }
// // //     else
// // //     {
// // //         printf("%d value and values less than %d are deleted\n"); // Executes if all the values are greater or not equal to inserted value
// // //     }
// // //     return head; // Returns head
// // // }

// // // C program for different tree traversals
// // #include <stdio.h>
// // #include <stdlib.h>

// // /* A binary tree node has data, pointer to left child
// // and a pointer to right child */
// // struct node
// // {
// //     int data;
// //     struct node *left;
// //     struct node *right;
// // };

// // /* Helper function that allocates a new node with the
// // given data and NULL left and right pointers. */
// // struct node *newNode(int data)
// // {
// //     struct node *node = (struct node *)malloc(sizeof(struct node));
// //     node->data = data;
// //     node->left = NULL;
// //     node->right = NULL;

// //     return (node);  // creating a new node
// // }

// // void printInorder(struct node *node)
// // {
// //     if (node == NULL){
// //         return;
// //     }
// //     printInorder(node->left);  /* first recur on left child */
// //     printf("%d ", node->data); /* then print the data of node */
// //     printInorder(node->right); /* now recur on right child */
// // }

// // /* Driver code*/
// // int main()
// // {
// //     struct node *root = newNode(1);
// //     root->left = newNode(2);
// //     root->right = newNode(3);
// //     root->left->left = newNode(4);
// //     root->left->right = newNode(5);

// //     // Function call
// //     printf("\nInorder traversal of binary tree is \n");
// //     printInorder(root);

// //     getchar();
// //     return 0;
// // }

// #include <stdio.h>
// int G[50][50], x[50]; // G:adjacency matrix,x:colors
// void next_color(int k)
// {
//     int i, j;
//     x[k] = 1; // coloring vertex with color1
//     for (i = 0; i < k; i++)
//     {                                     // checking all k-1 vertices-backtracking
//         if (G[i][k] != 0 && x[k] == x[i]) // if connected and has same color
//             x[k] = x[i] + 1;              // assign higher color than x[i]
//     }
// }

// int main()
// {
//     int n, e, i, j, k, l;
//     printf("Enter no. of vertices : ");
//     scanf("%d", &n); // total vertices
//     printf("Enter no. of edges : ");
//     scanf("%d", &e); // total edges

//     for (i = 0; i < n; i++)
//         for (j = 0; j < n; j++)
//             G[i][j] = 0; // assign 0 to all index of adjacency matrix

//     printf("Enter indexes where value is 1-->\n");
//     for (i = 0; i < e; i++)
//     {
//         scanf("%d %d", &k, &l);
//         G[k][l] = 1;
//         G[l][k] = 1;
//     }

//     for (i = 0; i < n; i++)
//         next_color(i); // coloring each vertex

//     printf("Colors of vertices -->\n");
//     for (i = 0; i < n; i++) // displaying color of each vertex
//         printf("Vertex[%d] : %d\n", i + 1, x[i]);

//     return 0;
// }
#include <stdio.h>

#include <conio.h>

static int m, n;

static int c = 0;

static int count = 0;

int g[50][50];

int x[50];

void nextValue(int k);

void GraphColoring(int k);

void main()

{

    int i, j;

    int temp;

     printf("\nEnter the number of nodes: ");

    scanf("%d", &n);

    /*

     printf("\nIf edge exists then enter 1 else enter 0 \n");

     for(i=1; i<=n; i++)

     {

      x[i]=0;

      for(j=1; j<=n; j++)

      {

       if(i==j)

        g[i][j]=0;

       else

       {

        printf("%d -> %d: " , i, j);

        scanf("%d", &temp);

        g[i][j]=g[j][i]=temp;

       }

      }

     }

    */

    printf("\nEnter Adjacency Matrix:\n");

    for (i = 1; i <= n; i++)

    {

        for (j = 1; j <= n; j++)

        {

            scanf("%d", &g[i][j]);
        }
    }

    printf("\nPossible Solutions are\n");

    for (m = 1; m <= n; m++)

    {

        if (c == 1)

        {

            break;
        }

        GraphColoring(1);
    }

    printf("\nThe chromatic number is %d", m - 1);

    // in for loop, m gets incremented first and then the condition is checked

    // so it is m minus 1

    printf("\nThe total number of solutions is %d", count);

    getch();

    void GraphColoring(int k){
    int i;
    while (1){
         nextValue(k);
        if (x[k] == 0){
            return;
        }
        if (k == n){
             c = 1;
            for (i = 1; i <= n; i++){
                 printf("%d ", x[i]);
            }
            count++;
            printf("\n");
        }
        else
            GraphColoring(k + 1);
    }
}

void nextValue(int k)
{
    int j;
    while (1){
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0){
            return;
        }
        for (j = 1; j <= n; j++){
            if (g[k][j] == 1 && x[k] == x[j])
                break;
        }
        if (j == (n + 1)){
            return;
        }
    }
}
}

