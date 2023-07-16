#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[3][4],b[4][2],sum=0,result[3][2];
    printf("Enter the 1st matrix:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            // printf("Enter the %d %d element of first matrix\n",i,j);
            scanf("%d",&a[i][j]);
        }
    }
     printf("Enter the 2nd matrix:\n");
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            // printf("Enter the %d %d element of first matrix\n",i,j);
            scanf("%d",&b[i][j]);
        }
    }
    // printf("Enter the elements of the mtrix:\n");
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         reuslt=a[i][4]*b[4][j];
    //     }
    // }
     printf("The resultant matrix:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<4; k++){
                sum += a[i][k]*b[k][j];
            }
            result[i][j]=sum;
            sum=0;
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            printf("%d\t",result[i][j]);
        }
        printf("\n");
    }
    return 0;
}