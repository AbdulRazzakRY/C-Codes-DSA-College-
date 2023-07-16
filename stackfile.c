// #include<stdio.h>
// #include<stdlib.h>
// struct stack
// {
//     int data[15];
//     int top;

// };
// void display(int a[50], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d\t", a[i]);
//     }
// }



//     display(data,n);
//     int ch;
//     s->top=-1;
//     while(1){
//         printf("\nEnter operation of stack\n");
//         printf("\n1-push\n");
//         printf("2-pop\n");
//         printf("3-peek\n");
//         scanf("%d",&ch);

//         switch(ch)
//         {
//             case 1:push(s);
//             break;
//             case 2:printf("Poped element is %d\n",pop(s));
//             break;
//             case 3:printf("Peek element is %d\n",peek(s));
//             break;
//         }
//     }

// }

// void push(struct stack *s)
// {
//     if(s->top<4){
//     s->top++;
//     printf("Enter the element to be inserted\n");
//     scanf("%d",&s->data[s->top]);
//     }
//     else{
//         printf("\n stack Overflow");
//     }
// }

// int pop(struct stack *s)
// {
//     if(s->top==-1){
//         printf("stack Underflow");
//     }
//         else{
//             int temp;
//             temp=s->data[s->top];
//             s->top--;
//             return temp;
//     }
// }

// int peek(struct stack *s)
// {
//     return(s->data[s->top]);
// }
// int isEmpty(struct stack *ptr)
// {
//     if(ptr->top==-1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// int isFull(struct stack *ptr)
// {
//     if(ptr->top==NULL){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
