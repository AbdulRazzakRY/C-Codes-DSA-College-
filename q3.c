#include<stdio.h>
int mat1(int i,int j)
{
    int arr1[i][j];
    for(int m=0; m<i; m++){
        for(int n=0; n<j; n++){
            scanf("%d",arr1[i][j]);
        }
    }
    for(int m=0; m<i; m++){
        for(int n=0; n<j; n++){
            printf("%d\t",*((arr1+i)+j));
        }
        printf("\n");
    }

}
int mat2(int i,int j)
{
    int arr2[i][j];
    for(int m=0; m<i; m++){
        for(int n=0; n<j; n++){
            scanf("%d",arr2[i][j]);
        }
    }
    for(int m=0; m<i; m++){
        for(int n=0; n<j; n++){
            printf("%d\t",arr2[i][j]);
        }
        printf("\n");
    }

}
int main(){
    int i,j;
    int arr1[i][j],arr2[i][j];
    printf("Enter no. of rows i and no. columns j for 1st matrix:\n");
    scanf("%d",&i);
    scanf("%d",&j);
    printf("Enter the 1st mtrix:\n");
    mat1(i,j);
    printf("Enter no. of rows i and no. columns j for 2nd matrix:\n");
    scanf("%d",&i);
    scanf("%d",&j);
    printf("Enter the 2nd mtrix:\n");
    mat2(i,j);
}