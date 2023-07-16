#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        printf("Stack Overflow! Cannot push %d to the stack\n",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int pop(struct stack *ptr){
    if(ptr->top==-1){
        printf("Stack Underflow\n");
        return -4;
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek (struct stack *sp,int i){
    int arrIndex=sp->top-i+1;
    if(arrIndex<0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return sp->arr[arrIndex];
    }
}

int main(){
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=15;
    sp->top=-1;

    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    FILE *myfile;
    myfile= fopen("randomnofiles.txt","w");
    int n;
    printf("Enter the no.\n");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        fprintf(myfile,"%d\n",rand()%15);
    }
    fclose(myfile);
    myfile= fopen("randomnofiles.txt","r");
    int arr1[15];
    
    for (int i = 0; i < 15; i++)
    {
        fscanf(myfile,"%d",&arr1[i]);
    }
     s->top=-1;
     int ch;
    while(1){
        printf("\nEnter operation of stack\n");
        printf("\n1-push\n");
        printf("2-pop\n");
        printf("3-peek\n");
        printf("4-exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:push(s);
            break;
            case 2:printf("Poped element is %d\n",pop(s));
            break;
            case 3:printf("Peek element is %d\n",peek(s));
            break;
            case 4:printf("exit\n");
            break;
            default : printf("Invalid");
        }
    }
    sp->arr=(int *)malloc(sp->size * sizeof(int));
    printf("stack has been created successfully\n");

    printf("Top Element is %d\n",sp->arr[sp->top]);
    printf("The Bottom Element is %d\n",sp->arr[0]);
    return 0;
}